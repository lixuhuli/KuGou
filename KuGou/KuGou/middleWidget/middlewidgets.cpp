#include "middlewidgets.h"
#include <QBoxLayout>

middleWidgets::middleWidgets(QWidget *parent) 
    : baseWidget(parent)
    , left_widget_(this)
    , right_widget_(this){
    setStyleSheet("baseWidget{background:white;}");

    InitUi();
    InitConnect();
}

void middleWidgets::InitUi() {
    QHBoxLayout *hyout = new QHBoxLayout;
    if (!hyout) return;

    hyout->addWidget(&left_widget_);
    hyout->addWidget(&right_widget_);

    right_widget_.setMinimumWidth(690);

    hyout->setSpacing(0);
    hyout->setContentsMargins(0, 0, 0, 0);
    setLayout(hyout);
}

void middleWidgets::InitConnect() {

}

void middleWidgets::mouseMoveEvent(QMouseEvent *e) {
    baseWidget::mouseMoveEvent(e);
}
