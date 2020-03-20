#include "skincontentwidget.h"

skinContentWidget::skinContentWidget(QWidget *parent /*= nullptr*/)
    : baseWidget(parent) {
    InitUi();
    InitConnect();
}

void skinContentWidget::InitUi() {
    setStyleSheet("QWidget{background: white;}");
}

void skinContentWidget::InitConnect() {

}
