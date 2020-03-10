#ifndef MAINWND_H
#define MAINWND_H

#include <QDialog>

class mainWnd : public QDialog
{
    Q_OBJECT

public:
    mainWnd(QWidget *parent = 0);
    ~mainWnd();
};

#endif // MAINWND_H
