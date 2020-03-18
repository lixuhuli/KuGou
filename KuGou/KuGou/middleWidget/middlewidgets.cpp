#include "middlewidgets.h"
#include <QBoxLayout>

middleWidgets::middleWidgets(QWidget *parent) 
    : baseWidget(parent)
    , btn_hide_(this)
    , left_widget_(this)
    , right_widget_(this){
    setStyleSheet("baseWidget{background:white;}");

    InitUi();
    InitConnect();
}

void middleWidgets::InitUi() {
    QHBoxLayout *hyout = new QHBoxLayout;
    if (!hyout) return;

    btn_hide_.setFixedSize(13, 55);
    btn_hide_.hide();
    btn_hide_.setChecked(true);
    btn_hide_.setCursor(Qt::PointingHandCursor);
    btn_hide_.setStyleSheet("QRadioButton::indicator::unchecked{border-image:url(:/image/middlewidget/btn_listshow (1).png);}"
        "QRadioButton::indicator::unchecked:hover{border-image:url(:/image/middlewidget/btn_listshow (2).png);}"
        "QRadioButton::indicator::unchecked:pressed{border-image:url(:/image/middlewidget/btn_listshow (3).png);}"
        "QRadioButton::indicator::checked{border-image:url(:/image/middlewidget/btn_listhide (1).png);}"
        "QRadioButton::indicator::checked:hover{border-image:url(:/image/middlewidget/btn_listhide (2).png);}"
        "QRadioButton::indicator::checked:pressed{border-image:url(:/image/middlewidget/btn_listhide (3).png);}"
        "QRadioButton::indicator{width:13px;height:55px;}");

    hyout->addWidget(&left_widget_);
    hyout->addWidget(&btn_hide_);
    hyout->addWidget(&right_widget_);

    right_widget_.setMinimumWidth(690);

    hyout->setSpacing(0);
    hyout->setContentsMargins(0, 0, 0, 0);
    setLayout(hyout);
}

void middleWidgets::InitConnect() {
    connect(&btn_hide_, SIGNAL(toggled(bool)), &left_widget_, SLOT(setVisible(bool)));
}

void middleWidgets::mouseMoveEvent(QMouseEvent *e) {
    baseWidget::mouseMoveEvent(e);
}

void middleWidgets::setBackgroundstatus(bool isTransparent) {
    QString str = QString("baseWidget{background:%1;}").arg(isTransparent ? "transparent" : "white");
    left_widget_.setTransStatus(isTransparent);
    setStyleSheet(str);

    if (isTransparent) btn_hide_.show();
    else {
        btn_hide_.hide();
        left_widget_.show();
        btn_hide_.setChecked(true);
    }
}
