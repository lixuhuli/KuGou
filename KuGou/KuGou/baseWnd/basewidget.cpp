#include "basewidget.h"
#include <QStyleOption>
#include <QPainter>
#include "mainWnd/mainwnd.h"

baseWidget::baseWidget(QWidget *parent) : QWidget(parent) {
    setStyleSheet("QWidget{background:transparent;}");
    setMouseTracking(true);
}
void baseWidget::paintEvent(QPaintEvent *e) {
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(e);
}

void baseWidget::mousePressEvent(QMouseEvent *e) {
    QWidget::mousePressEvent(e);
}

void baseWidget::mouseMoveEvent(QMouseEvent *e) {
    mainWnd::getInstance().mouseMoveEvent(e);
    QWidget::mouseMoveEvent(e);
}

void baseWidget::mouseReleaseEvent(QMouseEvent *e) {
    QWidget::mouseReleaseEvent(e);
}
