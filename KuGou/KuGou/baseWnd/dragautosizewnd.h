#ifndef DRAGAUTOSIZEWND_H
#define DRAGAUTOSIZEWND_H

#include <QWidget>
#include<QMouseEvent>

enum eCursorMoveState { Default, Right, Left, Bottom, Top, TopRight, TopLeft, BottomRight, BottomLeft };

enum eCursorPressedState { UnPressed, WinRegion, WinBorder };


class dragAutoSizeWnd : public QWidget{
    Q_OBJECT
public:
    explicit dragAutoSizeWnd(QWidget *parent = nullptr);
    virtual ~dragAutoSizeWnd() {}

    inline void setBorder(int border);

    void mouseMoveRect(const QPoint &pt);

protected:
    virtual void mouseMoveEvent(QMouseEvent *event);  //交给别个调用
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);

private:
    int border_;
    eCursorMoveState cursol_move_state_;
    eCursorPressedState cursol_pressed_state_;
    QPoint  mouse_pos_;
    QPoint  window_pos_;
    QSize window_size_;
};

#endif // DRAGAUTOSIZEWND_H