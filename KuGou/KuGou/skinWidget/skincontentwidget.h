#ifndef SKINCONTENTWIDGET_H
#define SKINCONTENTWIDGET_H

#include "baseWnd/basewidget.h"

class skinContentWidget : public baseWidget {
    Q_OBJECT
public:
    explicit skinContentWidget(QWidget *parent = nullptr);
    virtual ~skinContentWidget() {}

protected:
    void InitUi();
    void InitConnect();

signals:

    public slots :

private:
};

#endif // SKINCONTENTWIDGET_H