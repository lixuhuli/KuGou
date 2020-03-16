#ifndef MIDDLEWIDGETS_H
#define MIDDLEWIDGETS_H

#include "baseWnd/basewidget.h"
#include "midleftwidget.h"

class middleWidgets : public baseWidget {
    Q_OBJECT
public:
    explicit middleWidgets(QWidget *parent = nullptr);
    virtual ~middleWidgets() {}

protected:
    void InitUi();
    void InitConnect();

signals:

public slots:

private:
    midLeftWidget left_widget_;
    baseWidget right_widget_;
};

#endif // MIDDLEWIDGETS_H