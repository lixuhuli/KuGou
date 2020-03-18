#ifndef MIDDLEWIDGETRIGHT_H
#define MIDDLEWIDGETRIGHT_H

#include "baseWnd/basewidget.h"
#include <QButtonGroup>
#include <QStackedWidget>
#include "mvwidget.h"

class middleWidgetRight : public baseWidget {
    Q_OBJECT
public:
    explicit middleWidgetRight(QWidget *parent = nullptr);
    virtual ~middleWidgetRight() {}

protected:
    void InitUi();
    void InitConnect();

    virtual void paintEvent(QPaintEvent*) override;

signals:

    public slots :

private:
    QButtonGroup option_functions_;
    QStackedWidget stack_func_widget_;

    MvWidget mv_widget_;;
};

#endif // MIDDLEWIDGETRIGHT_H