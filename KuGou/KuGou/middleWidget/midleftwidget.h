#ifndef MIDLEFTWIDGET_H
#define MIDLEFTWIDGET_H

#include "baseWnd/basewidget.h"
#include <QButtonGroup>


class midLeftWidget : public baseWidget {
    Q_OBJECT
public:
    explicit midLeftWidget(QWidget *parent = nullptr);
    virtual ~midLeftWidget() {}

protected:
    void InitUi();
    void InitConnect();
    void initAnimation();

    virtual void paintEvent(QPaintEvent *) override;

signals:

    public slots :

private:
    QButtonGroup option_groups_;
    QPixmap opt_pic_;
};

#endif // MIDLEFTWIDGET_H