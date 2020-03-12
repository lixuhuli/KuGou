#include "dragautosizewnd.h"

dragAutoSizeWnd::dragAutoSizeWnd(QWidget *parent) 
    : QWidget(parent)
    , border_(8)
    , cursol_move_state_(Default)
    , cursol_pressed_state_(UnPressed)
    , mouse_pos_(QPoint(0, 0))
    , window_pos_(QPoint(0, 0))
    , window_size_(QSize(0, 0)){

    setMinimumSize(400, 550);

    setMouseTracking(true);
    setWindowFlags(Qt::FramelessWindowHint);  // setting windows tool bar icon invisiable
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void dragAutoSizeWnd::setBorder(int border) {
    border_ = border;
}

void dragAutoSizeWnd::mouseMoveRect(const QPoint &pt) {
    auto p = mapFromGlobal(pt);

    if (cursol_pressed_state_ != WinBorder) {
        if (p.x() > width() - border_ && p.y() < height() - border_ && p.y() > border_) {
            // right side
            setCursor(Qt::SizeHorCursor);
            cursol_move_state_ = Right;
        }
        else if (p.x() < border_ && p.y() < height() - border_ && p.y() > border_) // left side;
        {
            setCursor(Qt::SizeHorCursor);
            cursol_move_state_ = Left;
        }
        else if (p.y() > height() - border_ && p.x() > border_ && p.x() < width() - border_) // bottom side;
        {
            setCursor(Qt::SizeVerCursor);
            cursol_move_state_ = Bottom;
        }
        else if (p.y() < border_ && p.x() > border_ && p.x() < width() - border_)
        {
            setCursor(Qt::SizeVerCursor);
            cursol_move_state_ = Top;
        }
        //corner
        else if (p.y() < border_ && p.x() > width() - border_)
        {
            setCursor(Qt::SizeBDiagCursor);
            cursol_move_state_ = TopRight;
        }

        else if (p.y() < border_ && p.x() < border_)
        {
            setCursor(Qt::SizeFDiagCursor);
            cursol_move_state_ = TopLeft;
        }

        else if (p.x() > width() - border_ && p.y() > height() - border_)
        {
            setCursor(Qt::SizeFDiagCursor);
            cursol_move_state_ = BottomRight;
        }

        else if (p.x() < border_ && p.y() > height() - border_)
        {
            setCursor(Qt::SizeBDiagCursor);
            cursol_move_state_ = BottomLeft;
        }
        ////
        else
        {
            cursol_move_state_ = Default;
            setCursor(Qt::ArrowCursor);
        }
    }
    else if (cursol_pressed_state_ == WinBorder) {
        switch (cursol_move_state_) {
        case Right: {
            int setW = pt.x() - x();
            if (minimumWidth() <= setW && setW <= maximumWidth())
                setGeometry(x(), y(), setW, height());
            break;
        }
        case Left: {
            int setW = width() + x() - pt.x();
            if (minimumWidth() <= setW && setW <= maximumWidth())
                setGeometry(pt.x(), y(), setW, height());
            break;
        }
        case Bottom: {
            int setH = pt.y() - y();
            if (minimumHeight() <= setH && setH <= maximumHeight())
                setGeometry(x(), y(), width(), setH);
            break;
        }
        case Top: {
            int setH = y() - pt.y() + height();
            if (minimumHeight() <= setH && setH <= maximumHeight())
                setGeometry(x(), pt.y(), width(), setH);
            break;
        }
        case TopRight: {
            int setH = height() + y() - pt.y();
            int setW = pt.x() - x();
            int setY = pt.y();

            if (setH >= maximumHeight()) {
                setY = window_pos_.y() + window_size_.height() - height();
                setH = maximumHeight();
            }
            else if (setH <= minimumHeight()) {
                setY = window_pos_.y() + window_size_.height() - height();
                setH = minimumHeight();
            }
            setGeometry(window_pos_.x(), setY, setW, setH);
            break;
        }
        case TopLeft: {
            int setY = pt.y();
            int setX = pt.x();

            int setW = pos().x() - setX + width();
            int setH = pos().y() - setY + height();
            int totalW = window_pos_.x() + window_size_.width();
            int totalH = window_pos_.y() + window_size_.height();

            if (totalW - setX >= maximumWidth()) {
                setX = totalW - maximumWidth();
                setW = maximumWidth();
            }
            else if (totalW - setX <= minimumWidth()) {
                setX = totalW - minimumWidth();
                setW = minimumWidth();
            }

            if (totalH - setY >= maximumHeight()) {
                setY = totalH - maximumHeight();
                setH = maximumHeight();
            }
            else if (totalH - setY <= minimumHeight()) {
                setY = totalH - minimumHeight();
                setH = minimumHeight();
            }
            setGeometry(setX, setY, setW, setH);
            break;
        }
        case BottomRight: {
            int setW = pt.x() - x();
            int setH = pt.y() - y();
            setGeometry(window_pos_.x(), window_pos_.y(), setW, setH);
            break;
        }
        case BottomLeft: {
            int setW = x() - pt.x() + width();
            int setH = pt.y() - window_pos_.y();
            int setX = pt.x();
            int totalW = window_pos_.x() + window_size_.width();

            if (totalW - setX >= maximumWidth()) {
                setX = totalW - maximumWidth();
                setW = maximumWidth();
            }
            else if (totalW - setX <= minimumWidth()) {
                setX = totalW - minimumWidth();
                setW = minimumWidth();
            }
            setGeometry(setX, window_pos_.y(), setW, setH);
            break;
        }
        case Default:
        default:
            break;
        }
    }
}

void dragAutoSizeWnd::mouseMoveEvent(QMouseEvent *event) {
    if (!event) return;

    mouseMoveRect(event->globalPos());
    if (cursol_pressed_state_ == WinRegion) {
        this->move(window_pos_ + (event->globalPos() - mouse_pos_));
    }
}

void dragAutoSizeWnd::mousePressEvent(QMouseEvent *event) {
    if (!event) return;

    window_size_ = this->size();

    setFocus();

    if (event->button() == Qt::LeftButton) {
        window_pos_ = this->pos(); // save the prssed position
        if (QRect(border_ + 1, border_ + 1, width() - (border_ + 1) * 2, height() - (border_ + 1) * 2).contains(QPoint(event->globalX() - x(), event->globalY() - y()))) {
            mouse_pos_ = event->globalPos();
            cursol_pressed_state_ = WinRegion;
        }
        else
            cursol_pressed_state_ = WinBorder;
    }

}

void dragAutoSizeWnd::mouseReleaseEvent(QMouseEvent *event) {
    if (!event) return;

    mouse_pos_.setX(0);
    mouse_pos_.setY(0);
    cursol_pressed_state_ = UnPressed;

    if (event->button() == Qt::LeftButton) {
        setCursor(Qt::PointingHandCursor);
    }
}