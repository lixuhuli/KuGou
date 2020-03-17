#include "middleleftstackwidget3.h"
#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QPainter>

middleLeftStackWidget3::middleLeftStackWidget3(QWidget *parent /*= nullptr*/)
    : baseWidget(parent)
    , music_groups_(this)
    , stack_music_widget_(this) {
    InitUi();
    InitConnect();
}

void middleLeftStackWidget3::InitUi() {
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    music_groups_.setExclusive(true);

    QVBoxLayout *vLyout = new QVBoxLayout;
    if (!vLyout) return;

    QHBoxLayout *hLyout = new QHBoxLayout;

    QPushButton *btn_music = new QPushButton(this);
    btn_music->setFixedHeight(40);
    btn_music->setCheckable(true);
    btn_music->setChecked(true);
    btn_music->setCursor(Qt::PointingHandCursor);
    btn_music->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    btn_music->setText(QString::fromLocal8Bit("音乐电台"));
    btn_music->setStyleSheet("QPushButton{color:rgb(68,68,68);font-size:14px;}"
                             "QPushButton::checked{color:rgb(40,143,231);font-size:14px;}");
    music_groups_.addButton(btn_music, 0);


    QPushButton *btn_mtv = new QPushButton(this);
    btn_mtv->setFixedHeight(40);
    btn_mtv->setCheckable(true);
    btn_mtv->setCursor(Qt::PointingHandCursor);
    btn_mtv->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    btn_mtv->setText(QString::fromLocal8Bit("MV电台"));
    btn_mtv->setStyleSheet("QPushButton{color:rgb(68,68,68);font-size:14px;}"
                           "QPushButton::checked{color:rgb(40,143,231);font-size:14px;}");
    music_groups_.addButton(btn_mtv, 1);


    hLyout->addWidget(btn_music);
    hLyout->addWidget(btn_mtv);
    hLyout->setSpacing(0);
    hLyout->setContentsMargins(0, 0, 0, 0);

    vLyout->addLayout(hLyout);
    vLyout->addWidget(&stack_music_widget_);

    stack_music_widget_.setCurrentIndex(0);

    vLyout->setSpacing(0);
    vLyout->setContentsMargins(0, 0, 0, 0);
    setLayout(vLyout);
}

void middleLeftStackWidget3::InitConnect() {
    
}

void middleLeftStackWidget3::paintEvent(QPaintEvent* e) {
    baseWidget::paintEvent(e);

    QPainter p(this);
    p.setPen(QColor(230, 230, 230));
    p.drawLine(0, 40, width(), 40);
}
