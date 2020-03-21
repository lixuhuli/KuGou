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

    setMinimumSize(1008, 698);
    resize(1008, 698);

    main_widget_.setStyleSheet("QLabel{color:white;}" "QWidget{background:transparent;}");
    main_widget_.setSkinPic(":/ID_DEFAULT_SKIN_PIC");

    //top_widget_.setStyleSheet("topWidgets{background:blue;}");

    InitUi();
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

void mainWnd::InitConnect() {
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
