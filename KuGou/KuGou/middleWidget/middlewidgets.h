#ifndef MIDDLEWIDGETS_H
#define MIDDLEWIDGETS_H

#include "baseWnd/basewidget.h"
#include "midleftwidget.h"
#include "middlewidgetright.h"
#include <QRadioButton>

class middleWidgets : public baseWidget {
    Q_OBJECT
public:
    explicit middleWidgets(QWidget *parent = nullptr);
    virtual ~middleWidgets() {}

protected:
    void InitUi();
    void InitConnect();

    virtual void mousePressEvent(QMouseEvent *) override;
    virtual void mouseReleaseEvent(QMouseEvent *) override;
    virtual void mouseMoveEvent(QMouseEvent *) override;

signals:

public slots:
    void setBackgroundstatus(bool isTransparent);
    void setLeftWidgetOpacity(int value);

private:
    midLeftWidget left_widget_;
    QRadioButton btn_hide_;
    middleWidgetRight right_widget_;
};

#endif // MIDDLEWIDGETS_H