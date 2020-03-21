#ifndef SKINWIDGET_H
#define SKINWIDGET_H

#include <QScrollArea>
#include "baseWnd/baseCommonWnd.h"
#include <QPushButton>
#include "skincontentwidget.h"
#include "customizeCtrl/slider.h"

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

    void InitSkinSliderUi();

    virtual bool eventFilter(QObject *, QEvent *) override;

signals:

public slots :
    void onSliderOpacity(int value);

private:
    QScrollArea scrollArea;
    QPushButton m_btnAdjustWindow;
    QPushButton m_btnOpacity;

    skinContentWidget skin_con_widget_;

    baseWidget mid_top_widget_;

    baseWidget slider_widget_;
    Slider* list_skin_slider_;

private:
};

#endif // SKINWIDGET_H