#ifndef SKINCONTENTWIDGET_H
#define SKINCONTENTWIDGET_H

#include "baseWnd/basewidget.h"
#include <QPushButton>

class skinContentWidget : public baseWidget {
    Q_OBJECT
public:
    explicit skinContentWidget(QWidget *parent = nullptr);
    virtual ~skinContentWidget() {}

protected:
    void InitUi();
    void InitConnect();

private:
    QPushButton* createSkinContentItem();

signals:

    public slots :

private:
};


class skinContentItem : public QPushButton {
    Q_OBJECT
public:
    explicit skinContentItem(QWidget *parent = nullptr) : QPushButton(parent) {}
    virtual ~skinContentItem() {}

protected:
    virtual void enterEvent(QEvent *e) override { QPushButton::enterEvent(e); enterItem(true); };
    virtual void leaveEvent(QEvent *e) override { QPushButton::leaveEvent(e); enterItem(false); };

signals:
    void enterItem(bool enter);

    public slots :

private:
};

#endif // SKINCONTENTWIDGET_H