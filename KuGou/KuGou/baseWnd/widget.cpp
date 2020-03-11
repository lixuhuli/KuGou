#include "widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent) 
    : QWidget(parent) {

}

void Widget::setSkinPic(const QString &skin) {
    skin_pic_.load(skin);
    skin_path_ = skin;
}

void Widget::paintEvent(QPaintEvent *e) {
    __super::paintEvent(e);
    if (skin_pic_.isNull()) return;

    QPainter painter(this);

    float d = (float)skin_pic_.height() / skin_pic_.width();
    int h = d * width();
    int w = height() / d;
    if (h < height()) {
        painter.drawPixmap(0, 0, w, height(), skin_pic_);
        return;
    }

    painter.drawPixmap(0, 0, width(), h, skin_pic_);
}

void Widget::resizeEvent(QResizeEvent *e) {
    __super::resizeEvent(e);
    //updateSkin();
}

void Widget::updateSkin() {
    if (skin_pic_.isNull()) return;

    QPalette palette = this->palette();
    palette.setBrush(backgroundRole(), QBrush(skin_pic_.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    this->setPalette(palette);

    setAutoFillBackground(true);
}
