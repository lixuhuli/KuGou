#ifndef SKINWIDGET_H
#define SKINWIDGET_H

#include <QScrollArea>
#include "baseWnd/baseCommonWnd.h"
#include <QPushButton>
#include "skincontentwidget.h"

class skinWidget : public baseCommonWnd {
    Q_OBJECT
public:
    explicit skinWidget(QWidget *parent = nullptr);
    virtual ~skinWidget() {}

protected:
    void InitUi();
    void InitConnect();

    ////////////////////////////
    void InitMidTopUi(QWidget* widget);

    virtual bool eventFilter(QObject *, QEvent *) override;

signals:

    public slots :

private:
    QScrollArea scrollArea;
    QPushButton m_btnAdjustWindow;

    skinContentWidget skin_con_widget_;

    baseWidget mid_top_widget_;

private:
};

#endif // SKINWIDGET_H