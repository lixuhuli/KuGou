#ifndef BOTTOMWIDGETS_H
#define BOTTOMWIDGETS_H

#include "baseWnd/basewidget.h"

class bottomWidgets : public baseWidget {
    Q_OBJECT
public:
    explicit bottomWidgets(QWidget *parent = nullptr);
    virtual ~bottomWidgets() {}

protected:
    void InitUi();
    void InitConnect();

signals:

public slots:
};

#endif // BOTTOMWIDGETS_H