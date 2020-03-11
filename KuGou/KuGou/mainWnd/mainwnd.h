#ifndef MAINWND_H
#define MAINWND_H

#include <QDialog>
#include <QMutex>
#include "baseWnd/basewindow.h"
#include "topWidget/topwidgets.h"

class mainWnd : public baseWindow {
    Q_OBJECT

public:
    static mainWnd& getInstance();

public:
    mainWnd(QWidget *parent = 0);
    virtual ~mainWnd();

protected:
    void initLayout();

private:
    static QMutex mutex_;                          // 实例互斥锁。
    static QAtomicPointer<mainWnd> main_wnd_;      // <使用原子指针,默认初始化为0。

    topWidgets top_widget_;

    QWidget mid_widget_;
    QWidget bottom_widget_;
};

#endif // MAINWND_H
