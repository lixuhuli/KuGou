#ifndef BASEWIDGET_H
#define BASEWIDGET_H

#include <QWidget>

class baseWidget : public QWidget {
    Q_OBJECT
public:
    explicit baseWidget(QWidget *parent = nullptr);
    virtual ~baseWidget() {}

protected:
    virtual void paintEvent(QPaintEvent *);
    virtual void mousePressEvent(QMouseEvent *);
    virtual void mouseMoveEvent(QMouseEvent*);
    virtual void mouseReleaseEvent(QMouseEvent *);

signals:

public slots:
};

#endif // BASEWIDGET_H
