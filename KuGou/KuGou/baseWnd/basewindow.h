#ifndef BASEWINDOW_H
#define BASEWINDOW_H

#include "dragautosizewnd.h"
#include "widget.h"

class baseWindow : public dragAutoSizeWnd {
    Q_OBJECT

public:
    explicit baseWindow(QWidget *parent = nullptr);
    virtual ~baseWindow() {}

    Widget main_widget_;
protected:
    virtual void paintEvent(QPaintEvent *);

public slots:
    void setSkin(const QString &str);

public:
    void set_contents_margins(const QRect& rc);
    const QRect& contents_margins() { return contents_margins_; }

    const QString& skin() { return main_widget_.skinPath(); }

private:
    QRect contents_margins_;
};

#endif // BASEWINDOW_H