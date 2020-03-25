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

    // �Զ�ˢ�¹�������ĸ߶ȣ�����������������֮������itemԪ�ؽ��治�ᶶ��
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