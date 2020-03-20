#include "skincontentwidget.h"
#include <QGridLayout>
#include <QLabel>

skinContentWidget::skinContentWidget(QWidget *parent /*= nullptr*/)
    : baseWidget(parent) {
    InitUi();
    InitConnect();
}

void skinContentWidget::InitUi() {
    setStyleSheet("QWidget{background: white;}");

    QGridLayout *gyout = new QGridLayout;
    if (!gyout) return;

    auto item = createSkinContentItem();

    gyout->addWidget(item, 0, 0);

    gyout->setHorizontalSpacing(4);
    gyout->setVerticalSpacing(4);
    gyout->setContentsMargins(20, 0, 20, 4);

    setLayout(gyout);
}

void skinContentWidget::InitConnect() {

}

QPushButton* skinContentWidget::createSkinContentItem() {
    skinContentItem* item = new skinContentItem(this);
    if (!item) return nullptr;

    item->setFixedSize(125, 80);
    item->setStyleSheet(QString::fromLocal8Bit("QPushButton{border-image:url(:/image/skin/默认.jpg);}"));
    item->setCursor(Qt::PointingHandCursor);
    item->setCheckable(true);

    QWidget *select_widget = new QWidget(item);
    select_widget->setGeometry(105, 60, 17, 17);
    select_widget->setObjectName("select_widget");
    select_widget->setStyleSheet("QWidget{background:transparent;border-image:url(:/image/skinwidget/selected.png)}");

    baseWidget* item_widget = new baseWidget(item);
    item_widget->setStyleSheet("QWidget{background:rgb(55,55,55,100);}");
    item_widget->setGeometry(0, 0, 125, 80);
    item_widget->setObjectName("item_widget");


    QVBoxLayout *vlyout = new QVBoxLayout(item_widget);
    if (!vlyout) return item;

    QString labl_sheet(QString::fromLocal8Bit("QLabel{background:transparent;font-family:宋体;font-size:13px;color:white;}"));

    QLabel* pic_name = new QLabel(QString::fromLocal8Bit("默认"), item_widget);
    pic_name->setStyleSheet(labl_sheet);
    pic_name->adjustSize();
    pic_name->setAlignment(Qt::AlignHCenter);

    QLabel* author_name = new QLabel(QString::fromLocal8Bit("作者：严涛"), item_widget);
    author_name->setStyleSheet(labl_sheet);
    author_name->setFixedHeight(13);
    author_name->adjustSize();
    author_name->setAlignment(Qt::AlignHCenter);

    QLabel* used_count = new QLabel(QString::fromLocal8Bit("250人已使用"), item_widget);
    used_count->setStyleSheet(labl_sheet);
    used_count->adjustSize();
    used_count->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);

    vlyout->addWidget(pic_name);
    vlyout->addSpacing(1);
    vlyout->addWidget(author_name);
    vlyout->addSpacing(1);
    vlyout->addWidget(used_count);
    vlyout->setSpacing(0);
    vlyout->setContentsMargins(0, 21, 0, 18);
    item_widget->setLayout(vlyout);

    item_widget->hide();
    select_widget->hide();

    connect(item, SIGNAL(enterItem(bool)), item_widget, SLOT(setVisible(bool)));
    connect(item, SIGNAL(toggled(bool)), select_widget, SLOT(setVisible(bool)));

    return item;
}
