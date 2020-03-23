#include "stackcontentitem.h"
#include <QBoxLayout>
#include <QGridLayout>
#include <QScrollArea>
#include <QSCrollbar>
#include <QPushButton>
#include <QPainter>

stackContentItem::stackContentItem(const QString& name, QWidget *parent /*= nullptr*/)
  : QPushButton(parent)
  , lbl_play_list_(nullptr) {
    setCheckable(true);
    play_list_name_ = name;

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
    connect(btn_menu, SIGNAL(clicked(bool)), this, SLOT(onTrackMenu()));

    hlyout->addWidget(lbl_play_list_);
    hlyout->setSpacing(0);
    hlyout->addSpacerItem(new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Fixed));
    hlyout->addWidget(btn_menu);
    hlyout->setContentsMargins(18, 0, 14, 0);
    top_button->setLayout(hlyout);

    initMenu();


    vlyout->addWidget(top_button, 0, Qt::AlignTop);
    vlyout->setSpacing(0);
    vlyout->setContentsMargins(0, 0, 0, 0);
    setLayout(vlyout);
}

void stackContentItem::InitConnect() {
}

void stackContentItem::initMenu() {
    m_menu.setStyleSheet(QString("QMenu{background-color: white;border: 1px solid rgb(214,214,214);}"
        "QMenu::item{height: 28px;padding: 0px 20px 0px 40px;font-size : 12px;color: rgb(102, 102, 102);font-family: %1;}"
        "QMenu::item:focus{padding: -1;}"
        "QMenu::item:!enabled{color:rgb(150,150,150);}"
        "QMenu::item:selected{color: white;background-color: rgb(22, 154, 243);}"
        "QMenu::icon{position: absolute;left: 12px;}"
        "QMenu::separator{height:1px;background: rgb(209,209,209);margin:4px 0px 4px 0px;}").arg(QString::fromLocal8Bit("微软雅黑")));

    m_menu.addAction(new QAction(QString::fromLocal8Bit("新建列表")));
    m_menu.addSeparator();
    m_menu.addAction(new QAction(QString::fromLocal8Bit("添加歌曲")));
    m_menu.addAction(new QAction(QString::fromLocal8Bit("稍后播")));
    m_menu.addAction(new QAction(QString::fromLocal8Bit("添加到播放列表")));
    m_menu.addAction(new QAction(QString::fromLocal8Bit("全部发送到移动设备")));
    m_menu.addAction(new QAction(QString::fromLocal8Bit("下载本列表全部歌曲")));
    m_menu.addAction(new QAction(QString::fromLocal8Bit("排序")));
    m_menu.addAction(new QAction(QString::fromLocal8Bit("匹配MV")));
    m_menu.addAction(new QAction(QString::fromLocal8Bit("收藏整个列表")));
    m_menu.addSeparator();
    m_menu.addAction(new QAction(QString::fromLocal8Bit("清空列表")));
    m_menu.addAction(new QAction(QString::fromLocal8Bit("删除列表")));
    m_menu.addAction(new QAction(QString::fromLocal8Bit("重命名")));

    m_menu.setContentsMargins(4, 10, 3, 10);
}

void stackContentItem::setEnabledMenuItem(bool isSetting/* = false*/) {
    auto action = m_menu.actions().value(12);
    if (action) action->setEnabled(isSetting);

    action = m_menu.actions().value(13);
    if (action) action->setEnabled(isSetting);
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

void stackContentItem::onTrackMenu() {
    m_menu.exec(QCursor::pos());
}
