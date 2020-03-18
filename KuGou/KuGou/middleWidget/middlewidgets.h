#ifndef MIDDLEWIDGETS_H
#define MIDDLEWIDGETS_H

#include "baseWnd/basewidget.h"
#include "midleftwidget.h"
#include "middlewidgetright.h"

class middleWidgets : public baseWidget {
    Q_OBJECT
public:
    explicit middleWidgets(QWidget *parent = nullptr);
    virtual ~middleWidgets() {}

protected:
    void InitUi();
    void InitConnect();

    virtual void mousePressEvent(QMouseEvent *) override { setFocus(); }
    virtual void mouseReleaseEvent(QMouseEvent *) override  {}
    virtual void mouseMoveEvent(QMouseEvent *) override;

signals:

public slots:

private:
    midLeftWidget left_widget_;
    middleWidgetRight right_widget_;
};

#endif // MIDDLEWIDGETS_H