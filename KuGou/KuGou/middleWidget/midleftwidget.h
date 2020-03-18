#ifndef MIDLEFTWIDGET_H
#define MIDLEFTWIDGET_H

#include "baseWnd/basewidget.h"
#include <QButtonGroup>
#include <QStackedWidget>
#include "middleleftstackwidget2.h"
#include "middleleftstackwidget3.h"
#include "middleleftstackwidget1.h"
#include "middleleftstackwidget4.h"
#include "middleleftstackwidget5.h"


class midLeftWidget : public baseWidget {
    Q_OBJECT
public:
    explicit midLeftWidget(QWidget *parent = nullptr);
    virtual ~midLeftWidget() {}

    void setTransStatus(bool isTrans);

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
    middleLeftStackWidget1 stack_widget_page1_;
    middleLeftStackWidget2 stack_widget_page2_;
    middleLeftStackWidget3 stack_widget_page3_;
    middleLeftStackWidget4 stack_widget_page4_;
    middleLeftStackWidget5 stack_widget_page5_;

    bool m_isDrawVerticalLine;

    QColor line_color_;
    QColor bg_color_;
};

#endif // MIDLEFTWIDGET_H