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
    , content_widget_(nullptr)
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

    content_widget_ = new baseWidget(scrollArea);
    scrollArea->setWidget(content_widget_);
    scrollArea->setWidgetResizable(true);

    content_layout_ = new QVBoxLayout(content_widget_);
    content_item_groups_.setParent(content_widget_);

    default_item_ = new stackContentItem(QString::fromLocal8Bit("默认列表"), content_widget_);
    content_item_groups_.addButton(default_item_);
    content_layout_->addWidget(default_item_);
    default_item_->setEnabledMenuItem(false);
    connect(default_item_, SIGNAL(addContentItem()), this, SLOT(addContentItem()));
    connect(default_item_, SIGNAL(needSetLayout()), this, SLOT(setAutoLayout()));
    default_item_->setExpand(true);

    love_item_ = new stackContentItem(QString::fromLocal8Bit("我的最爱"), content_widget_);
    content_item_groups_.addButton(love_item_);
    content_layout_->addWidget(love_item_);
    love_item_->setEnabledMenuItem(false);
    connect(love_item_, SIGNAL(addContentItem()), this, SLOT(addContentItem()));
    connect(love_item_, SIGNAL(needSetLayout()), this, SLOT(setAutoLayout()));
    
    setAutoLayout();

    content_item_groups_.setExclusive(true);

    content_layout_->setAlignment(Qt::AlignTop);
    content_layout_->setSpacing(0);
    content_layout_->setContentsMargins(0, 0, 0, 0);
    content_widget_->setLayout(content_layout_);

    vlyout->addWidget(scrollArea);
    vlyout->setSpacing(0);
    vlyout->setContentsMargins(0, 0, 0, 0);
    setLayout(vlyout);
}

void middleLeftStackWidget1::InitConnect() {

}

void middleLeftStackWidget1::addContentItem() {
    if (!content_layout_ || !content_widget_) return;

    auto item = new stackContentItem(QString::fromLocal8Bit("新建列表%1").arg(content_item_id_ + 1), content_widget_);
    content_layout_->addWidget(item);
    content_item_groups_.addButton(item, content_item_id_++);
    connect(item, SIGNAL(addContentItem()), this, SLOT(addContentItem()));
    connect(item, SIGNAL(needSetLayout()), this, SLOT(setAutoLayout()));
    connect(item, SIGNAL(delContentItem(stackContentItem*)), this, SLOT(delContentItem(stackContentItem*)));
    item->setExpand(true);

    // 刷新区域高度，这样避免滚动条出来之后，每次添加item元素界面都会抖动
    setAutoLayout();
}

void middleLeftStackWidget1::delContentItem(stackContentItem* item) {
    if (!content_layout_) return;
    content_layout_->removeWidget(item);

    setAutoLayout();
}

void middleLeftStackWidget1::setAutoLayout() {
    if (!content_layout_ || !content_widget_) return;

    int height = 0;
    int count = content_layout_->count();

    for (int i = 0; i < count; i++) {
        if (content_layout_->itemAt(i) && content_layout_->itemAt(i)->widget()) {
            height += content_layout_->itemAt(i)->widget()->height();
        }
    }

    content_widget_->setMinimumHeight(height);
}

void middleLeftStackWidget1::resizeEvent(QResizeEvent *e) {
    baseWidget::resizeEvent(e);

    if (!content_widget_) return;
    content_widget_->setFixedWidth(width());
}