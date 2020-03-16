#include "midleftwidget.h"
#include <QBoxLayout>
#include <QRadioButton>
#include <QPushButton>
#include <QPainter>

midLeftWidget::midLeftWidget(QWidget *parent /*= nullptr*/) 
 : baseWidget(parent)
 , option_groups_(this){
    InitUi();
    InitConnect();
    initAnimation();
}

void midLeftWidget::InitUi() {
    setMinimumWidth(310);
    setMaximumWidth(380);

    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);

    QVBoxLayout *vlyout = new QVBoxLayout;
    if (!vlyout) return;

    QHBoxLayout *hlyout = new QHBoxLayout;

    auto option_1 = new QPushButton;
    option_1->setCheckable(true);
    option_1->setChecked(true);
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

    option_groups_.addButton(option_1, 0);
    option_groups_.addButton(option_2, 1);
    option_groups_.addButton(option_3, 2);
    option_groups_.addButton(option_4, 3);
    option_groups_.addButton(option_5, 4);
    hlyout->addWidget(option_1);
    hlyout->addWidget(option_2);
    hlyout->addWidget(option_3);
    hlyout->addWidget(option_4);
    hlyout->addWidget(option_5);

    option_groups_.setExclusive(true);

    hlyout->setContentsMargins(0, 0, 0, 0);
    hlyout->setSpacing(0);



    vlyout->addLayout(hlyout);
    vlyout->addStretch();
    vlyout->setSpacing(0);
    vlyout->setContentsMargins(0, 0, 0, 0);
    setLayout(vlyout);
}

void midLeftWidget::InitConnect() {
    opt_pic_ = QPixmap(":/image/middlewidget/indicator.png");
}

void midLeftWidget::initAnimation() {

}

void midLeftWidget::paintEvent(QPaintEvent *e) {
    baseWidget::paintEvent(e);

    QPainter painter(this);
    painter.setPen(Qt::transparent);
    painter.setBrush(QColor(255, 255, 255, 100));//Ë¢Í¸Ã÷ÇøÓò
    painter.drawRect(-1, -1, width(), height() + 1);
    painter.setPen(QColor(230, 230, 230));

    painter.drawLine(width() - 1, 0, width() - 1, height());//vertical line

    auto option = qobject_cast<QPushButton *>(option_groups_.checkedButton());
    if (!option || opt_pic_.isNull()) return;

    auto x = option->pos().x() + (option->width() - opt_pic_.width()) / 2;
    auto y = option->pos().y() + option->height() - opt_pic_.height();

    painter.drawLine(0, option->height() - 1, x, option->height() - 1);
    painter.drawLine(x + opt_pic_.width(), option->height() - 1, width() - 1, option->height() - 1);

    painter.drawPixmap(x, y, opt_pic_);

}
