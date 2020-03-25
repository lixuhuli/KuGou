#include "mainwnd.h"
#include <QGridLayout>
#include <QLabel>
#include <QSize>
#include <QWidgetAction>

QMutex mainWnd::mutex_;
QAtomicPointer<mainWnd> mainWnd::main_wnd_ = nullptr;

mainWnd::mainWnd(QWidget *parent)
    : baseWindow(parent)
    , top_widget_(this)
    , mid_widget_(this)
    , bottom_widget_(this)
    , store_vol_value_(80)
    , tray_vol_btn_(nullptr)
    , tray_vol_widget_(nullptr) 
    , tray_vol_slider_(nullptr)
    , close_opacity_animation_(this, "windowOpacity")
    , close_move_animation_(this, "geometry") {

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
    InitAnmation();
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
    tray_menu_.setFixedWidth(200);
    tray_menu_.setContentsMargins(4, 5, 4, 10);

    InitPlayItem();

    tray_menu_.addSeparator();

    InitVolItem();

    tray_menu_.addSeparator();

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

    connect(act_exit, SIGNAL(triggered(bool)), this, SLOT(slot_quitApp()));

    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    system_tray_.setContextMenu(&tray_menu_);
    system_tray_.setIcon(QIcon(":/image/main/trayIcon.png"));
    system_tray_.setToolTip(QString::fromLocal8Bit("酷狗音乐"));
    system_tray_.show();
}

void mainWnd::InitVolItem() {
    auto* act_vol = new QWidgetAction(&tray_menu_);
    if (!act_vol) return;

    ////////////////////////////////////////////////////////////////////////////////////
    tray_vol_widget_ = new baseWidget(&tray_menu_);

    tray_vol_widget_->setFixedSize(190, 30);

    QHBoxLayout *hlyout = new QHBoxLayout;
    hlyout->setAlignment(Qt::AlignLeft);

    tray_vol_btn_ = new QRadioButton;
    tray_vol_btn_->setFixedSize(16, 16);
    tray_vol_btn_->setCursor(QCursor(Qt::PointingHandCursor));
    tray_vol_btn_->setStyleSheet("QRadioButton::indicator::unchecked{border-image:url(:/image/trayMenu/menu_vol (1).png) 0 16 0 48;}"
        "QRadioButton::indicator::unchecked:hover{border-image:url(:/image/trayMenu/menu_vol (2).png) 0 16 0 48;}"
        "QRadioButton::indicator::checked{border-image:url(:/image/trayMenu/menu_vol (1).png) 0 0 0 64;}"
        "QRadioButton::indicator::checked:hover{border-image:url(:/image/trayMenu/menu_vol (2).png) 0 0 0 64;}"
        "QRadioButton::indicator{width:16px;height:16px;}");

    tray_vol_slider_ = new Slider(Qt::Horizontal, tray_vol_widget_); 
    tray_vol_slider_->setFixedSize(140, 20);
    tray_vol_slider_->setStyleSheet("QSlider::groove:horizontal{border-radius:2px;height:2px;}"
        "QSlider::sub-page:horizontal{background:rgb(104,104,104);}"
        "QSlider::add-page:horizontal{background:rgb(209,209,209);}"
        "QSlider::handle:horizontal{background:rgb(104,104,104);width:8px;border-radius:4px;margin:-3px 0px -3px 0px;}");

    hlyout->addWidget(tray_vol_btn_);
    hlyout->addWidget(tray_vol_slider_);
    hlyout->addSpacerItem(new QSpacerItem(10, 10, QSizePolicy::Expanding, QSizePolicy::Fixed));
    hlyout->setContentsMargins(12, 0, 0, 0);
    tray_vol_widget_->setLayout(hlyout);


    /////////////////////////////////////////////////////////////////////////////////////
    act_vol->setDefaultWidget(tray_vol_widget_);
    tray_menu_.addAction(act_vol);
    tray_vol_widget_->raise();
}

void mainWnd::InitPlayItem() {
    auto act_play = new QWidgetAction(&tray_menu_);
    if (!act_play) return;

    ////////////////////////////////////////////////////////////////////////////////////
    auto tray_play_widget = new baseWidget(&tray_menu_);

    tray_play_widget->setFixedSize(190, 65);

    QVBoxLayout *vlyout = new QVBoxLayout;

    QHBoxLayout *hlyout = new QHBoxLayout;

    QPushButton* backward_button = new QPushButton;
    backward_button->setFixedSize(32, 32);
    backward_button->setFlat(true);
    backward_button->setCursor(QCursor(Qt::PointingHandCursor));
    backward_button->setStyleSheet("QPushButton{border-image:url(:/image/trayMenu/menu_previous (1).png);}"
        "QPushButton::hover{border-image:url(:/image/trayMenu/menu_previous (2).png);}"
        "QPushButton::pressed{border-image:url(:/image/trayMenu/menu_previous (3).png);}");

    QPushButton* play_button = new QPushButton;
    play_button->setFixedSize(32, 32);
    play_button->setFlat(true);
    play_button->setCursor(QCursor(Qt::PointingHandCursor));
    play_button->setStyleSheet("QPushButton{border-image:url(:/image/trayMenu/menu_play (1).png);}"
        "QPushButton::hover{border-image:url(:/image/trayMenu/menu_play (2).png);}"
        "QPushButton::pressed{border-image:url(:/image/trayMenu/menu_play (3).png);}");

    QPushButton* forward_button = new QPushButton;
    forward_button->setFixedSize(32, 32);
    forward_button->setFlat(true);
    forward_button->setCursor(QCursor(Qt::PointingHandCursor));
    forward_button->setStyleSheet("QPushButton{border-image:url(:/image/trayMenu/menu_next (1).png);}"
        "QPushButton::hover{border-image:url(:/image/trayMenu/menu_next (2).png);}"
        "QPushButton::pressed{border-image:url(:/image/trayMenu/menu_next (3).png);}");

    hlyout->addWidget(backward_button);
    hlyout->addWidget(play_button);
    hlyout->addWidget(forward_button);
    hlyout->setSpacing(0);
    hlyout->setContentsMargins(0, 0, 0, 0);


    QLabel* lbl_music_name = new QLabel(QString::fromLocal8Bit("极视听 传播好音乐"));
    lbl_music_name->setStyleSheet("color: rgb(134,134,134);");
    lbl_music_name->setFixedHeight(20);
    lbl_music_name->setEnabled(false);

    vlyout->addLayout(hlyout);
    vlyout->addWidget(lbl_music_name, 0, Qt::AlignHCenter);
    vlyout->setSpacing(2);
    vlyout->setContentsMargins(0, 2, 0, 0);
    tray_play_widget->setLayout(vlyout);

    ////////////////////////////////////////////////////////////////////////////////////
    act_play->setDefaultWidget(tray_play_widget);
    tray_menu_.addAction(act_play);
}

void mainWnd::InitAnmation() {
    close_move_animation_.setDuration(1300);
    close_move_animation_.setEasingCurve(QEasingCurve::OutQuad);

    close_opacity_animation_.setDuration(1300);
    close_opacity_animation_.setEasingCurve(QEasingCurve::OutQuad);
    connect(&close_opacity_animation_, SIGNAL(finished()), this, SLOT(close()));
}

void mainWnd::InitConnect() {
    connect(&system_tray_, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(systemTrayActived(QSystemTrayIcon::ActivationReason)));

    connect(tray_vol_btn_, SIGNAL(clicked(bool)), this, SLOT(OnTrayVolClick(bool)));
    connect(tray_vol_slider_, SIGNAL(valueChanged(int)), this, SLOT(updateBtnStatus(int)));
    connect(tray_vol_slider_, SIGNAL(valueChanged(int)), &bottom_widget_, SLOT(setVoldSliderValue(int)));

    tray_vol_slider_->setValue(store_vol_value_);
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

void mainWnd::slot_quitApp() {
    system_tray_.hide();

    if (!isVisible()) close();

    setMinimumSize(0, 0);
    auto rc = geometry();
    close_move_animation_.setStartValue(rc);
    close_move_animation_.setEndValue(QRectF(rc.x() / 8, rc.y() / 8, rc.width() / 8, rc.height() / 8));
    close_move_animation_.start();

    close_opacity_animation_.setStartValue(1.0);
    close_opacity_animation_.setEndValue(0.0);
    close_opacity_animation_.start();
}

void mainWnd::updateBtnStatus(int volume) {
    if (volume <= 0) {
        tray_vol_btn_->setChecked(true);
    }
    else if (volume <= 30) {
        tray_vol_btn_->setChecked(false);
        tray_vol_btn_->setStyleSheet("QRadioButton::indicator::unchecked{border-image:url(:/image/trayMenu/menu_vol (1).png) 0 48 0 16;}"
            "QRadioButton::indicator::unchecked:hover{border-image:url(:/image/trayMenu/menu_vol (2).png) 0 48 0 16;}"
            "QRadioButton::indicator::checked{border-image:url(:/image/trayMenu/menu_vol (1).png) 0 0 0 64;}"
            "QRadioButton::indicator::checked:hover{border-image:url(:/image/trayMenu/menu_vol (2).png) 0 0 0 64;}"
            "QRadioButton::indicator{width:16px;height:16px;}");
    }
    else {
        tray_vol_btn_->setChecked(false);
        tray_vol_btn_->setStyleSheet("QRadioButton::indicator::unchecked{border-image:url(:/image/trayMenu/menu_vol (1).png) 0 16 0 48;}"
            "QRadioButton::indicator::unchecked:hover{border-image:url(:/image/trayMenu/menu_vol (2).png) 0 16 0 48;}"
            "QRadioButton::indicator::checked{border-image:url(:/image/trayMenu/menu_vol (1).png) 0 0 0 64;}"
            "QRadioButton::indicator::checked:hover{border-image:url(:/image/trayMenu/menu_vol (2).png) 0 0 0 64;}"
            "QRadioButton::indicator{width:16px;height:16px;}");
    }

    if (volume != 0) store_vol_value_ = volume;
}

void mainWnd::setVolSliderStatus(int volume) {
    if (tray_vol_slider_) tray_vol_slider_->setValue(volume);
}

void mainWnd::OnTrayVolClick(bool check) {
    if (!tray_vol_slider_) return;
    tray_vol_slider_->setValue(check ? 0 : store_vol_value_);
}
