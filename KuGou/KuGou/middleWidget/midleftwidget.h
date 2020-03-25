#ifndef MIDLEFTWIDGET_H
#define MIDLEFTWIDGET_H

#include "baseWnd/basewidget.h"
#include <QButtonGroup>
#include <QStackedWidget>
#include <QPropertyAnimation>
#include "middleleftstackwidget2.h"
#include "middleleftstackwidget3.h"
#include "middleleftstackwidget1.h"
#include "middleleftstackwidget4.h"
#include "middleleftstackwidget5.h"


class midLeftWidget : public baseWidget {
    Q_OBJECT
    Q_PROPERTY(int indicator_x_ READ getValue WRITE setValue)
public:
    explicit midLeftWidget(QWidget *parent = nullptr);
    virtual ~midLeftWidget() {}

    void setTransStatus(bool isTrans);
    void setWidgetOpacity(int value);

    int getValue() { return indicator_x_; }
    void setValue(int i) { indicator_x_ = i; update(); }

protected:
    void InitUi();
    void InitConnect();
    void initAnimation();

    virtual void paintEvent(QPaintEvent *) override;

signals:

public slots :
    void onOptionPressed(int);
    void animafinished();

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

    // 动画类 option动画
    QPropertyAnimation animation_;
    bool isanima_;
    int indicator_x_;

    // stack动画
    QPropertyAnimation stack_animation_;
};

#endif // MIDLEFTWIDGET_H