#include "middlewidgetright.h"
#include <QBoxLayout>
#include <QPushButton>
#include <QPainter>

middleWidgetRight::middleWidgetRight(QWidget *parent /*= nullptr*/)
    : baseWidget(parent)
    , mv_widget_(this)
    , m_isdrawline(true)
    , option_functions_(this)
    , stack_func_widget_(this) {
    InitUi();
    InitConnect();
}

void middleWidgetRight::InitUi() {
    setMinimumWidth(690);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    option_functions_.setExclusive(true);

    QVBoxLayout *vLyout = new QVBoxLayout;
    if (!vLyout) return;

    QHBoxLayout *hlyout = new QHBoxLayout;

    QFont font;
    font.setPixelSize(17);
    font.setFamily(QString::fromLocal8Bit("黑体"));

    QStringList list_name;
    list_name << QString::fromLocal8Bit("乐库") << QString::fromLocal8Bit("电台") << QString::fromLocal8Bit("歌单")
        << QString::fromLocal8Bit("直播") << QString::fromLocal8Bit("MV") << QString::fromLocal8Bit("歌词");

    hlyout->addStretch();
    for (int i = 0; i < 6; i++) {
        QPushButton *btn_option = new QPushButton(this);
        btn_option->setCheckable(true);
        btn_option->setFixedSize(54, 40);
        btn_option->setCursor(Qt::PointingHandCursor);
        btn_option->setFont(font);
        btn_option->setText(list_name.value(i));
        btn_option->setStyleSheet("QPushButton{color:rgb(68,68,68);}"
            "QPushButton::hover{color:rgb(40,143,231);}"
            "QPushButton::checked{color:rgb(40,143,231);border-image:url(:/image/middlewidget/btn_mask.png);}");
        option_functions_.addButton(btn_option, i);
        hlyout->addWidget(btn_option);
    }
    option_functions_.button(0)->setChecked(true);
    hlyout->addStretch();

    hlyout->setSpacing(25);
    hlyout->setContentsMargins(0, 0, 0, 0);

    stack_func_widget_.addWidget(new baseWidget(this));
    stack_func_widget_.addWidget(new baseWidget(this));
    stack_func_widget_.addWidget(new baseWidget(this));
    stack_func_widget_.addWidget(new baseWidget(this));
    stack_func_widget_.addWidget(&mv_widget_);
    stack_func_widget_.addWidget(new baseWidget(this));
    stack_func_widget_.setCurrentIndex(0);

    vLyout->addLayout(hlyout);
    vLyout->addWidget(&stack_func_widget_);

    vLyout->setSpacing(0);
    vLyout->setContentsMargins(0, 0, 0, 0);
    setLayout(vLyout);
}

void middleWidgetRight::InitConnect() {
    connect(&option_functions_, SIGNAL(buttonToggled(int, bool)), this, SLOT(OnButtonToggled(int, bool)));
    connect(this, SIGNAL(setIsTransparent(bool)), parentWidget(), SLOT(setBackgroundstatus(bool)));
}

void middleWidgetRight::paintEvent(QPaintEvent* e) {
    baseWidget::paintEvent(e);

    if (m_isdrawline) {
        QPainter p(this);
        p.setPen(QColor(230, 230, 230));
        p.drawLine(0, 39, width(), 39);
    }
}

void middleWidgetRight::OnButtonToggled(int id, bool check) {
    auto list_btn = option_functions_.buttons();
    if (id < 0 || id >= list_btn.count()) return;

    if (check) stack_func_widget_.setCurrentIndex(id);

    if (id == 5) {
        if (check) {
            setDrawLine(false);
            setIsTransparent(true);
            update();
        }
        else {
            setDrawLine(true);
            setIsTransparent(false);
            update();
        }
    }
}
