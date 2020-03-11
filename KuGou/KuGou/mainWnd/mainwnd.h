#ifndef MAINWND_H
#define MAINWND_H

#include <QDialog>
#include <QMutex>
#include "baseWnd/basewindow.h"

class mainWnd : public baseWindow {
    Q_OBJECT

public:
    static mainWnd& getInstance();

public:
    mainWnd(QWidget *parent = 0);
    virtual ~mainWnd();

private:
    static QMutex mutex_;                          // 实例互斥锁。
    static QAtomicPointer<mainWnd> main_wnd_;    // <使用原子指针,默认初始化为0。
};

#endif // MAINWND_H
