#ifndef MIDDLELEFTSTACKWIDGET1_H
#define MIDDLELEFTSTACKWIDGET1_H

#include <QButtonGroup>
#include "baseWnd/basewidget.h"

class QVBoxLayout;
class QGridLayout;
class QPushButton;
class stackContentItem;
class middleLeftStackWidget1 : public baseWidget {
    Q_OBJECT
public:
    explicit middleLeftStackWidget1(QWidget *parent = nullptr);
    virtual ~middleLeftStackWidget1() {}

    void updateLineColor(const QColor& color);

protected:
    void InitUi();
    void InitConnect();

    virtual void resizeEvent(QResizeEvent *) override;

private:

signals:

public slots :
    void addContentItem();
    void delContentItem(stackContentItem*);

    // 自动刷新滚动区域的高度，这样当滚动条出来之后，增加item元素界面不会抖动
    void setAutoLayout();
    void addDragItemToItem(stackContentItem*, stackContentItem*, bool);

private:
    QVBoxLayout* content_layout_;
    baseWidget* content_widget_;
    QButtonGroup content_item_groups_;

    stackContentItem* default_item_;
    stackContentItem* love_item_;

    int content_item_id_;
};

#endif // MIDDLELEFTSTACKWIDGET1_H