#include "basewindow.h"
#include <QGridLayout>
#include<QPainter>
#include<qmath.h>

baseWindow::baseWindow(QWidget *parent /*= nullptr*/)
 : dragAutoSizeWnd(parent)
 , contents_margins_(QRect(4, 4, 4, 4)){
    setAttribute(Qt::WA_TranslucentBackground, true);

    main_widget_.setAutoFillBackground(true);
    QGridLayout *lyout = new QGridLayout;

    if (lyout) {
        lyout->addWidget(&main_widget_);
        lyout->setContentsMargins(contents_margins_.left(), contents_margins_.top(), contents_margins_.width(), contents_margins_.height());
        setLayout(lyout);
    }
}

void baseWindow::paintEvent(QPaintEvent *e) {
    __super::paintEvent(e);

    QPainter painter(this);
    // draw shadow margin

    QPainterPath path;
    path.setFillRule(Qt::WindingFill);
    path.addRect(9, 9, this->width() - 18, this->height() - 18);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.fillPath(path, QBrush(Qt::white));


    QColor color(0, 0, 0, 50);
    for (int i = 0; i < 9; i++)  {
        QPainterPath path;
        path.setFillRule(Qt::WindingFill);
        path.addRect(9 - i, 9 - i, this->width() - (9 - i) * 2, this->height() - (9 - i) * 2);
        color.setAlpha(150 - qSqrt(i) * 50);
        painter.setPen(color);
        painter.drawPath(path);
    }
}

void baseWindow::set_contents_margins(const QRect& rc) {
    contents_margins_ = rc;
}
