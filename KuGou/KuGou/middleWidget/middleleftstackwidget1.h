#ifndef MIDDLELEFTSTACKWIDGET1_H
#define MIDDLELEFTSTACKWIDGET1_H

#include "baseWnd/basewidget.h"

class middleLeftStackWidget1 : public baseWidget {
    Q_OBJECT
public:
    explicit middleLeftStackWidget1(QWidget *parent = nullptr);
    virtual ~middleLeftStackWidget1() {}

protected:
    void InitUi();
    void InitConnect();

signals:

    public slots :

private:
};

#endif // MIDDLELEFTSTACKWIDGET1_H