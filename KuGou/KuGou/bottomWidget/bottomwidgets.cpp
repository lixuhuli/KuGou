#include "bottomwidgets.h"

bottomWidgets::bottomWidgets(QWidget *parent) 
    : baseWidget(parent) {
    InitUi();
    InitConnect();
}

void bottomWidgets::InitUi() {
    setFixedHeight(66);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
}

void bottomWidgets::InitConnect() {

}
