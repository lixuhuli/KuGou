#ifndef MIDDLEWIDGETS_H
#define MIDDLEWIDGETS_H

#include "baseWnd/basewidget.h"

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
};

#endif // MIDDLEWIDGETS_H