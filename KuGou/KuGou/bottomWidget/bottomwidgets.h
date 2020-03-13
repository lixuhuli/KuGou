#ifndef BOTTOMWIDGETS_H
#define BOTTOMWIDGETS_H

#include "baseWnd/basewidget.h"
#include <QPushButton>
#include <QSlider>
#include <QLabel>

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

    QSlider main_slider_;

    QLabel lbl_playname_;
    QLabel lal_bposition_;
};

#endif // BOTTOMWIDGETS_H