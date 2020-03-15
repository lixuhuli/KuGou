#include "volumuctrl.h"
#include <QBoxLayout>

VolumuCtrl::VolumuCtrl(QWidget *parent /*= nullptr*/)
    : QRadioButton(parent) {
}

VolumuCtrl::VolumuCtrl(const QString &text, QWidget *parent /*= nullptr*/) 
 : QRadioButton(text, parent) {

}

volSliderWidget::volSliderWidget(QWidget* parent /*= 0*/)
 : baseWidget(parent) {
    QHBoxLayout *hlyout = new QHBoxLayout;
    if (!hlyout) return;

    setFixedSize(30, 110);
    setStyleSheet("QWidget{background-color:rgb(64,64,64,200);border-radius:5px;}");


    m_slider = new Slider(Qt::Vertical, this);
    m_slider->setStyleSheet("QSlider{background:transparent;}"
        "QSlider::groove:vertical{background:transparent;border-radius:2px;width:3px;}"
        "QSlider::sub-page:vertical{background:rgb(122,122,122);}"
        "QSlider::add-page:vertical{background:rgb(255, 255, 160);}"
        "QSlider::handle:vertical{background:rgb(255, 255, 160); height: 8px; border-radius: 4px; margin-left: -3px;  margin-right: -3px;  }");
    m_slider->setFixedSize(12, 85);

    hlyout->addWidget(m_slider);
    hlyout->setContentsMargins(0, 0, 0, 0);
    setLayout(hlyout);
}
