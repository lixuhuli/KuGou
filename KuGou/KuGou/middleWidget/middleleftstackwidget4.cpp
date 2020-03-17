#include "middleleftstackwidget4.h"
#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>

middleLeftStackWidget4::middleLeftStackWidget4(QWidget *parent /*= nullptr*/)
    : baseWidget(parent) {
    InitUi();
    InitConnect();
}

void middleLeftStackWidget4::InitUi() {
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void middleLeftStackWidget4::InitConnect() {
    QVBoxLayout *vLyout = new QVBoxLayout;
    if (!vLyout) return;

    QLabel *label2 = new QLabel(QString::fromLocal8Bit("请选择连接手机的方式"), this);
    label2->adjustSize();
    label2->setAlignment(Qt::AlignHCenter);
    label2->setStyleSheet(QString::fromLocal8Bit("QLabel{color:rgb(68,68,68);font-family:黑体;font-size:18px;}"));

    QPushButton *btn = new QPushButton(this);
    btn->setFixedSize(206, 100);
    btn->setCursor(Qt::PointingHandCursor);
    btn->setStyleSheet("QPushButton{border-image: url(:/image/middlewidget/wire_connect (1).png);}"
        "QPushButton:hover{border-image: url(:/image/middlewidget/wire_connect (2).png);}"
        "QPushButton:pressed{border-image: url(:/image/middlewidget/wire_connect (3).png);}");

    QPushButton *btn2 = new QPushButton(this);
    btn2->setFixedSize(206, 100);
    btn2->setStyleSheet("QPushButton{border-image: url(:/image/middlewidget/net_connect (1).png);}"
        "QPushButton:hover{border-image: url(:/image/middlewidget/net_connect (2).png);}"
        "QPushButton:pressed{border-image: url(:/image/middlewidget/net_connect (3).png);}");


    vLyout->addSpacerItem(new QSpacerItem(10, 65, QSizePolicy::Expanding, QSizePolicy::Expanding));
    vLyout->addWidget(label2, 0, Qt::AlignHCenter);
    vLyout->addSpacing(50);
    vLyout->addWidget(btn, 0, Qt::AlignHCenter);
    vLyout->addSpacing(30);
    vLyout->addWidget(btn2, 0, Qt::AlignHCenter);

    vLyout->addSpacerItem(new QSpacerItem(10, 170, QSizePolicy::Expanding, QSizePolicy::Expanding));

    vLyout->setContentsMargins(0, 0, 0, 0);
    setLayout(vLyout);
}
