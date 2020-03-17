#ifndef MIDDLELEFTSTACKWIDGET3_H
#define MIDDLELEFTSTACKWIDGET3_H

#include "baseWnd/basewidget.h"

class middleLeftStackWidget3 : public baseWidget {
    Q_OBJECT
public:
    explicit middleLeftStackWidget3(QWidget *parent = nullptr);
    virtual ~middleLeftStackWidget3() {}

protected:
    void InitUi();
    void InitConnect();

signals:

    public slots :

private:
};

#endif // MIDDLELEFTSTACKWIDGET3_H