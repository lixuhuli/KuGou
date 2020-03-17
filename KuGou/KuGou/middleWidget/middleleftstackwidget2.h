#ifndef MIDDLELEFTSTACKWIDGET2_H
#define MIDDLELEFTSTACKWIDGET2_H

#include "baseWnd/basewidget.h"

class middleLeftStackWidget2 : public baseWidget {
    Q_OBJECT
public:
    explicit middleLeftStackWidget2(QWidget *parent = nullptr);
    virtual ~middleLeftStackWidget2() {}

protected:
    void InitUi();
    void InitConnect();

signals:

    public slots :

private:
};

#endif // MIDDLELEFTSTACKWIDGET2_H