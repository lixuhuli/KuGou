#ifndef MIDDLELEFTSTACKWIDGET3_H
#define MIDDLELEFTSTACKWIDGET3_H

#include "baseWnd/basewidget.h"
#include <QStackedWidget>
#include <QButtonGroup>

class middleLeftStackWidget3 : public baseWidget {
    Q_OBJECT
public:
    explicit middleLeftStackWidget3(QWidget *parent = nullptr);
    virtual ~middleLeftStackWidget3() {}

protected:
    void InitUi();
    void InitConnect();

    virtual void paintEvent(QPaintEvent*) override;

signals:

    public slots :

private:
    QStackedWidget stack_music_widget_;
    QButtonGroup music_groups_;

};

#endif // MIDDLELEFTSTACKWIDGET3_H