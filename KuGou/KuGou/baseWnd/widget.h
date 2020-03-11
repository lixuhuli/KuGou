#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget {
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);

    const QString& skinPath() { return skin_path_; }

public slots:
    void setSkinPic(const QString &skin);

protected:
    virtual void paintEvent(QPaintEvent *e) override;
    virtual void resizeEvent(QResizeEvent *) override;

private:
    void updateSkin();

private:
    QPixmap skin_pic_;
    QString skin_path_;
};

#endif // WIDGET_H
