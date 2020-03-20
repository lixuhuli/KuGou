#include "skinwidget.h"
#include <QBoxLayout>
#include "baseWnd/basewidget.h"
#include <QLabel>
#include <QPushButton>
#include <QSCrollbar>

skinWidget::skinWidget(QWidget *parent /*= nullptr*/)
    : baseCommonWnd(parent)
    , mid_top_widget_(&main_widget_)
    , scrollArea(&main_widget_)
    , skin_con_widget_(&scrollArea) {
    InitUi();
    InitConnect();
}

void skinWidget::InitUi() {
    setStyleSheet("QLabel{color:rgb(154,154,154);}"
        "QPushButton{color: rgb(154,154,154);border:1px solid rgb(197,197,197);}"
        "QPushButton:hover{border:1px solid rgb(100,176,250); color: rgb(100,176,250);}");

    setFixedSize(570, 450);

    main_widget_.setStyleSheet("QWidget{background:transparent;}");
    main_widget_.setSkinPic(QString::fromLocal8Bit(":/image/skin/默认.jpg"));

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
    //scrollArea.setWidgetResizable(true);

    /////////////////////////////////////////////////////////////////////////////////////////////////////////

    vlyout->addWidget(top_widget);
    vlyout->addWidget(&mid_top_widget_);
    vlyout->addWidget(&scrollArea);
    vlyout->addWidget(new baseWidget);
    vlyout->setSpacing(0);
    vlyout->setContentsMargins(0, 0, 0, 0);
    main_widget_.setLayout(vlyout);
}

void skinWidget::InitConnect() {
    mid_top_widget_.installEventFilter(this);
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

    return baseCommonWnd::eventFilter(o, e);
}
