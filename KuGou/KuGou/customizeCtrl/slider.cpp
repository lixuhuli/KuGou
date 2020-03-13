#include "slider.h"
#include <qevent.h>

Slider::Slider(Qt::Orientation orientation, QWidget* parent) 
    : QSlider(orientation, parent) {
    setMaximum(100);
    setMinimum(0);
    setCursor(Qt::PointingHandCursor);
    setMouseTracking(true);
}

void Slider::mousePressEvent(QMouseEvent *ev) {
    if (orientation() == Qt::Vertical) //vertical
    {
        if (ev->button() == Qt::LeftButton)
        {
            int dur = maximum() - minimum();
            int pos = maximum() - dur * ((double)ev->y() / height());
            if (pos != sliderPosition())
            {
                setValue(pos);
            }
        }
    }
    else//horizontal
    {
        if (ev->button() == Qt::LeftButton)
        {
            int dur = maximum() - minimum();
            int pos = minimum() + dur * ((double)ev->x() / width());
            if (pos != sliderPosition())
            {
                setValue(pos);
            }
        }
    }

    QSlider::mousePressEvent(ev);
}
