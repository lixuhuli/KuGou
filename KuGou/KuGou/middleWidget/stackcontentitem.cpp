#include "stackcontentitem.h"
#include <QBoxLayout>
#include <QGridLayout>
#include <QScrollArea>
#include <QSCrollbar>
#include <QPushButton>
#include <QPainter>

stackContentItem::stackContentItem(QWidget *parent /*= nullptr*/) 
  : QPushButton(parent) {
    setCheckable(true);
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
    top_button->setStyleSheet("QPushButton{border:NULL;background-image:url(:/image/middlewidget/indicator_top (1).png);background-repeat:repeat-no;background-position:left;}"
        "QPushButton::pressed{background-image:url(:/image/middlewidget/indicator_top (1).png);background-repeat:repeat-no;background-position:left;}"
        "QPushButton::checked{background-image:url(:/image/middlewidget/indicator_down (1).png);background-repeat:repeat-no;background-position:left;}");
    connect(this, SIGNAL(toggled(bool)), this, SLOT(onContentSelected(bool)));
    connect(top_button, SIGNAL(toggled(bool)), this, SLOT(onTopButtonSelected(bool)));

    QHBoxLayout *hlyout = new QHBoxLayout();


    hlyout->setSpacing(0);
    hlyout->setContentsMargins(0, 0, 0, 0);
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
