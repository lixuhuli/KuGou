#ifndef MAINWND_H
#define MAINWND_H

#include <QDialog>
#include <QMutex>
#include "baseWnd/basewindow.h"
#include "topWidget/topwidgets.h"
#include "middleWidget/middlewidgets.h"
#include "bottomWidget/bottomwidgets.h"

class mainWnd : public baseWindow {
    friend class baseWidget;
    Q_OBJECT
public:
    static mainWnd* getInstance();

public:
    mainWnd(QWidget *parent = 0);
    virtual ~mainWnd();

public:
    void setCurVol(int);
    baseWidget* middle_widget() { return &mid_widget_; }

protected:
    void InitUi();
    void InitConnect();

protected:
    virtual void mouseDoubleClickEvent(QMouseEvent *) override;

private:
    static QMutex mutex_;                          // 实例互斥锁。
    static QAtomicPointer<mainWnd> main_wnd_;      // <使用原子指针,默认初始化为0。

    topWidgets top_widget_;
    middleWidgets mid_widget_;
    bottomWidgets bottom_widget_;

signals:

public slots :
    

};

#endif // MAINWND_H
