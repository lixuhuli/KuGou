#include "baseCommonWnd.h"
#include <QGridLayout>
#include <QPainter>
#include <qmath.h>
#include <QMouseEvent>

baseCommonWnd::baseCommonWnd(QWidget *parent)
    : QDialog(parent)
    , border_(4)
    , main_widget_(this)
    , mouse_pos_(0, 0)
    , window_pos_(0, 0)
    , cursol_pressed_state_(UnPressed) {
    setMinimumSize(550, 440);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::X11BypassWindowManagerHint); //setting windows tool bar icon invisiable
    setAttribute(Qt::WA_TranslucentBackground, true);

    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    main_widget_.setAutoFillBackground(true);

    QGridLayout *lyout = new QGridLayout;
    lyout->addWidget(&main_widget_);
    lyout->setContentsMargins(4, 4, 4, 4);
    setLayout(lyout);
}

void baseCommonWnd::paintEvent(QPaintEvent* e) {
    QWidget::paintEvent(e);

    QPainter painter(this);
    QPainterPath path;
    path.setFillRule(Qt::WindingFill);
    path.addRect(9, 9, this->width() - 18, this->height() - 18);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.fillPath(path, QBrush(Qt::white));

    QColor color(0, 0, 0, 50);
    for (int i = 0; i < 9; i++) {
        QPainterPath path;
        path.setFillRule(Qt::WindingFill);
        path.addRect(9 - i, 9 - i, this->width() - (9 - i) * 2, this->height() - (9 - i) * 2);
        color.setAlpha(150 - qSqrt(i) * 50);
        painter.setPen(color);
        painter.drawPath(path);
    }
}

void baseCommonWnd::mousePressEvent(QMouseEvent *event) {
    if (!event) return;

    setFocus();

    if (event->button() == Qt::LeftButton) {
        window_pos_ = this->pos();
        if (QRect(border_ + 1, border_ + 1, width() - (border_ + 1) * 2, height() - (border_ + 1) * 2).contains(event->pos())) {
            mouse_pos_ = event->globalPos();
            cursol_pressed_state_ = WinRegion;
        }
        else
            cursol_pressed_state_ = WinBorder;
    }
}

void baseCommonWnd::mouseMoveEvent(QMouseEvent *event) {
    if (!event) return;

    if (cursol_pressed_state_ == WinRegion) {
        this->move(window_pos_ + (event->globalPos() - mouse_pos_));
    }
}

void baseCommonWnd::mouseReleaseEvent(QMouseEvent *) {
    mouse_pos_.setX(0);
    mouse_pos_.setY(0);
    cursol_pressed_state_ = UnPressed;
}