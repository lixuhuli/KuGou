#ifndef MVWIDGET_H
#define MVWIDGET_H

#include "baseWnd/basewidget.h"

class MvWidget : public baseWidget {
    Q_OBJECT
public:
    explicit MvWidget(QWidget *parent = nullptr);
    virtual ~MvWidget() {}

protected:
    void InitUi();
    void InitConnect();

    virtual void paintEvent(QPaintEvent*) override;

signals:

    public slots :

private:
};

#endif // MVWIDGET_H