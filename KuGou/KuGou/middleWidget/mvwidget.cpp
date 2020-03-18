#include "mvwidget.h"
#include <QPainter>

MvWidget::MvWidget(QWidget *parent /*= nullptr*/)
    : baseWidget(parent) {
    InitUi();
    InitConnect();
}

void MvWidget::InitUi() {
}

void MvWidget::InitConnect() {

}

void MvWidget::paintEvent(QPaintEvent*) {
    QPainter p(this);
    p.setBrush(Qt::black);
    p.drawRect(0, 0, width(), height());
}
