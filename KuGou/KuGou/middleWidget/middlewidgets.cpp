#include "middlewidgets.h"
#include <QBoxLayout>

middleWidgets::middleWidgets(QWidget *parent) 
    : baseWidget(parent) {
    setStyleSheet("baseWidget{background:white;}");

    InitUi();
    InitConnect();
}

void middleWidgets::InitUi() {
    QHBoxLayout *hyout = new QHBoxLayout;
    if (hyout) return;
}

void middleWidgets::InitConnect() {

}
