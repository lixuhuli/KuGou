#include "bottomwidgets.h"
#include <QBoxLayout>

bottomWidgets::bottomWidgets(QWidget *parent) 
    : baseWidget(parent)
    , play_slider_(Qt::Horizontal, this) {
    InitUi();
    InitConnect();
}

void bottomWidgets::InitUi() {
    setFixedHeight(66);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    QHBoxLayout* main_yout = new QHBoxLayout;
    if (!main_yout) return;
    main_yout->setAlignment(Qt::AlignLeft);


    ////////////////////////////////////////////////////////////////////////////////////////////////
    QHBoxLayout *layout1 = new QHBoxLayout;

    m_btnnext.setFixedSize(44, 44);
    m_btnprevious.setFixedSize(44, 44);
    m_btnPlay.setFixedSize(44, 44);

    m_btnnext.setStyleSheet("QPushButton{border-image:url(:/image/bottomwidget/btn_next (1).png);}"
        "QPushButton::hover{border-image:url(:/image/bottomwidget/btn_next (2).png);}"
        "QPushButton::pressed{border-image:url(:/image/bottomwidget/btn_next (3).png);}"
        "QPushButton::disabled{border-image:url(:/image/bottomwidget/btn_next (4).png);}");
    m_btnprevious.setStyleSheet("QPushButton{border-image:url(:/image/bottomwidget/btn_previous (1).png);}"
        "QPushButton::hover{border-image:url(:/image/bottomwidget/btn_previous (2).png);}"
        "QPushButton::pressed{border-image:url(:/image/bottomwidget/btn_previous (3).png);}"
        "QPushButton::disabled{border-image:url(:/image/bottomwidget/btn_previous (4).png);}");
    m_btnPlay.setStyleSheet("QPushButton{border-image:url(:/image/bottomwidget/btn_play (1).png);}"
        "QPushButton::hover{border-image:url(:/image/bottomwidget/btn_play (2).png);}"
        "QPushButton::pressed{border-image:url(:/image/bottomwidget/btn_play (3).png);}"
        "QPushButton::disabled{border-image:url(:/image/bottomwidget/btn_play (4).png);}");

    m_btnprevious.setCursor(QCursor(Qt::PointingHandCursor));
    m_btnPlay.setCursor(QCursor(Qt::PointingHandCursor));
    m_btnnext.setCursor(QCursor(Qt::PointingHandCursor));
    layout1->addWidget(&m_btnprevious);
    layout1->addWidget(&m_btnPlay);
    layout1->addWidget(&m_btnnext);

    layout1->setSpacing(15);
    layout1->setContentsMargins(0, 0, 0, 0);


    /////////////////////////////////////////////////////////////////////////secondlayout
    QVBoxLayout *layout2 = new QVBoxLayout;

    QHBoxLayout *layout2_1 = new QHBoxLayout;

    lbl_playname_.setMinimumWidth(250);
    lbl_playname_.setFixedHeight(30);
    lbl_playname_.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    lbl_playname_.setStyleSheet(QString::fromLocal8Bit("background:transparent;font: bold;color:white;font-family:Î¢ÈíÑÅºÚ;font-size:14px"));
    lbl_playname_.setText(QString::fromLocal8Bit("¼«ÊÓÌýÒôÀÖ"));
    layout2_1->addWidget(&lbl_playname_);

    QFont font;
    font.setFamily("Î¢ÈíÑÅºÚ");
    font.setPixelSize(12);
    font.setBold(false);

    lal_bposition_.setAlignment(Qt::AlignRight | Qt::AlignBottom);
    lal_bposition_.setFixedSize(80, 24);
    lal_bposition_.setFont(font);
    lal_bposition_.setText("00:00/00:00");

    layout2_1->addWidget(&lal_bposition_);

    play_slider_.installEventFilter(this);
    play_slider_.setRange(0, 1000);
    play_slider_.setMinimumWidth(403);
    play_slider_.setFixedHeight(12);
    play_slider_.setStyleSheet("QSlider::groove:horizontal{border-radius:2px;height:3px;}"
        "QSlider::sub-page:horizontal{background:rgb(255, 255, 160);}"
        "QSlider::add-page:horizontal{background:rgb(200,200,209);}"
        "QSlider::handle:horizontal{background:rgb(255, 255, 160);width:8px;border-radius:4px;margin:-3px 0px -3px 0px;}");

    layout2->addLayout(layout2_1);
    layout2->addWidget(&play_slider_);
    layout2->setSpacing(0);
    layout2->setContentsMargins(0, 0, 0, 10);


    main_yout->addLayout(layout1);
    main_yout->addLayout(layout2);
    main_yout->setSpacing(30);
    main_yout->setContentsMargins(12, 0, 0, 0);
    setLayout(main_yout);
}

void bottomWidgets::InitConnect() {

}
