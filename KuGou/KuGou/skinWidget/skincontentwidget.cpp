#include "skincontentwidget.h"
#include <QGridLayout>
#include <QLabel>
#include <QDir>
#include <QApplication>

skinContentWidget::skinContentWidget(QWidget *parent /*= nullptr*/)
    : baseWidget(parent)
    , skin_item_groups_(this) {
    InitUi();
    InitConnect();
}

void skinContentWidget::InitUi() {
    setStyleSheet("QWidget{background: white;}");

    QGridLayout *gyout = new QGridLayout();
    if (!gyout) return;

    skin_item_groups_.setExclusive(true);

    auto item = createSkinContentItem(QString::fromLocal8Bit(":/image/skin/默认.jpg"));
    skin_item_groups_.addButton(item, 0);
    gyout->addWidget(item, 0, 0);
    item->setChecked(true);

    loadFromDir(QApplication::applicationDirPath() + "/skin", gyout);

    gyout->setHorizontalSpacing(4);
    gyout->setVerticalSpacing(4);
    gyout->setContentsMargins(20, 0, 20, 0);

    setLayout(gyout);
}

void skinContentWidget::InitConnect() {
}

void skinContentWidget::loadFromDir(const QString &strdir, QGridLayout *gyout) {
    if (!gyout) return;

    QDir dir(strdir);
    if (!dir.exists()) return;

    dir.setFilter(QDir::Files | QDir::NoSymLinks);
    QFileInfoList list = dir.entryInfoList();

    int count = list.count();
    if (count <= 0) return;

    int row = 0;
    int column = 0;
    for (int i = 1; i < count + 1; i++) {
        auto file_info = list.value(i - 1);
        auto suffix = file_info.suffix();
        if (suffix.compare("png", Qt::CaseInsensitive) == 0
            || suffix.compare("jpg", Qt::CaseInsensitive) == 0) {

            auto skin_path = file_info.absoluteFilePath();
            auto item = createSkinContentItem(skin_path);
            row = i / 4;
            column = i - row * 4;
            skin_item_groups_.addButton(item, i);
            gyout->addWidget(item, row, column);
        }
    }

}

QPushButton* skinContentWidget::createSkinContentItem(const QString& file_path) {
    skinContentItem* item = new skinContentItem(this);
    if (!item) return nullptr;

    QString sheet_str = QString("QPushButton{border-image:url(%1);}").arg(file_path);

    item->setFixedSize(125, 80);
    item->setStyleSheet(sheet_str);
    item->setCursor(Qt::PointingHandCursor);
    item->setCheckable(true);

    QWidget *select_widget = new QWidget(item);
    select_widget->setGeometry(105, 60, 17, 17);
    select_widget->setObjectName("select_widget");
    select_widget->setStyleSheet("QWidget{background:transparent;border-image:url(:/image/skinwidget/selected.png)}");

    baseWidget* item_widget = new baseWidget(item);
    item_widget->setStyleSheet("QWidget{background:rgb(55,55,55,100);}");
    item_widget->setGeometry(0, 0, 125, 80);
    item_widget->setObjectName("item_widget");


    QVBoxLayout *vlyout = new QVBoxLayout(item_widget);
    if (!vlyout) return item;

    QString labl_sheet(QString::fromLocal8Bit("QLabel{background:transparent;font-family:宋体;font-size:13px;color:white;}"));

    QLabel* pic_name = new QLabel(QString::fromLocal8Bit("默认"), item_widget);
    pic_name->setStyleSheet(labl_sheet);
    pic_name->adjustSize();
    pic_name->setAlignment(Qt::AlignHCenter);

    QLabel* author_name = new QLabel(QString::fromLocal8Bit("作者：严涛"), item_widget);
    author_name->setStyleSheet(labl_sheet);
    author_name->setFixedHeight(13);
    author_name->adjustSize();
    author_name->setAlignment(Qt::AlignHCenter);

    QLabel* used_count = new QLabel(QString::fromLocal8Bit("250人已使用"), item_widget);
    used_count->setStyleSheet(labl_sheet);
    used_count->adjustSize();
    used_count->setAlignment(Qt::AlignHCenter);

    vlyout->addWidget(pic_name);
    vlyout->addSpacing(1);
    vlyout->addWidget(author_name);
    vlyout->addSpacing(1);
    vlyout->addWidget(used_count);
    vlyout->setSpacing(0);
    vlyout->setContentsMargins(0, 21, 0, 18);
    item_widget->setLayout(vlyout);

    item_widget->hide();
    select_widget->hide();

    connect(item, SIGNAL(enterItem(bool)), item_widget, SLOT(setVisible(bool)));
    connect(item, SIGNAL(toggled(bool)), select_widget, SLOT(setVisible(bool)));

    return item;
}
