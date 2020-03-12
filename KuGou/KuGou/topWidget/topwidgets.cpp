#include "topwidgets.h"
#include <QStyleOption>
#include <QPainter>
#include <QBoxLayout>
#include "mainWnd/mainwnd.h"
#include <QLabel>

topWidgets::topWidgets(QWidget *parent)
    : QWidget(parent) {
    setStyleSheet("TopWidgets{background:transparent;}");
    setMouseTracking(true);
    initWidget();
}

void topWidgets::paintEvent(QPaintEvent *e) {
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    __super::paintEvent(e);
}

void topWidgets::mouseMoveEvent(QMouseEvent* e) {
    mainWnd::getInstance().mouseMoveEvent(e);
    __super::mouseMoveEvent(e);
}

void topWidgets::initWidget() {
    setMinimumHeight(50);
    setMaximumHeight(50);

    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    QHBoxLayout *main_yout_ = new QHBoxLayout;
    if (!main_yout_) return;

    main_yout_->setAlignment(Qt::AlignLeft);

    QPushButton *btn = new QPushButton();
    btn->setFixedSize(30, 30);
    btn->setStyleSheet("QPushButton{background:transparent;border-image:url(:/image/topwidget/label_icon.png)}");

    main_yout_->addWidget(btn);
    main_yout_->addSpacing(11);

    btn_login_.setFixedSize(26, 24);
    btn_login_.setStyleSheet("QPushButton{background:transparent;color:white;font-family:ËÎÌå;font-size:12px;}");
    btn_login_.setText(QString::fromLocal8Bit("µÇÂ½"));
    btn_login_.setCursor(QCursor(Qt::PointingHandCursor));
    main_yout_->addWidget(&btn_login_);
    main_yout_->addSpacing(5);

    QLabel*label2 = new QLabel(QString::fromLocal8Bit("Ø­"), this);
    label2->setFixedSize(10, 20);
    label2->setStyleSheet("color:white;");
    label2->adjustSize();
    main_yout_->addWidget(label2);
    main_yout_->addSpacing(5);


    m_btnregister.setFixedSize(26, 24);
    m_btnregister.setStyleSheet("QPushButton{background:transparent;color:white;font-family:ËÎÌå;font-size:12px;}");
    m_btnregister.setText(QString::fromLocal8Bit("×¢²á"));
    main_yout_->addWidget(&m_btnregister);



    //main_yout_->addSpacing(190);

    main_yout_->setSpacing(0);
    main_yout_->setContentsMargins(16, 0, 15, 0);
    setLayout(main_yout_);

}
