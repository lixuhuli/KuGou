#include "middleleftstackwidget1.h"
#include <QBoxLayout>
#include <QGridLayout>
#include <QScrollArea>
#include <QSCrollbar>
#include <QPushButton>
#include "stackcontentitem.h"

middleLeftStackWidget1::middleLeftStackWidget1(QWidget *parent /*= nullptr*/)
    : baseWidget(parent)
    , content_layout_(nullptr) 
    , content_item_id_(0)
    , content_item_groups_(this) {
    InitUi();
    InitConnect();
}

void middleLeftStackWidget1::InitUi() {
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QVBoxLayout *vlyout = new QVBoxLayout;
    if (!vlyout) return;

    QScrollArea* scrollArea = new QScrollArea(this);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setFrameShadow(QFrame::Plain);//设置平的样式
    scrollArea->setFrameShape(QFrame::NoFrame);//设置无边样式
    scrollArea->verticalScrollBar()->setStyleSheet("QScrollBar{background:transparent; width:10px; padding-right: 2px;}"
        "QScrollBar::handle{background:rgb(180,180,180,150);border-radius:4px;}"
        "QScrollBar::handle:hover{background: rgb(150,150,150,150);}"
        "QScrollBar::add-line:vertical{border:1px rgb(230,230,230,150);height: 1px;}"
        "QScrollBar::sub-line:vertical{border:1px rgb(230,230,230,150);height: 1px;}"
        "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {background:transparent;}");

    baseWidget* content_widget = new baseWidget(scrollArea);
    scrollArea->setWidget(content_widget);
    scrollArea->setWidgetResizable(true);

    content_layout_ = new QGridLayout(content_widget);
    content_item_groups_.setParent(content_widget);

    default_item_ = new stackContentItem(QString::fromLocal8Bit("默认列表"), content_widget);
    content_item_groups_.addButton(default_item_);
    content_layout_->addWidget(default_item_);
    default_item_->setEnabledMenuItem(false);

    love_item_ = new stackContentItem(QString::fromLocal8Bit("我的最爱"), content_widget);
    content_item_groups_.addButton(love_item_);
    content_layout_->addWidget(love_item_);
    love_item_->setEnabledMenuItem(false);
    
    auto item = new stackContentItem(QString::fromLocal8Bit("新建列表%1").arg(content_item_id_ + 1), content_widget);
    content_layout_->addWidget(item);
    content_item_groups_.addButton(item, content_item_id_++);

    auto item2 = new stackContentItem(QString::fromLocal8Bit("新建列表%1").arg(content_item_id_ + 1), content_widget);
    content_layout_->addWidget(item2);
    content_item_groups_.addButton(item2, content_item_id_++);

    content_item_groups_.setExclusive(true);

    content_layout_->setAlignment(Qt::AlignTop);
    content_layout_->setHorizontalSpacing(0);
    content_layout_->setVerticalSpacing(0);
    content_layout_->setContentsMargins(0, 0, 0, 0);
    content_widget->setLayout(content_layout_);

    vlyout->addWidget(scrollArea);
    vlyout->setSpacing(0);
    vlyout->setContentsMargins(0, 0, 0, 0);
    setLayout(vlyout);
}

void middleLeftStackWidget1::InitConnect() {

}
