#ifndef MIDDLELEFTSTACKWIDGET5_H
#define MIDDLELEFTSTACKWIDGET5_H

#include "baseWnd/basewidget.h"
#include <QStackedWidget>
#include <QButtonGroup>

class middleLeftStackWidget5 : public baseWidget {
    Q_OBJECT
public:
    explicit middleLeftStackWidget5(QWidget *parent = nullptr);
    virtual ~middleLeftStackWidget5() {}

protected:
    void InitUi();
    void InitConnect();

    virtual void paintEvent(QPaintEvent*) override;

signals:

    public slots :

private:
    QStackedWidget stack_down_widget_;
    QButtonGroup down_groups_;
};

#endif // MIDDLELEFTSTACKWIDGET5_H