#include "mainwnd.h"
#include <QGridLayout>
#include <QLabel>

QMutex mainWnd::mutex_;
QAtomicPointer<mainWnd> mainWnd::main_wnd_ = nullptr;

mainWnd::mainWnd(QWidget *parent)
    : baseWindow(parent) {

    setMinimumSize(1008, 698);

    main_widget_.setStyleSheet("QLabel{color:white;}" "QWidget{background:transparent;}");
    main_widget_.setStyleSheet(QString::fromLocal8Bit("border-image:url(:/image/skin/Ä¬ÈÏ.jpg);"));
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
