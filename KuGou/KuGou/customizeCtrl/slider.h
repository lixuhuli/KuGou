#ifndef SLIDER_H
#define SLIDER_H

#include <QSlider>

class Slider : public QSlider {
    Q_OBJECT
public:
    Slider(Qt::Orientation orientation, QWidget* parent = 0);
    virtual ~Slider() {}

protected:
    void mousePressEvent(QMouseEvent*);
};

#endif // SLIDER_H