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
    static QMutex mutex_;                          // ʵ����������
    static QAtomicPointer<mainWnd> main_wnd_;    // <ʹ��ԭ��ָ��,Ĭ�ϳ�ʼ��Ϊ0��
};

#endif // MAINWND_H
