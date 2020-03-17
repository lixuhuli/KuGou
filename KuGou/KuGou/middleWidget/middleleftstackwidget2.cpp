#include "middleleftstackwidget2.h"
#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>

middleLeftStackWidget2::middleLeftStackWidget2(QWidget *parent /*= nullptr*/)
    : baseWidget(parent) {
    InitUi();
    InitConnect();
}

void middleLeftStackWidget2::InitUi() {
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QVBoxLayout *vLyout = new QVBoxLayout;
    if (!vLyout) return;

    QLabel *label = new QLabel(this);
    label->setStyleSheet("QLabel{border:NULL;background-image:url(:/image/middlewidget/lab_backups.png);}");
    label->setFixedSize(146, 90);

    QLabel *label2 = new QLabel(QString::fromLocal8Bit("云端备份 多屏同步"), this);
    label2->adjustSize();
    label2->setAlignment(Qt::AlignHCenter);
    label2->setStyleSheet("QLabel{color:rgb(52,52,52);font-size:18px}");
    

    QFont font;
    font.setPixelSize(14);
    QLabel *label3 = new QLabel(QString::fromLocal8Bit("你的列表有  首歌曲未设置备份"), this);
    label3->adjustSize();
    label3->setAlignment(Qt::AlignHCenter);
    label3->setStyleSheet("color:rgb(51,51,51);");
    label3->setFont(font);

    QPushButton *btn = new QPushButton();
    btn->setText(QString::fromLocal8Bit("马上使用"));
    btn->setFixedSize(170, 36);
    btn->setCursor(QCursor(Qt::PointingHandCursor));
    btn->setStyleSheet("QPushButton{font-size:16px;color:rgb(80,80,80);border: 1px solid;border-color:rgb(229,229,229);background:rgb(240,240,240);}"
        "QPushButton:hover{font-size:16px;color:rgb(30,30,30);border: 1px solid;border-color:rgb(219,219,219);background:rgb(229,229,229);}"
        "QPushButton:pressed{font-size:16px;color:rgb(80,80,80);border: 1px solid;border-color:rgb(229,229,229);background:rgb(240,240,240);}");

    QWidget *lineWid = new QWidget(this);
    lineWid->setMinimumSize(250, 1);
    lineWid->setMaximumSize(320, 1);
    lineWid->setStyleSheet("QWidget{border:1px solid rgb(230,230,230);}");
    lineWid->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    QLabel *lab2DC = new QLabel(this);
    lab2DC->setPixmap(QPixmap(":/image/middlewidget/lab_2DC.png"));
    lab2DC->setFixedSize(82, 82);

    QPushButton *labdown = new QPushButton(this);
    labdown->adjustSize();
    labdown->setCursor(QCursor(Qt::PointingHandCursor));
    labdown->setText(QString::fromLocal8Bit("扫一扫下载手机酷狗"));
    labdown->setStyleSheet("color:rgb(51,51,51);text-decoration: underline;font-size:14px;");

    vLyout->addSpacerItem(new QSpacerItem(10, 40, QSizePolicy::Expanding, QSizePolicy::Expanding));
    vLyout->addWidget(label, 0, Qt::AlignHCenter);
    vLyout->addSpacing(25);
    vLyout->addWidget(label2, 0, Qt::AlignHCenter);
    vLyout->addSpacing(10);
    vLyout->addWidget(label3, 0, Qt::AlignHCenter);
    vLyout->addSpacing(20);
    vLyout->addWidget(btn, 0, Qt::AlignHCenter);
    vLyout->addSpacing(20);
    vLyout->addWidget(lineWid, 0, Qt::AlignHCenter);
    vLyout->addSpacing(40);
    vLyout->addWidget(lab2DC, 0, Qt::AlignHCenter);
    vLyout->addSpacing(20);
    vLyout->addWidget(labdown, 0, Qt::AlignHCenter);

    vLyout->addSpacerItem(new QSpacerItem(10, 50, QSizePolicy::Expanding, QSizePolicy::Expanding));

    vLyout->setContentsMargins(0, 0, 0, 0);
    setLayout(vLyout);
}

void middleLeftStackWidget2::InitConnect() {
}
