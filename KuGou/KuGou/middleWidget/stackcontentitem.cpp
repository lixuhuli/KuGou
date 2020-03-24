#include "stackcontentitem.h"
#include <QBoxLayout>
#include <QGridLayout>
#include <QScrollArea>
#include <QSCrollbar>
#include <QPushButton>
#include <QPainter>
#include "baseWnd/basewidget.h"

stackContentItem::stackContentItem(const QString& name, QWidget *parent /*= nullptr*/)
  : QPushButton(parent)
  , top_button_(nullptr)
  , leave_widget_(nullptr)
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

    top_button_ = new QPushButton();
    top_button_->setObjectName("top_button");
    top_button_->setCursor(Qt::PointingHandCursor);
    top_button_->setFixedHeight(40);
    top_button_->setCheckable(true);
    top_button_->setStyleSheet("#top_button{border:NULL;background-image:url(:/image/middlewidget/indicator_top (1).png);background-repeat:repeat-no;background-position:left;}"
        "#top_button::pressed{background-image:url(:/image/middlewidget/indicator_top (1).png);background-repeat:repeat-no;background-position:left;}"
        "#top_button::checked{background-image:url(:/image/middlewidget/indicator_down (1).png);background-repeat:repeat-no;background-position:left;}");
    connect(this, SIGNAL(toggled(bool)), this, SLOT(onContentSelected(bool)));
    connect(top_button_, SIGNAL(toggled(bool)), this, SLOT(onTopButtonSelected(bool)));

    QHBoxLayout *hlyout = new QHBoxLayout();

    lbl_play_list_ = new QLabel(play_list_name_, top_button_);
    lbl_play_list_->setStyleSheet(QString::fromLocal8Bit("QLabel{color:rgb(38,38,38);font: 14px ����;}"));

    QPushButton* btn_menu = new QPushButton(top_button_);
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
    top_button_->setLayout(hlyout);

    initMenu();


    /////////////////////////////////////////////////////////////////////////////////////////
    leave_widget_ = new baseWidget(this);
    leave_widget_->setFixedHeight(80);

    QVBoxLayout *leave_vlyout = new QVBoxLayout(this);

    QHBoxLayout *local_music_yout = new QHBoxLayout();
    QPushButton* add_local_music = new QPushButton();
    add_local_music->setFixedHeight(16);
    add_local_music->setCursor(Qt::PointingHandCursor);
    add_local_music->adjustSize();
    add_local_music->setText(QString::fromLocal8Bit("��ӱ��ظ���"));
    add_local_music->setStyleSheet("QPushButton{border:NULL;padding-left:25;background-image:url(:/image/middlewidget/lab_add.png);background-repeat:repeat-no;background-position:left top;color:rgb(58,58,58);text-decoration:underline;}");

    local_music_yout->addStretch(20);
    local_music_yout->addWidget(add_local_music);
    local_music_yout->addStretch(20);
    local_music_yout->setSpacing(0);
    local_music_yout->setContentsMargins(0, 0, 0, 0);

    

    QHBoxLayout *local_dir_yout = new QHBoxLayout();
    QPushButton* add_local_dir = new QPushButton();
    add_local_dir->setFixedHeight(16);
    add_local_dir->setCursor(Qt::PointingHandCursor);
    add_local_dir->adjustSize();
    add_local_dir->setText(QString::fromLocal8Bit("��ӱ��ظ����ļ���"));
    add_local_dir->setStyleSheet("QPushButton{border:NULL;padding-left:25;background-image:url(:/image/middlewidget/lab_addfolder.png);background-repeat:repeat-no;background-position:left top;color:rgb(58,58,58);text-decoration:underline;}");

    local_dir_yout->addStretch(20);
    local_dir_yout->addWidget(add_local_dir);
    local_dir_yout->addStretch(20);
    local_dir_yout->setSpacing(0);
    local_dir_yout->setContentsMargins(0, 0, 0, 0);

    leave_vlyout->addLayout(local_music_yout);
    leave_vlyout->addLayout(local_dir_yout);
    leave_vlyout->setSpacing(11);
    leave_vlyout->setContentsMargins(0, 0, 0, 0);
    leave_widget_->setLayout(leave_vlyout);
    leave_widget_->hide();

    vlyout->addWidget(top_button_);
    vlyout->addWidget(leave_widget_);
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
        "QMenu::separator{height:1px;background: rgb(209,209,209);margin:4px 0px 4px 0px;}").arg(QString::fromLocal8Bit("΢���ź�")));

    auto add_item = new QAction(QString::fromLocal8Bit("�½��б�"));

    m_menu.addAction(add_item);
    m_menu.addSeparator();
    m_menu.addAction(new QAction(QString::fromLocal8Bit("��Ӹ���")));
    m_menu.addAction(new QAction(QString::fromLocal8Bit("�Ժ�")));
    m_menu.addAction(new QAction(QString::fromLocal8Bit("��ӵ������б�")));
    m_menu.addAction(new QAction(QString::fromLocal8Bit("ȫ�����͵��ƶ��豸")));
    m_menu.addAction(new QAction(QString::fromLocal8Bit("���ر��б�ȫ������")));
    m_menu.addAction(new QAction(QString::fromLocal8Bit("����")));
    m_menu.addAction(new QAction(QString::fromLocal8Bit("ƥ��MV")));
    m_menu.addAction(new QAction(QString::fromLocal8Bit("�ղ������б�")));
    m_menu.addSeparator();
    m_menu.addAction(new QAction(QString::fromLocal8Bit("����б�")));
    m_menu.addAction(new QAction(QString::fromLocal8Bit("ɾ���б�")));
    m_menu.addAction(new QAction(QString::fromLocal8Bit("������")));

    QMenu* sub_menu = new QMenu(QString::fromLocal8Bit("�Ӳ˵�����"), &m_menu);
    m_menu.addSeparator();
    m_menu.addMenu(sub_menu);
    sub_menu->addAction(new QAction(QString::fromLocal8Bit("������չ1")));
    sub_menu->addAction(new QAction(QString::fromLocal8Bit("������չ2")));

    connect(add_item, SIGNAL(triggered(bool)), this, SIGNAL(addContentItem()));

    m_menu.setContentsMargins(4, 10, 3, 10);
}

void stackContentItem::setEnabledMenuItem(bool isSetting/* = false*/) {
    auto action = m_menu.actions().value(12);
    if (action) action->setEnabled(isSetting);

    action = m_menu.actions().value(13);
    if (action) action->setEnabled(isSetting);
}

void stackContentItem::setExpand(bool expand) {
    if (!top_button_) return;
    top_button_->setChecked(expand);
}

void stackContentItem::paintEvent(QPaintEvent *e) {
    QPushButton::paintEvent(e);

    QPainter p(this);
    p.setPen(QColor(230, 230, 230));
    p.drawLine(0, height() - 1, width() - 1, height() - 1);
}

void stackContentItem::onContentSelected(bool checked) {
    if (checked) return;

    if (!top_button_) return;
    top_button_->setChecked(false);
}

void stackContentItem::onTopButtonSelected(bool checked) {
    if (checked) {
        setFixedHeight(120);
        setChecked(checked);
        if (leave_widget_) leave_widget_->show();
    }
    else {
        setFixedHeight(40);
        if (leave_widget_) leave_widget_->hide();
    }

    needSetLayout();
}

void stackContentItem::onTrackMenu() {
    m_menu.exec(QCursor::pos());
}
