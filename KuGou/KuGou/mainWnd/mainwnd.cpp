#include "mainwnd.h"
#include <QGridLayout>
#include <QLabel>

QMutex mainWnd::mutex_;
QAtomicPointer<mainWnd> mainWnd::main_wnd_ = nullptr;

mainWnd::mainWnd(QWidget *parent)
    : baseWindow(parent) {

    setMinimumSize(1008, 698);

    main_widget_.setStyleSheet("QLabel{color:white;}" "QWidget{background:transparent;}");
    //main_widget_.setStyleSheet(QString::fromLocal8Bit("border-image:url(:/image/skin/Ä¬ÈÏ.jpg);"));
    main_widget_.setSkinPic(QString::fromLocal8Bit(":/image/skin/Ä¬ÈÏ.jpg"));

    initLayout();
}

mainWnd::~mainWnd() {

}

mainWnd& mainWnd::getInstance() {
    if (main_wnd_ == nullptr) {
        QMutexLocker locker(&mutex_); // ¼Ó»¥³âËø¡£
        if (main_wnd_ == nullptr)
            main_wnd_ = new mainWnd();
    }

    return *main_wnd_;
}

void mainWnd::initLayout() {
    QVBoxLayout *vlyout = new QVBoxLayout;
    if (!vlyout) return;

    //vlyout->addWidget(&top_widget_);
    //vlyout->addWidget(&mid_widget_);
    //vlyout->addWidget(&bottom_widget_);
    //vlyout->setSpacing(0);
    //vlyout->setContentsMargins(0, 0, 0, 0);

    main_widget_.setLayout(vlyout);
}

