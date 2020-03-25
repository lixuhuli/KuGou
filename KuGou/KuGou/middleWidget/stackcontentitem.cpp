#include "stackcontentitem.h"
#include <QBoxLayout>
#include <QGridLayout>
#include <QScrollArea>
#include <QSCrollbar>
#include <QPushButton>
#include <QPainter>
#include "baseWnd/basewidget.h"
#include <QMouseEvent>
#include <QDrag>
#include <QMimeData>

stackContentItem::stackContentItem(const QString& name, QWidget *parent /*= nullptr*/)
  : QPushButton(parent)
  , top_button_(nullptr)
  , leave_widget_(nullptr)
  , lbl_play_list_(nullptr)
  , can_drag_move_(true)
  , draw_mode_(unDraw)
  , left_btn_pressed_(false)
  , pos_before_drag_(0, 0) {
    setCheckable(true);
    play_list_name_ = name;

    InitUi();
    InitConnect();
}

void stackContentItem::InitUi() {
    setFixedHeight(40);

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
    top_button_->setAcceptDrops(true);
    top_button_->installEventFilter(this);

    QHBoxLayout *hlyout = new QHBoxLayout();

    lbl_play_list_ = new QLabel(play_list_name_, top_button_);
    lbl_play_list_->setStyleSheet(QString::fromLocal8Bit("QLabel{color:rgb(38,38,38);font: 14px 黑体;}"));

    QPushButton* btn_menu = new QPushButton(top_button_);
    btn_menu->setFixedSize(40, 40);
    btn_menu->setCursor(Qt::PointingHandCursor);
    btn_menu->setStyleSheet("QPushButton{border-image:url(:/image/middlewidget/indicator_menu (1).png);margin:12 14 12 10;}"
        "QPushButton:hover{border-image:url(:/image/middlewidget/indicator_menu (2).png);}"
        "QPushButton:pressed{border-image:url(:/image/middlewidget/indicator_menu (3).png);}");
    connect(btn_menu, SIGNAL(clicked(bool)), this, SLOT(onTrackMenu()));

    hlyout->addWidget(lbl_play_list_);
    hlyout->setSpacing(0);
    hlyout->addSpacerItem(new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Fixed));
    hlyout->addWidget(btn_menu);
    hlyout->setContentsMargins(18, 0, 0, 0);
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
    add_local_music->setText(QString::fromLocal8Bit("添加本地歌曲"));
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
    add_local_dir->setText(QString::fromLocal8Bit("添加本地歌曲文件夹"));
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
        "QMenu::separator{height:1px;background: rgb(209,209,209);margin:4px 0px 4px 0px;}").arg(QString::fromLocal8Bit("微软雅黑")));

    auto add_item = new QAction(QString::fromLocal8Bit("新建列表"));
    auto del_item = new QAction(QString::fromLocal8Bit("删除列表"));

    m_menu.addAction(add_item);
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
    m_menu.addAction(del_item);
    m_menu.addAction(new QAction(QString::fromLocal8Bit("重命名")));

    QMenu* sub_menu = new QMenu(QString::fromLocal8Bit("子菜单功能"), &m_menu);
    m_menu.addSeparator();
    m_menu.addMenu(sub_menu);
    sub_menu->addAction(new QAction(QString::fromLocal8Bit("子类扩展1")));
    sub_menu->addAction(new QAction(QString::fromLocal8Bit("子类扩展2")));

    connect(add_item, SIGNAL(triggered(bool)), this, SIGNAL(addContentItem()));
    connect(del_item, SIGNAL(triggered(bool)), this, SLOT(onDelContentItem()));

    m_menu.setContentsMargins(4, 10, 3, 10);
}

void stackContentItem::setEnabledMenuItem(bool isSetting/* = false*/) {
    auto action = m_menu.actions().value(12);
    if (action) action->setEnabled(isSetting);

    action = m_menu.actions().value(13);
    if (action) action->setEnabled(isSetting);

    can_drag_move_ = (isSetting == true);
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

bool stackContentItem::eventFilter(QObject *o, QEvent *e) {
    if (o == top_button_) {
        if (e->type() == QEvent::MouseButtonPress) {
            auto event = (QMouseEvent*)e;
            if (event && event->button() == Qt::LeftButton) {
                pos_before_drag_ = event->pos();
                left_btn_pressed_ = true;
            }
            return false;
        }
        else if (e->type() == QEvent::MouseMove) {
            auto event = (QMouseEvent*)e;
            if (event && left_btn_pressed_) {
                QRect re(pos_before_drag_.x() - 2, pos_before_drag_.y() - 2, pos_before_drag_.x() + 2, pos_before_drag_.y() + 2);
                if (!re.contains(event->pos()) && can_drag_move_) {
                    QDrag *drag = new QDrag(top_button_); // 自动释放
                    if (!drag) return false;

                    QMimeData *data = new QMimeData;
                    drag->setMimeData(data);

                    QPixmap pixmap = this->grab(top_button_->rect());
                    drag->setHotSpot(QPoint(0, top_button_->height() / 2));
                    drag->setPixmap(pixmap);
                    drag->exec(Qt::MoveAction);

                    drag->deleteLater();
                    data->deleteLater();
                }

            }

            return false;
        }
        else if (e->type() == QEvent::MouseButtonRelease) {
            left_btn_pressed_ = false;

            auto event = (QMouseEvent*)e;
            if (event && event->button() == Qt::RightButton) {
                m_menu.exec(QCursor::pos());
            }

            return false;
        }
        else if (e->type() == QEvent::DragEnter) {
            auto event = (QDragEnterEvent*)e;
            if (event) {
                if (can_drag_move_) {
                    event->setDropAction(Qt::MoveAction);
                    event->accept();
                }
                else event->ignore();
            }
        }
        else if (e->type() == QEvent::Drop) {
            auto event = (QDropEvent*)e;
            if (event) {
                draw_mode_ = unDraw;
                top_button_->update();
            }
        }
        else if (e->type() == QEvent::DragMove) {
            auto event = (QDragMoveEvent*)e;
            if (event) {
                if (event->pos().y() < top_button_->height() / 2) {
                    draw_mode_ = drawTop;
                    update();
                } 
                else {
                    draw_mode_ = drawbottom;
                    update();
                }
            }
        }
        else if (e->type() == QEvent::DragLeave) {
            auto event = (QDragLeaveEvent*)e;
            if (event) {
                draw_mode_ = unDraw;
                top_button_->update();
            }
        }
        else if (e->type() == QEvent::Paint) {
            auto event = (QPaintEvent*)e;
            if (!event || draw_mode_ == unDraw) return false;

            QPainter p(top_button_);
            if (draw_mode_ == drawTop) p.drawLine(0, 0, top_button_->width(), 0);
            else p.drawLine(0, top_button_->height() - 1, top_button_->width(), top_button_->height() - 1);
        }

    }

    return QPushButton::eventFilter(o, e);
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

void stackContentItem::onDelContentItem() {
    delContentItem(this);
}
