#include "middleleftstackwidget5.h"
#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QPainter>

middleLeftStackWidget5::middleLeftStackWidget5(QWidget *parent /*= nullptr*/)
    : baseWidget(parent)
    , down_groups_(this)
    , stack_down_widget_(this) {
    InitUi();
    InitConnect();
}

void middleLeftStackWidget5::InitUi() {
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    down_groups_.setExclusive(true);

    QVBoxLayout *vLyout = new QVBoxLayout;
    if (!vLyout) return;

    QHBoxLayout *hLyout = new QHBoxLayout;

    QPushButton *btn_mydown = new QPushButton(this);
    btn_mydown->setCheckable(true);
    btn_mydown->setChecked(true);
    btn_mydown->setFixedHeight(40); 
    btn_mydown->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    btn_mydown->setCursor(Qt::PointingHandCursor);
    btn_mydown->setText(QString::fromLocal8Bit("我的下载"));
    btn_mydown->setStyleSheet("QPushButton{color:rgb(68,68,68);font-size:14px;}"
        "QPushButton::checked{color:rgb(40,143,231);font-size:14px;}");
    down_groups_.addButton(btn_mydown, 0);

    QPushButton *btn_local = new QPushButton(this);
    btn_local->setCheckable(true);
    btn_local->setFixedHeight(40);
    btn_local->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    btn_local->setCursor(Qt::PointingHandCursor);
    btn_local->setText(QString::fromLocal8Bit("本地导入"));
    btn_local->setStyleSheet("QPushButton{color:rgb(68,68,68);font-size:14px;}"
        "QPushButton::checked{color:rgb(40,143,231);font-size:14px;}");
    down_groups_.addButton(btn_local, 1);


    hLyout->addWidget(btn_mydown);
    hLyout->addWidget(btn_local);
    hLyout->setSpacing(0);
    hLyout->setContentsMargins(0, 0, 0, 0);

    stack_down_widget_.addWidget(new baseWidget(this));
    stack_down_widget_.addWidget(new baseWidget(this));

    vLyout->addLayout(hLyout);
    vLyout->addWidget(&stack_down_widget_);

    stack_down_widget_.setCurrentIndex(0);

    vLyout->setSpacing(0);
    vLyout->setContentsMargins(0, 0, 0, 0);
    setLayout(vLyout);
}

void middleLeftStackWidget5::InitConnect() {

}

void middleLeftStackWidget5::paintEvent(QPaintEvent* e) {
    baseWidget::paintEvent(e);

    QPainter p(this);
    p.setPen(QColor(230, 230, 230));
    p.drawLine(0, 40, width(), 40);
}
