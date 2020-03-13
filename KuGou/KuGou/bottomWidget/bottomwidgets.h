#ifndef BOTTOMWIDGETS_H
#define BOTTOMWIDGETS_H

#include <QLabel>
#include <QPushButton>
#include "baseWnd/basewidget.h"
#include "customizeCtrl/slider.h"

class bottomWidgets : public baseWidget {
    Q_OBJECT
public:
    explicit bottomWidgets(QWidget *parent = nullptr);
    virtual ~bottomWidgets() {}

protected:
    void InitUi();
    void InitConnect();

signals:

public slots:

private:
    QPushButton m_btnnext;
    QPushButton m_btnprevious;
    QPushButton m_btnPlay;

    Slider play_slider_;

    QLabel lbl_playname_;
    QLabel lal_bposition_;
};

#endif // BOTTOMWIDGETS_H