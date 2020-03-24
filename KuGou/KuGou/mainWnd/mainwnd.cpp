#include "mainwnd.h"
#include <QGridLayout>
#include <QLabel>
#include <QSize>

QMutex mainWnd::mutex_;
QAtomicPointer<mainWnd> mainWnd::main_wnd_ = nullptr;

mainWnd::mainWnd(QWidget *parent)
    : baseWindow(parent)
    , top_widget_(this)
    , mid_widget_(this)
    , bottom_widget_(this) {

    // 增加属性  使点击任务栏可以最大化和最小化
    setWindowFlags(windowFlags() | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint);

    setMinimumSize(1008, 698);
    resize(1008, 698);

    main_widget_.setStyleSheet("QLabel{color:white;}" "QWidget{background:transparent;}");
    main_widget_.setSkinPic(":/ID_DEFAULT_SKIN_PIC");

    //top_widget_.setStyleSheet("topWidgets{background:blue;}");

    InitUi();
    InitTrayMenu();
    InitConnect();
}

mainWnd::~mainWnd() {

}

mainWnd* mainWnd::getInstance() {
    if (main_wnd_ == nullptr) {
        QMutexLocker locker(&mutex_); // 加互斥锁。
        if (main_wnd_ == nullptr)
            main_wnd_ = new mainWnd();
    }

    return main_wnd_;
}

void mainWnd::InitUi() {
    QVBoxLayout *vlyout = new QVBoxLayout;
    if (!vlyout) return;

    vlyout->addWidget(&top_widget_);
    vlyout->addWidget(&mid_widget_);
    vlyout->addWidget(&bottom_widget_);
    vlyout->setSpacing(0);
    vlyout->setContentsMargins(0, 0, 0, 0);

    main_widget_.setLayout(vlyout);
}

void mainWnd::InitTrayMenu() {
    tray_menu_.setStyleSheet(QString("QMenu{background-color: white;border: 1px solid rgb(214,214,214);}"
        "QMenu::item{height: 28px;padding: 0px 20px 0px 40px;font-size : 12px;color: rgb(102, 102, 102);font-family: %1;}"
        "QMenu::item:focus{padding: -1;}"
        "QMenu::item:!enabled{color:rgb(150,150,150);}"
        "QMenu::item:selected{color: white;background-color: rgb(22, 154, 243);}"
        "QMenu::icon{position: absolute;left: 12px;}"
        "QMenu::separator{height:1px;background: rgb(209,209,209);margin:4px 0px 4px 0px;}").arg(QString::fromLocal8Bit("微软雅黑")));
    tray_menu_.setFixedHeight(200);
    tray_menu_.setContentsMargins(4, 5, 4, 10);

    auto* act_dest_lyric = new QAction(QIcon(":/image/trayMenu/menu_lrc.png"), QString::fromLocal8Bit("显示桌面歌词"));
    auto* act_lock_lyric = new QAction(QIcon(":/image/trayMenu/menu_lock.png"), QString::fromLocal8Bit("锁定歌词"));
    auto* act_setting = new QAction(QIcon(":/image/trayMenu/menu_setting.png"), QString::fromLocal8Bit("选项设置"));
    auto* act_login = new QAction(QIcon(":/image/trayMenu/menu_log.png"), QString::fromLocal8Bit("登录"));
    auto* act_exit = new QAction(QIcon(":/image/trayMenu/menu_close.png"), QString::fromLocal8Bit("退出"));

    tray_menu_.addAction(act_dest_lyric);
    tray_menu_.addAction(act_lock_lyric);
    tray_menu_.addSeparator();
    tray_menu_.addAction(act_setting);
    tray_menu_.addSeparator();
    tray_menu_.addAction(act_login);
    tray_menu_.addAction(act_exit);



    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    system_tray_.setContextMenu(&tray_menu_);
    system_tray_.setIcon(QIcon(":/image/main/trayIcon.png"));
    system_tray_.setToolTip(QString::fromLocal8Bit("酷狗音乐"));
    system_tray_.show();
}

void mainWnd::InitConnect() {
    connect(&system_tray_, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(systemTrayActived(QSystemTrayIcon::ActivationReason)));
}

void mainWnd::mouseDoubleClickEvent(QMouseEvent *e) {
    if (e->button() == Qt::LeftButton) {
        Q_UNUSED(e)
            if (!isMaximized())
            {
                showMaximized();
                setGeometry(-4, -4, width() + 8, height() + 8);//最大显示
            }
            else
                showNormal();
    }
    
    baseWindow::mouseDoubleClickEvent(e);
}

void mainWnd::closeEvent(QCloseEvent *event) {
    if (system_tray_.isVisible()) {
        hide();
        event->ignore();
    }
    else event->accept();
}

void mainWnd::systemTrayActived(QSystemTrayIcon::ActivationReason reason) {
    switch (reason) {
    case QSystemTrayIcon::DoubleClick:
    case QSystemTrayIcon::Trigger: {
        showNormal();
        activateWindow();
        break;
    }
    default:
        break;
    }
}
