#include "bottomwidgets.h"
#include <QBoxLayout>
#include <QEvent>

bottomWidgets::bottomWidgets(QWidget *parent) 
    : baseWidget(parent)
    , store_vol_(80)
    , volumn_widget_(parent)
    , play_slider_(Qt::Horizontal, this) {
    InitUi();
    InitConnect();

    m_timer.setSingleShot(true);
    volumn_widget_.installEventFilter(this);
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


    ///////////////////////////////////////////////////////////////////////////////////////
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


    ///////////////////////////////////////////////////////////////////////////////////////
    QHBoxLayout *layout3 = new QHBoxLayout;

    m_btnplaylist.setFixedSize(60, 20);
    m_btnlrc.setFixedSize(20, 20);
    m_btnequalizer.setFixedSize(48, 20);
    m_btnplaymode.setFixedSize(20, 20);
    m_btnvol.setFixedSize(20, 20);
    m_btnmore.setFixedSize(20, 20);
    m_btndownload.setFixedSize(20, 20);
    m_btnfavorite.setFixedSize(20, 20);

    m_btnplaylist.setCursor(QCursor(Qt::PointingHandCursor));
    m_btnlrc.setCursor(QCursor(Qt::PointingHandCursor));
    m_btnequalizer.setCursor(QCursor(Qt::PointingHandCursor));
    m_btnplaymode.setCursor(QCursor(Qt::PointingHandCursor));
    m_btnvol.setCursor(QCursor(Qt::PointingHandCursor));
    m_btnmore.setCursor(QCursor(Qt::PointingHandCursor));
    m_btndownload.setCursor(QCursor(Qt::PointingHandCursor));
    m_btnfavorite.setCursor(QCursor(Qt::PointingHandCursor));

    m_btnplaylist.setStyleSheet("QPushButton{border:NULL;background-image:url(:/image/bottomwidget/btn_miniplaylist (1).png);}"
        "QPushButton::hover{background-image:url(:/image/bottomwidget/btn_miniplaylist (2).png);}"
        "QPushButton::pressed{background-image:url(:/image/bottomwidget/btn_miniplaylist (3).png);}");
    m_btnlrc.setStyleSheet("QPushButton{border-image:url(:/image/bottomwidget/btn_lrc (1).png);}"
        "QPushButton::hover{border-image:url(:/image/bottomwidget/btn_lrc (2).png);}"
        "QPushButton::pressed{border-image:url(:/image/bottomwidget/btn_lrc (3).png);}");

    m_btnequalizer.setStyleSheet("QPushButton{border:NULL;background-image:url(:/image/bottomwidget/btn_equalizer (1).png);}"
        "QPushButton::hover{background-image:url(:/image/bottomwidget/btn_equalizer (2).png);}"
        "QPushButton::pressed{background-image:url(:/image/bottomwidget/btn_equalizer (3).png);}");

    m_btnplaymode.setStyleSheet("QPushButton{border-image:url(:/image/bottomwidget/btn_listrandom (1).png);}"
        "QPushButton::hover{border-image:url(:/image/bottomwidget/btn_listrandom (2).png);}");

    m_btnmore.setStyleSheet("QPushButton{border-image:url(:/image/bottomwidget/btn_more (1).png);}"
        "QPushButton::hover{border-image:url(:/image/bottomwidget/btn_more (2).png);}"
        "QPushButton::pressed{border-image:url(:/image/bottomwidget/btn_more (3).png);}");

    m_btndownload.setStyleSheet("QPushButton{border:NULL;background-image:url(:/image/bottomwidget/btn_download (1).png);}"
        "QPushButton::hover{background-image:url(:/image/bottomwidget/btn_download (2).png);}"
        "QPushButton::pressed{background-image:url(:/image/bottomwidget/btn_download (3).png);}");

    m_btnfavorite.setStyleSheet("QPushButton{border-image:url(:/image/bottomwidget/btn_favorite_no (1).png);}"
        "QPushButton::hover{border-image:url(:/image/bottomwidget/btn_favorite_no (2).png);}"
        "QPushButton::pressed{border-image:url(:/image/bottomwidget/btn_favorite_no (3).png);}");

    m_btnvol.setStyleSheet("QRadioButton::indicator::unchecked{border-image:url(:/image/bottomwidget/btn_vol (1).png) 0 20 0 60;}"
        "QRadioButton::indicator::unchecked:hover{border-image:url(:/image/bottomwidget/btn_vol (2).png) 0 20 0 60;}"
        "QRadioButton::indicator::checked{border-image:url(:/image/bottomwidget/btn_vol (1).png) 0 0 0 80;}"
        "QRadioButton::indicator::checked:hover{border-image:url(:/image/bottomwidget/btn_vol (2).png) 0 0 0 80;}"
        "QRadioButton::indicator{width:20px;height:20px;}");
    m_btnvol.installEventFilter(this);

    layout3->addWidget(&m_btnfavorite);
    layout3->addWidget(&m_btndownload);
    layout3->addWidget(&m_btnmore);
    layout3->addWidget(&m_btnplaymode);
    layout3->addWidget(&m_btnvol);
    layout3->addWidget(&m_btnequalizer);
    layout3->addWidget(&m_btnlrc);
    layout3->addWidget(&m_btnplaylist);

    layout3->setSpacing(18);
    layout3->setContentsMargins(0, 0, 0, 0);


    /////////////////////////////////////////////////////////////////////////////////////////////
    main_yout->addLayout(layout1);
    main_yout->addLayout(layout2);
    main_yout->addLayout(layout3);
    main_yout->setSpacing(30);
    main_yout->setContentsMargins(12, 0, 0, 0);
    setLayout(main_yout);

    volumn_widget_.hide();
}

void bottomWidgets::InitConnect() {
    connect(&m_timer, SIGNAL(timeout()), &volumn_widget_, SLOT(hide()));
    connect(&m_btnvol, SIGNAL(clicked(bool)), this, SLOT(OnRadioClick(bool)));

    auto vol_slider = volumn_widget_.volumn_slider();
    if (vol_slider) {
        connect(vol_slider, SIGNAL(valueChanged(int)), this, SLOT(updateBtnStatus(int)));
        vol_slider->setValue(store_vol_);
    }
}

bool bottomWidgets::eventFilter(QObject *o, QEvent *e) {
    if (o == &m_btnvol) {
        if (e->type() == QEvent::Enter) {
            auto x = m_btnvol.pos().x();
            auto y = pos().y() + m_btnvol.pos().y() - volumn_widget_.height();

            volumn_widget_.setGeometry(x, y, 30, 310);
            volumn_widget_.show();
            volumn_widget_.raise();

            m_timer.stop();
        }
        else if (e->type() == QEvent::Leave) {
            m_timer.start(500);
        }
    }
    else if (o == &volumn_widget_) {
        if (e->type() == QEvent::Enter) {
            m_timer.stop();
        }
        else if (e->type() == QEvent::Leave) {
            m_timer.start(500);
        }
    }

    return baseWidget::eventFilter(o, e);
}

void bottomWidgets::updateBtnStatus(int value) {
    if (value <= 0) {
        m_btnvol.setChecked(true);
    }
    else if (value <= 30) {
        m_btnvol.setChecked(false);
        m_btnvol.setStyleSheet("QRadioButton::indicator::unchecked{border-image:url(:/image/bottomwidget/btn_vol (1).png) 0 60 0 20;}"
            "QRadioButton::indicator::unchecked:hover{border-image:url(:/image/bottomwidget/btn_vol (2).png) 0 60 0 20;}"
            "QRadioButton::indicator::checked{border-image:url(:/image/bottomwidget/btn_vol (1).png) 0 0 0 80;}"
            "QRadioButton::indicator::checked:hover{border-image:url(:/image/bottomwidget/btn_vol (2).png) 0 0 0 80;}"
            "QRadioButton::indicator{width:20px;height:20px;}");
    }
    else {
        m_btnvol.setChecked(false);
        m_btnvol.setStyleSheet("QRadioButton::indicator::unchecked{border-image:url(:/image/bottomwidget/btn_vol (1).png) 0 20 0 60;}"
            "QRadioButton::indicator::unchecked:hover{border-image:url(:/image/bottomwidget/btn_vol (2).png) 0 20 0 60;}"
            "QRadioButton::indicator::checked{border-image:url(:/image/bottomwidget/btn_vol (1).png) 0 0 0 80;}"
            "QRadioButton::indicator::checked:hover{border-image:url(:/image/bottomwidget/btn_vol (2).png) 0 0 0 80;}"
            "QRadioButton::indicator{width:20px;height:20px;}");
    }

    if (value != 0) store_vol_ = value;
}

void bottomWidgets::OnRadioClick(bool check) {
    auto vol_slider = volumn_widget_.volumn_slider();
    if (!vol_slider) return;

    vol_slider->setValue(check ? 0 : store_vol_);
}
