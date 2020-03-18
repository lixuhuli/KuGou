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

    void setDrawLine(bool draw = true) { m_isdrawline = draw; }

protected:
    void InitUi();
    void InitConnect();

    virtual void paintEvent(QPaintEvent*) override;

signals:
    void setIsTransparent(bool trans);

public slots :
    void OnButtonToggled(int id, bool check);

private:
    QButtonGroup option_functions_;
    QStackedWidget stack_func_widget_;

    MvWidget mv_widget_;

    bool m_isdrawline;
};

#endif // MIDDLEWIDGETRIGHT_H