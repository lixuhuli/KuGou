#ifndef BASECOMMONWINDOW_H
#define BASECOMMONWINDOW_H

#include <QWidget>
#include "widget.h"

enum eCursorPressedState { UnPressed, WinRegion, WinBorder };

class baseCommonWnd : public QWidget {
    Q_OBJECT
public:
    explicit baseCommonWnd(QWidget *parent = nullptr);
    virtual ~baseCommonWnd() {}

    Widget main_widget_;

protected:
    virtual void paintEvent(QPaintEvent*) override;
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;

private:
    int border_;
    eCursorPressedState cursol_pressed_state_;
    QPoint  mouse_pos_;
    QPoint  window_pos_;
};

#endif // BASECOMMONWINDOW_H