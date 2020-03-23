#ifndef MIDDLELEFTSTACKWIDGET1_H
#define MIDDLELEFTSTACKWIDGET1_H

#include <QButtonGroup>
#include "baseWnd/basewidget.h"

class QGridLayout;
class QPushButton;
class stackContentItem;
class middleLeftStackWidget1 : public baseWidget {
    Q_OBJECT
public:
    explicit middleLeftStackWidget1(QWidget *parent = nullptr);
    virtual ~middleLeftStackWidget1() {}

protected:
    void InitUi();
    void InitConnect();

private:

signals:

    public slots :

private:
    QGridLayout* content_layout_;
    QButtonGroup content_item_groups_;

    stackContentItem* default_item_;
    stackContentItem* love_item_;

    int content_item_id_;
};

#endif // MIDDLELEFTSTACKWIDGET1_H