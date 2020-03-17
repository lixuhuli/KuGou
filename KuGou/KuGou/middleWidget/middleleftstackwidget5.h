#ifndef MIDDLELEFTSTACKWIDGET5_H
#define MIDDLELEFTSTACKWIDGET5_H

#include "baseWnd/basewidget.h"

class middleLeftStackWidget5 : public baseWidget {
    Q_OBJECT
public:
    explicit middleLeftStackWidget5(QWidget *parent = nullptr);
    virtual ~middleLeftStackWidget5() {}

protected:
    void InitUi();
    void InitConnect();

signals:

    public slots :

private:
};

#endif // MIDDLELEFTSTACKWIDGET5_H