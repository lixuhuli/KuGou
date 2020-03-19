#ifndef SKINWIDGET_H
#define SKINWIDGET_H

#include "baseWnd/baseCommonWnd.h"

class skinWidget : public baseCommonWnd {
    Q_OBJECT
public:
    explicit skinWidget(QWidget *parent = nullptr);
    virtual ~skinWidget() {}

protected:
    void InitUi();
    void InitConnect();

signals:

    public slots :

private:
};

#endif // SKINWIDGET_H