#ifndef MIDDLELEFTSTACKWIDGET4_H
#define MIDDLELEFTSTACKWIDGET4_H

#include "baseWnd/basewidget.h"

class middleLeftStackWidget4 : public baseWidget {
    Q_OBJECT
public:
    explicit middleLeftStackWidget4(QWidget *parent = nullptr);
    virtual ~middleLeftStackWidget4() {}

protected:
    void InitUi();
    void InitConnect();

signals:

    public slots :

private:
};

#endif // MIDDLELEFTSTACKWIDGET4_H