#ifndef MIDLEFTWIDGET_H
#define MIDLEFTWIDGET_H

#include "baseWnd/basewidget.h"
#include <QButtonGroup>
#include <QStackedWidget>
#include "middleleftstackwidget2.h"


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
        
    QStackedWidget stack_widget_;
    baseWidget stack_widget_page1_;
    middleLeftStackWidget2 stack_widget_page2_;
    baseWidget stack_widget_page3_;
    baseWidget stack_widget_page4_;
    baseWidget stack_widget_page5_;
};

#endif // MIDLEFTWIDGET_H