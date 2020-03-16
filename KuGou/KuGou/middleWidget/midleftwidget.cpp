#include "midleftwidget.h"
#include <QButtonGroup>
#include <QBoxLayout>
#include <QRadioButton>
#include <QPushButton>

midLeftWidget::midLeftWidget(QWidget *parent /*= nullptr*/) 
 : baseWidget(parent){
    InitUi();
    InitConnect();

}

void midLeftWidget::InitUi() {
    setMinimumWidth(310);
    setMaximumWidth(380);

    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);

    QVBoxLayout *vlyout = new QVBoxLayout;
    if (!vlyout) return;

    QHBoxLayout *hlyout = new QHBoxLayout;
    QButtonGroup* option_group = new QButtonGroup(this);

    auto option_1 = new QPushButton;
    option_1->setCheckable(true);
    option_1->setFixedHeight(40);
    option_1->setCursor(QCursor(Qt::PointingHandCursor));
    option_1->setStyleSheet("QPushButton{border:none;background-image:url(:/image/middlewidget/btn_music (1).png);background-repeat:repeat-no;background-position:Center;}"
        "QPushButton::hover{background-image:url(:/image/middlewidget/btn_music (2).png) no-repeat center;background-repeat:repeat-no;background-position:Center;}"
        "QPushButton::pressed{background-image:url(:/image/middlewidget/btn_music (3).png) no-repeat center;background-repeat:repeat-no;background-position:Center;}"
        "QPushButton::checked{background-image:url(:/image/middlewidget/btn_music (3).png) no-repeat center;background-repeat:repeat-no;background-position:Center;}");

    auto option_2 = new QPushButton;
    option_2->setCheckable(true);
    option_2->setFixedHeight(40);
    option_2->setCursor(QCursor(Qt::PointingHandCursor));
    option_2->setStyleSheet("QPushButton{border:none;background-image:url(:/image/middlewidget/btn_cloud (1).png);background-repeat:repeat-no;background-position:Center;}"
        "QPushButton::hover{background-image:url(:/image/middlewidget/btn_cloud (2).png) no-repeat center;background-repeat:repeat-no;background-position:Center;}"
        "QPushButton::pressed{background-image:url(:/image/middlewidget/btn_cloud (3).png) no-repeat center;background-repeat:repeat-no;background-position:Center;}"
        "QPushButton::checked{background-image:url(:/image/middlewidget/btn_cloud (3).png) no-repeat center;background-repeat:repeat-no;background-position:Center;}");

    auto option_3 = new QPushButton;
    option_3->setCheckable(true);
    option_3->setFixedHeight(40);
    option_3->setCursor(QCursor(Qt::PointingHandCursor));
    option_3->setStyleSheet("QPushButton{border:none;background-image:url(:/image/middlewidget/btn_radio (1).png);background-repeat:repeat-no;background-position:Center;}"
        "QPushButton::hover{background-image:url(:/image/middlewidget/btn_radio (2).png) no-repeat center;background-repeat:repeat-no;background-position:Center;}"
        "QPushButton::pressed{background-image:url(:/image/middlewidget/btn_radio (3).png) no-repeat center;background-repeat:repeat-no;background-position:Center;}"
        "QPushButton::checked{background-image:url(:/image/middlewidget/btn_radio (3).png) no-repeat center;background-repeat:repeat-no;background-position:Center;}");

    auto option_4 = new QPushButton;
    option_4->setCheckable(true);
    option_4->setFixedHeight(40);
    option_4->setCursor(QCursor(Qt::PointingHandCursor));
    option_4->setStyleSheet("QPushButton{border:none;background-image:url(:/image/middlewidget/btn_phone (1).png);background-repeat:repeat-no;background-position:Center;}"
        "QPushButton::hover{background-image:url(:/image/middlewidget/btn_phone (2).png) no-repeat center;background-repeat:repeat-no;background-position:Center;}"
        "QPushButton::pressed{background-image:url(:/image/middlewidget/btn_phone (3).png) no-repeat center;background-repeat:repeat-no;background-position:Center;}"
        "QPushButton::checked{background-image:url(:/image/middlewidget/btn_phone (3).png) no-repeat center;background-repeat:repeat-no;background-position:Center;}");

    auto option_5 = new QPushButton;
    option_5->setCheckable(true);
    option_5->setFixedHeight(40);
    option_5->setCursor(QCursor(Qt::PointingHandCursor));
    option_5->setStyleSheet("QPushButton{border:none;background-image:url(:/image/middlewidget/btn_download (1).png);background-repeat:repeat-no;background-position:Center;}"
        "QPushButton::hover{background-image:url(:/image/middlewidget/btn_download (2).png) no-repeat center;background-repeat:repeat-no;background-position:Center;}"
        "QPushButton::pressed{background-image:url(:/image/middlewidget/btn_download (3).png) no-repeat center;background-repeat:repeat-no;background-position:Center;}"
        "QPushButton::checked{background-image:url(:/image/middlewidget/btn_download (3).png) no-repeat center;background-repeat:repeat-no;background-position:Center;}");

    option_group->addButton(option_1, 0);
    option_group->addButton(option_2, 1);
    option_group->addButton(option_3, 2);
    option_group->addButton(option_4, 3);
    option_group->addButton(option_5, 4);
    hlyout->addWidget(option_1);
    hlyout->addWidget(option_2);
    hlyout->addWidget(option_3);
    hlyout->addWidget(option_4);
    hlyout->addWidget(option_5);

    option_group->setExclusive(true);

    hlyout->setContentsMargins(0, 0, 0, 0);
    hlyout->setSpacing(0);



    vlyout->addLayout(hlyout);
    vlyout->addStretch();
    vlyout->setSpacing(0);
    vlyout->setContentsMargins(0, 0, 0, 0);
    setLayout(vlyout);
}

void midLeftWidget::InitConnect() {

}
