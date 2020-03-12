#ifndef MAINWND_H
#define MAINWND_H

#include <QDialog>
#include <QMutex>
#include "baseWnd/basewindow.h"
#include "topWidget/topwidgets.h"

class mainWnd : public baseWindow {
    friend class baseWidget;
    Q_OBJECT
public:
    static mainWnd& getInstance();

public:
    mainWnd(QWidget *parent = 0);
    virtual ~mainWnd();

protected:
    void initLayout();

protected:
    virtual void mouseDoubleClickEvent(QMouseEvent *) override;

private:
    static QMutex mutex_;                          // ʵ����������
    static QAtomicPointer<mainWnd> main_wnd_;      // <ʹ��ԭ��ָ��,Ĭ�ϳ�ʼ��Ϊ0��

    topWidgets top_widget_;
    QWidget mid_widget_;
    QWidget bottom_widget_;
};

#endif // MAINWND_H
