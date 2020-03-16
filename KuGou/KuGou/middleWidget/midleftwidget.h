#ifndef MIDLEFTWIDGET_H
#define MIDLEFTWIDGET_H

#include "baseWnd/basewidget.h"


class midLeftWidget : public baseWidget {
    Q_OBJECT
public:
    explicit midLeftWidget(QWidget *parent = nullptr);
    virtual ~midLeftWidget() {}

protected:
    void InitUi();
    void InitConnect();

signals:

    public slots :

};

#endif // MIDLEFTWIDGET_H