#include "stackcontentitem.h"
#include <QBoxLayout>
#include <QGridLayout>
#include <QScrollArea>
#include <QSCrollbar>
#include <QPushButton>
#include <QPainter>

stackContentItem::stackContentItem(int& id, QWidget *parent /*= nullptr*/)
  : QPushButton(parent)
  , lbl_play_list_(nullptr) {
    setCheckable(true);

    play_list_name_ = QString::fromLocal8Bit("新建列表%1").arg(id + 1);
    id++;

    InitUi();
    InitConnect();
}

void stackContentItem::InitUi() {
    setFixedHeight(40);

    //setFixedWidth(310);
    //setStyleSheet("QPushButton{border:1px solid red;}");

    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    QVBoxLayout *vlyout = new QVBoxLayout(this);
    if (!vlyout) return;

    QPushButton* top_button = new QPushButton();
    top_button->setObjectName("top_button");
    top_button->setCursor(Qt::PointingHandCursor);
    top_button->setFixedHeight(40);
    top_button->setCheckable(true);
    top_button->setStyleSheet("#top_button{border:NULL;background-image:url(:/image/middlewidget/indicator_top (1).png);background-repeat:repeat-no;background-position:left;}"
        "#top_button::pressed{background-image:url(:/image/middlewidget/indicator_top (1).png);background-repeat:repeat-no;background-position:left;}"
        "#top_button::checked{background-image:url(:/image/middlewidget/indicator_down (1).png);background-repeat:repeat-no;background-position:left;}");
    connect(this, SIGNAL(toggled(bool)), this, SLOT(onContentSelected(bool)));
    connect(top_button, SIGNAL(toggled(bool)), this, SLOT(onTopButtonSelected(bool)));

    QHBoxLayout *hlyout = new QHBoxLayout();

    lbl_play_list_ = new QLabel(play_list_name_, top_button);
    lbl_play_list_->setStyleSheet(QString::fromLocal8Bit("QLabel{color:rgb(38,38,38);font: 14px 黑体;}"));

    QPushButton* btn_menu = new QPushButton(top_button);
    btn_menu->setFixedSize(16, 16);
    btn_menu->setCursor(Qt::PointingHandCursor);
    btn_menu->setStyleSheet("QPushButton{border-image:url(:/image/middlewidget/indicator_menu (1).png);}"
        "QPushButton:hover{border-image:url(:/image/middlewidget/indicator_menu (2).png);}"
        "QPushButton:pressed{border-image:url(:/image/middlewidget/indicator_menu (3).png);}");

    hlyout->addWidget(lbl_play_list_);
    hlyout->setSpacing(0);
    hlyout->addSpacerItem(new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Fixed));
    hlyout->addWidget(btn_menu);
    hlyout->setContentsMargins(18, 0, 14, 0);
    top_button->setLayout(hlyout);

    vlyout->addWidget(top_button, 0, Qt::AlignTop);
    vlyout->setSpacing(0);
    vlyout->setContentsMargins(0, 0, 0, 0);
    setLayout(vlyout);
}

void stackContentItem::InitConnect() {

}

void stackContentItem::paintEvent(QPaintEvent *e) {
    QPushButton::paintEvent(e);

    QPainter p(this);
    p.setPen(QColor(230, 230, 230));
    p.drawLine(0, height() - 1, width() - 1, height() - 1);
}

void stackContentItem::onContentSelected(bool checked) {
    if (checked) return;

    auto top_button = findChild<QPushButton*>("top_button");
    if (!top_button) return;

    top_button->setChecked(false);
}

void stackContentItem::onTopButtonSelected(bool checked) {
    setFixedHeight(checked ? 120 : 40);
    if (checked) setChecked(checked);
}
