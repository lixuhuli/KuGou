#include "topwidgets.h"
#include <QStyleOption>
#include <QPainter>
#include <QBoxLayout>
#include "mainWnd/mainwnd.h"
#include <QLabel>

topWidgets::topWidgets(QWidget *parent)
    : QWidget(parent) {
    setStyleSheet("TopWidgets{background:transparent;}");
    setMouseTracking(true);
    initWidget();
}

void topWidgets::paintEvent(QPaintEvent *e) {
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    __super::paintEvent(e);
}

void topWidgets::mouseMoveEvent(QMouseEvent* e) {
    mainWnd::getInstance().mouseMoveEvent(e);
    __super::mouseMoveEvent(e);
}

void topWidgets::initWidget() {
    setMinimumHeight(50);
    setMaximumHeight(50);

    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    QHBoxLayout *main_yout_ = new QHBoxLayout;
    if (!main_yout_) return;

    main_yout_->setAlignment(Qt::AlignLeft);

    QPushButton *btn = new QPushButton();
    btn->setFixedSize(30, 30);
    btn->setStyleSheet("QPushButton{background:transparent;border-image:url(:/image/topwidget/label_icon.png)}");

    main_yout_->addWidget(btn);
    main_yout_->addSpacing(11);

    btn_login_.setFixedSize(26, 24);
    btn_login_.setStyleSheet("QPushButton{background:transparent;color:white;font-family:ËÎÌå;font-size:12px;}");
    btn_login_.setText(QString::fromLocal8Bit("µÇÂ½"));
    btn_login_.setCursor(QCursor(Qt::PointingHandCursor));
    main_yout_->addWidget(&btn_login_);
    main_yout_->addSpacing(5);

    QLabel*label2 = new QLabel(QString::fromLocal8Bit("Ø­"), this);
    label2->setFixedSize(10, 20);
    label2->setStyleSheet("color:white;");
    label2->adjustSize();
    main_yout_->addWidget(label2);
    main_yout_->addSpacing(5);


    m_btnregister.setFixedSize(26, 24);
    m_btnregister.setStyleSheet("QPushButton{background:transparent;color:white;font-family:ËÎÌå;font-size:12px;}");
    m_btnregister.setText(QString::fromLocal8Bit("×¢²á"));
    main_yout_->addWidget(&m_btnregister);

    main_yout_->addSpacing(190);
    main_yout_->addSpacerItem(new QSpacerItem(80, 30, QSizePolicy::Maximum));//ÉèÖÃËü×î´óÅòÕÍ£¡£¡£¡



    ////////////////////////////////////////////////////////////////////////////////////////////////
    QPushButton *m_btnreturn = new QPushButton(this);
    m_btnreturn->setFixedSize(20, 20);
    m_btnreturn->setStyleSheet("QPushButton{border-image:url(:/image/topwidget/btn_ return(1).png);}"
        "QPushButton::hover{border-image:url(:/image/topwidget/btn_ return(2).png);}"
        "QPushButton::pressed{border-image:url(:/image/topwidget/btn_ return(3).png);}");
    m_btnreturn->setCursor(QCursor(Qt::PointingHandCursor));
    main_yout_->addWidget(m_btnreturn);

    main_yout_->addSpacing(20);

    QPushButton *m_btnrefresh = new QPushButton(this);
    m_btnrefresh->setFixedSize(20, 20);
    m_btnrefresh->setStyleSheet("QPushButton{border-image:url(:/image/topwidget/btn_refresh(1).png);}"
        "QPushButton::hover{border-image:url(:/image/topwidget/btn_refresh(2).png);}"
        "QPushButton::pressed{border-image:url(:/image/topwidget/btn_refresh(3).png);}");
    m_btnrefresh->setCursor(QCursor(Qt::PointingHandCursor));
    main_yout_->addWidget(m_btnrefresh);

    main_yout_->addSpacing(20);

    m_lineEdit.setMinimumSize(260, 26);
    m_lineEdit.setMaximumSize(320, 26);
    m_lineEdit.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    m_lineEdit.setStyleSheet("QLineEdit{border-radius:13px;background:rgb(255,255,255,180);}");
    m_lineEdit.setContextMenuPolicy(Qt::NoContextMenu);

    QHBoxLayout *pSearchLayout = new QHBoxLayout();
    pSearchLayout->setAlignment(Qt::AlignRight);
    pSearchLayout->setSpacing(0);
    pSearchLayout->setContentsMargins(0, 0, 15, 0);
    m_lineEdit.setLayout(pSearchLayout);

    QPushButton *serbtn = new QPushButton();
    serbtn->setFixedSize(16, 16);
    serbtn->setStyleSheet("QPushButton{background:transparent;border-image: url(:/image/topwidget/btn_search (1).png);}"
        "QPushButton::hover{border-image: url(:/image/topwidget/btn_search (2).png);}"
        "QPushButton::pressed{border-image: url(:/image/topwidget/btn_search (3).png);}");
    serbtn->setCursor(QCursor(Qt::PointingHandCursor));
    pSearchLayout->addWidget(serbtn);

    m_lineEdit.setPlaceholderText(QString::fromLocal8Bit("ÖÜ½ÜÂ×-¶«·çÆÆ"));
    QMargins margins = m_lineEdit.textMargins();
    m_lineEdit.setTextMargins(margins.left() + 15, margins.top(), serbtn->width() + 15, margins.bottom());
    main_yout_->addWidget(&m_lineEdit);

    main_yout_->addSpacerItem(new QSpacerItem(110, 30, QSizePolicy::Expanding));//ÅòÕÍ


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    QHBoxLayout *right_yout = new QHBoxLayout;
    m_btntool.setFixedSize(16, 16);
    m_btntool.setStyleSheet("QPushButton{border-image:url(:/image/topwidget/btn_tool (1).png);}"
        "QPushButton::hover{border-image:url(:/image/topwidget/btn_tool (2).png);}"
        "QPushButton::pressed{border-image:url(:/image/topwidget/btn_tool (3).png);}");
    m_btntool.setCursor(QCursor(Qt::PointingHandCursor));
    right_yout->addWidget(&m_btntool);

    m_btnplaycard.setFixedSize(16, 16);
    m_btnplaycard.setStyleSheet("QPushButton{border-image:url(:/image/topwidget/btn_playcard (1).png);}"
        "QPushButton::hover{border-image:url(:/image/topwidget/btn_playcard (2).png);}"
        "QPushButton::pressed{border-image:url(:/image/topwidget/btn_playcard (3).png);}");
    m_btnplaycard.setCursor(QCursor(Qt::PointingHandCursor));
    right_yout->addWidget(&m_btnplaycard);

    m_btngame.setFixedSize(16, 16);
    m_btngame.setStyleSheet("QPushButton{border-image:url(:/image/topwidget/btn_game (1).png);}"
        "QPushButton::hover{border-image:url(:/image/topwidget/btn_game (2).png);}"
        "QPushButton::pressed{border-image:url(:/image/topwidget/btn_game (3).png);}");
    m_btngame.setCursor(QCursor(Qt::PointingHandCursor));
    right_yout->addWidget(&m_btngame);

    m_btnmessage.setFixedSize(16, 16);
    m_btnmessage.setStyleSheet("QPushButton{border-image:url(:/image/topwidget/btn_message (1).png);}"
        "QPushButton::hover{border-image:url(:/image/topwidget/btn_message (2).png);}"
        "QPushButton::pressed{border-image:url(:/image/topwidget/btn_message (3).png);}");
    m_btnmessage.setCursor(QCursor(Qt::PointingHandCursor));
    right_yout->addWidget(&m_btnmessage);

    m_btnskin.setFixedSize(16, 16);
    m_btnskin.setStyleSheet("QPushButton{border-image:url(:/image/topwidget/btn_skin (1).png);}"
        "QPushButton::hover{border-image:url(:/image/topwidget/btn_skin (2).png);}"
        "QPushButton::pressed{border-image:url(:/image/topwidget/btn_skin (3).png);}");
    m_btnskin.setCursor(QCursor(Qt::PointingHandCursor));
    right_yout->addWidget(&m_btnskin);

    m_btnsetting.setFixedSize(16, 16);
    m_btnsetting.setStyleSheet("QPushButton{border-image:url(:/image/topwidget/btn_setting (1).png);}"
        "QPushButton::hover{border-image:url(:/image/topwidget/btn_setting (2).png);}"
        "QPushButton::pressed{border-image:url(:/image/topwidget/btn_setting (3).png);}");
    m_btnsetting.setCursor(QCursor(Qt::PointingHandCursor));
    right_yout->addWidget(&m_btnsetting);

    right_yout->addSpacing(18);

    m_btnmobile.setFixedSize(16, 16);
    m_btnmobile.setStyleSheet("QPushButton{border-image:url(:/image/topwidget/btn_mobile (1).png);}"
        "QPushButton::hover{border-image:url(:/image/topwidget/btn_mobile (2).png);}"
        "QPushButton::pressed{border-image:url(:/image/topwidget/btn_mobile (3).png);}");
    m_btnmobile.setCursor(QCursor(Qt::PointingHandCursor));
    right_yout->addWidget(&m_btnmobile);

    m_btnminiframe.setFixedSize(16, 16);
    m_btnminiframe.setStyleSheet("QPushButton{border-image:url(:/image/topwidget/btn_miniframe (1).png);}"
        "QPushButton::hover{border-image:url(:/image/topwidget/btn_miniframe (2).png);}"
        "QPushButton::pressed{border-image:url(:/image/topwidget/btn_miniframe (3).png);}");
    m_btnminiframe.setCursor(QCursor(Qt::PointingHandCursor));
    right_yout->addWidget(&m_btnminiframe);

    m_btnmini.setFixedSize(16, 16);
    m_btnmini.setStyleSheet("QPushButton{border-image:url(:/image/topwidget/btn_mini (1).png);}"
        "QPushButton::hover{border-image:url(:/image/topwidget/btn_mini (2).png);}"
        "QPushButton::pressed{border-image:url(:/image/topwidget/btn_mini (3).png);}");
    m_btnmini.setCursor(QCursor(Qt::PointingHandCursor));
    right_yout->addWidget(&m_btnmini);

    m_btnexit.setFixedSize(18, 18);
    m_btnexit.setStyleSheet("QPushButton{border-image:url(:/image/topwidget/btn_close (1).png);}"
        "QPushButton::hover{border-image:url(:/image/topwidget/btn_close (2).png);}"
        "QPushButton::pressed{border-image:url(:/image/topwidget/btn_close (3).png);}");
    m_btnexit.setCursor(QCursor(Qt::PointingHandCursor));
    right_yout->addWidget(&m_btnexit);

    right_yout->setSpacing(12);
    right_yout->setContentsMargins(0, 0, 0, 0);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    main_yout_->addLayout(right_yout);

    main_yout_->setSpacing(0);
    main_yout_->setContentsMargins(16, 0, 15, 0);
    setLayout(main_yout_);

}
