#ifndef VOLUMUCTRL_H
#define VOLUMUCTRL_H

#include <QRadioButton>
#include "baseWnd/basewidget.h"
#include "slider.h"

class VolumuCtrl : public QRadioButton {
    Q_OBJECT
public:
    explicit VolumuCtrl(QWidget *parent = nullptr);
    explicit VolumuCtrl(const QString &text, QWidget *parent = nullptr);
    virtual ~VolumuCtrl() {}


};

class volSliderWidget :public baseWidget {
    Q_OBJECT
public:
    volSliderWidget(QWidget* parent = 0);
    virtual ~volSliderWidget() {}

public:
    Slider* volumn_slider() { return m_slider; }

protected:
    void InitUi();
    void InitConnect();

private:
    Slider *m_slider;

public slots:
    //void slot_sliderMove(int va) { QToolTip::showText(QCursor::pos(), QString::number(va)); }

};

#endif // VOLUMUCTRL_H