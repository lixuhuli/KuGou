#include "skinwidget.h"
#include <QBoxLayout>
#include "baseWnd/basewidget.h"
#include <QLabel>
#include <QPushButton>
#include <QSCrollbar>
#include <QPainter>
#include "mainWnd/mainwnd.h"

skinWidget::skinWidget(QWidget *parent /*= nullptr*/)
    : baseCommonWnd(parent)
    , mid_top_widget_(&main_widget_)
    , scrollArea(&main_widget_)
    , skin_con_widget_(&scrollArea)
    , slider_widget_(&main_widget_)
    , list_skin_slider_(nullptr) {
    InitUi();
    InitConnect();
}

void skinWidget::InitUi() {
    setStyleSheet("QLabel{color:rgb(154,154,154);}"
        "QPushButton{color: rgb(154,154,154);border:1px solid rgb(197,197,197);}"
        "QPushButton:hover{border:1px solid rgb(100,176,250); color: rgb(100,176,250);}");

    setFixedSize(570, 450);

    main_widget_.setStyleSheet("QWidget{background:transparent;}");
    main_widget_.setSkinPic(mainWnd::getInstance()->skin());

    skin_con_widget_.updateItemSelected(mainWnd::getInstance()->skin());

    //////////////////////////////////////////////////////////////////////////////////////////
    //top widget
    QVBoxLayout *vlyout = new QVBoxLayout;
    if (!vlyout) return;

    baseWidget* top_widget = new baseWidget(this);
    top_widget->setFixedHeight(30);
    top_widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    QHBoxLayout *hlyout = new QHBoxLayout;
    hlyout->setAlignment(Qt::AlignLeft);
    QLabel *label = new QLabel(QString::fromLocal8Bit("主题皮肤与窗口调整"), &main_widget_);
    label->setFixedSize(200, 20);
    label->setStyleSheet("QLabel{font-size:14px;color:white;}");

    QPushButton *m_btn = new QPushButton(&main_widget_);
    m_btn->setFixedSize(20, 20);
    m_btn->setCursor(Qt::PointingHandCursor);
    m_btn->setStyleSheet("QPushButton{border-image:url(:/image/topwidget/btn_close (1).png);}"
        "QPushButton::hover{border-image:url(:/image/topwidget/btn_close (2).png);}"
        "QPushButton::pressed{border-image:url(:/image/topwidget/btn_close (3).png);}");

    connect(m_btn, SIGNAL(clicked(bool)), this, SLOT(hide()));//隐藏

    hlyout->addWidget(label);
    hlyout->addSpacerItem(new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Fixed));
    hlyout->addWidget(m_btn);
    hlyout->setSpacing(0);
    hlyout->setContentsMargins(5, 0, 2, 0);
    top_widget->setLayout(hlyout);


    //////////////////////////////////////////////////////////////////////////////////////////
    InitMidTopUi(&mid_top_widget_);


    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    scrollArea.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea.setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea.setFrameShadow(QFrame::Plain);     // 设置平的样式
    scrollArea.setFrameShape(QFrame::NoFrame);    // 设置无边样式
    scrollArea.setFixedHeight(322);

    // 如下代码保留，今后参考
    //scrollArea.verticalScrollBar()->setStyleSheet("QScrollBar{background:white; width:12px; padding-right: 4px;}"
    //    "QScrollBar::handle{background:rgb(217,217,217);border-radius:4px;}"
    //    "QScrollBar::handle:hover{background: rgb(191,191,191);}"
    //    "QScrollBar::add-line:vertical{border:1px rgb(230,230,230);height: 1px;}"
    //    "QScrollBar::sub-line:vertical{border:1px rgb(230,230,230);height: 1px;}"
    //    "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {background:transparent;}");

    scrollArea.verticalScrollBar()->setStyleSheet("QScrollBar{background:white; width:10px; padding-right: 2px;}"
        "QScrollBar::handle{background:rgb(180,180,180,150);border-radius:4px;}"
        "QScrollBar::handle:hover{background: rgb(150,150,150,150);}"
        "QScrollBar::add-line:vertical{border:1px rgb(230,230,230,150);height: 1px;}"
        "QScrollBar::sub-line:vertical{border:1px rgb(230,230,230,150);height: 1px;}"
        "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {background:transparent;}");


    scrollArea.setWidget(&skin_con_widget_);
    scrollArea.setWidgetResizable(true);

    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    // bottom widget
    baseWidget* bottom_widget = new baseWidget(&main_widget_);
    bottom_widget->setStyleSheet("QWidget{background:white}");

    QHBoxLayout *hlyout3 = new QHBoxLayout;
    hlyout3->setAlignment(Qt::AlignLeft);

    QLabel *label3 = new QLabel(QString::fromLocal8Bit("列表透明"), bottom_widget);
    label3->setFixedSize(60, 45);
    label3->setStyleSheet("QLabel{margin-top:25px;background:white;font-size:14px;}");

    m_btnOpacity.setFixedSize(73, 48);
    m_btnOpacity.setCursor(Qt::PointingHandCursor);
    m_btnOpacity.setStyleSheet("QPushButton{margin-top:24px;}");
    m_btnOpacity.setText("0%");

    QPushButton *btnpersonal = new QPushButton(QString::fromLocal8Bit("个性化壁纸"), bottom_widget);
    btnpersonal->setFixedSize(90, 48);
    btnpersonal->setCursor(Qt::PointingHandCursor);
    btnpersonal->setStyleSheet("QPushButton{margin-top:24px;}");


    hlyout3->addWidget(label3, 0, Qt::AlignTop);
    hlyout3->addWidget(&m_btnOpacity, 0, Qt::AlignTop);
    hlyout3->addStretch();
    hlyout3->addWidget(btnpersonal, 0, Qt::AlignTop);
    hlyout3->setSpacing(0);
    hlyout3->setContentsMargins(20, 0, 19, 0);
    bottom_widget->setLayout(hlyout3);

    /////////////////////////////////////////////////////////////////////////////////////////////////////////

    InitSkinSliderUi();


    /////////////////////////////////////////////////////////////////////////////////////////////////////

    vlyout->addWidget(top_widget);
    vlyout->addWidget(&mid_top_widget_);
    vlyout->addWidget(&scrollArea);
    vlyout->addWidget(bottom_widget);
    vlyout->setSpacing(0);
    vlyout->setContentsMargins(0, 0, 0, 0);
    main_widget_.setLayout(vlyout);
}

void skinWidget::InitMidTopUi(QWidget* widget) {
    if (!widget) return;

    widget->setFixedHeight(28);
    widget->setStyleSheet("QWidget{background: white;}");
    widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    QHBoxLayout *hlyout2 = new QHBoxLayout;
    hlyout2->setAlignment(Qt::AlignLeft);

    QLabel *label2 = new QLabel(QString::fromLocal8Bit("皮肤"), &main_widget_);
    label2->setFixedSize(100, 24);

    m_btnAdjustWindow.setCursor(Qt::PointingHandCursor);
    m_btnAdjustWindow.setText(QString::fromLocal8Bit("恢复窗口默认状态"));
    m_btnAdjustWindow.setStyleSheet("QPushButton{border:NULL; color: rgb(134,134,134);}"
        "QPushButton::hover{ text-decoration: underline; color: rgb(100,176,250);}");

    hlyout2->addWidget(label2);
    hlyout2->addStretch();
    hlyout2->addWidget(&m_btnAdjustWindow);
    hlyout2->setSpacing(0);
    hlyout2->setContentsMargins(20, 0, 20, 4);

    widget->setLayout(hlyout2);

}

void skinWidget::InitSkinSliderUi() {
    slider_widget_.setGeometry(80, 254, 72, 150);
    slider_widget_.setStyleSheet("QWidget{background:white;border:1px solid rgb(194,194,194);}");

    QHBoxLayout *hlyout = new QHBoxLayout;
    QVBoxLayout *vlyout = new QVBoxLayout;

    QString sheet_str = QString("QLabel{border:NULL;color:rgb(88,88,88);}");
    QLabel *label1 = new QLabel("100%", &slider_widget_);
    label1->setStyleSheet(sheet_str);
    label1->setFixedHeight(13);
    label1->adjustSize();

    QLabel *label2 = new QLabel("50%", &slider_widget_);
    label2->setStyleSheet(sheet_str);
    label2->setFixedHeight(13);
    label2->adjustSize();

    QLabel *label3 = new QLabel("0%", &slider_widget_);
    label3->setStyleSheet(sheet_str);
    label3->setFixedHeight(13);
    label3->adjustSize();

    vlyout->addWidget(label1);
    vlyout->addSpacing(52);
    vlyout->addWidget(label2);
    vlyout->addSpacing(52);
    vlyout->addWidget(label3);
    vlyout->setSpacing(0);
    vlyout->setContentsMargins(0, 0, 0, 0);


    list_skin_slider_ = new Slider(Qt::Vertical, &slider_widget_);
    list_skin_slider_->setFixedSize(10, 140);
    list_skin_slider_->setRange(0, 255);
    list_skin_slider_->setValue(0);
    list_skin_slider_->setStyleSheet("QSlider{border:NULL;background:transparent;}"
        "QSlider::groove:vertical{background:transparent;border-radius:2px;width:3px;}"
        "QSlider::sub-page:vertical{background:rgb(150, 150, 150);}"
        "QSlider::add-page:vertical{background:rgb(122,122,122);}"
        "QSlider::handle:vertical{background:rgb(122, 122, 122); height: 8px; border-radius: 4px; margin-left: -3px;  margin-right: -3px;  }");

    hlyout->addLayout(vlyout);
    hlyout->addWidget(list_skin_slider_, 0, Qt::AlignRight);
    hlyout->setSpacing(0);
    hlyout->setContentsMargins(5, 3, 12, 3);
    slider_widget_.setLayout(hlyout);

    slider_widget_.raise();
    slider_widget_.hide();
}

void skinWidget::InitConnect() {
    mid_top_widget_.installEventFilter(this);
    slider_widget_.installEventFilter(this);

    connect(&m_btnOpacity, SIGNAL(clicked(bool)), &slider_widget_, SLOT(show()));
    connect(&m_btnOpacity, SIGNAL(clicked(bool)), &slider_widget_, SLOT(setFocus()));
    if (list_skin_slider_) {
        connect(list_skin_slider_, SIGNAL(valueChanged(int)), mainWnd::getInstance()->middle_widget(), SLOT(setLeftWidgetOpacity(int)));
        connect(list_skin_slider_, SIGNAL(valueChanged(int)), this, SLOT(onSliderOpacity(int)));
        list_skin_slider_->setValue(100);
    }

    connect(&skin_con_widget_, SIGNAL(setClientSkin(QString)), this, SLOT(setSkin(QString)));
    connect(&skin_con_widget_, SIGNAL(setClientSkin(QString)), mainWnd::getInstance(), SLOT(setSkin(QString)));
}

bool skinWidget::eventFilter(QObject *o, QEvent *e) {
    if (o == &mid_top_widget_) {
        if (e->type() == QEvent::MouseButtonPress) {
            setFocus();
            return true;
        }
        else if (e->type() == QEvent::MouseButtonRelease) {
            return true;
        }
    }
    else if (o == &slider_widget_) {
        if (e->type() == QEvent::Leave) {
            slider_widget_.hide();
            return true;
        }
        else if (e->type() == QEvent::FocusOut) {
            QRect rc = slider_widget_.rect();
            auto cur_pos = mapFromGlobal(QCursor::pos());
            if (!slider_widget_.hasFocus() && !list_skin_slider_->hasFocus())
                slider_widget_.hide();
            return true;
        }
    }

    return baseCommonWnd::eventFilter(o, e);
}

void skinWidget::onSliderOpacity(int value) {
    QString str = QString("%1%").arg(100 * value / 255);
    m_btnOpacity.setText(str);
}
