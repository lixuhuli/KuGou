#ifndef BOTTOMWIDGETS_H
#define BOTTOMWIDGETS_H

#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include "baseWnd/basewidget.h"
#include "customizeCtrl/slider.h"
#include "customizeCtrl/volumuctrl.h"

class bottomWidgets : public baseWidget {
    Q_OBJECT
public:
    explicit bottomWidgets(QWidget *parent = nullptr);
    virtual ~bottomWidgets() {}

protected:
    void InitUi();
    void InitConnect();

protected:
    virtual bool eventFilter(QObject *, QEvent *) override;

signals:

public slots:
    void updateBtnStatus(int volume);
    void OnRadioClick(bool check);

private:
    QPushButton m_btnnext;
    QPushButton m_btnprevious;
    QPushButton m_btnPlay;

    Slider play_slider_;

    QLabel lbl_playname_;
    QLabel lal_bposition_;

    QPushButton m_btnfavorite;
    QPushButton m_btndownload;
    QPushButton m_btnmore;
    QPushButton m_btnplaymode;
    QRadioButton m_btnvol;
    QPushButton m_btnequalizer;
    QPushButton m_btnlrc;
    QPushButton m_btnplaylist;

    volSliderWidget volumn_widget_;
    QTimer m_timer;
    int store_vol_;
};

#endif // BOTTOMWIDGETS_H