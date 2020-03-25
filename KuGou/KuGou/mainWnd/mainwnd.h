#ifndef MAINWND_H
#define MAINWND_H

#include <QDialog>
#include <QMutex>
#include <QSystemTrayIcon>
#include "baseWnd/basewindow.h"
#include "topWidget/topwidgets.h"
#include "middleWidget/middlewidgets.h"
#include "bottomWidget/bottomwidgets.h"
#include <QMenu>

class mainWnd : public baseWindow {
    friend class baseWidget;
    Q_OBJECT
public:
    static mainWnd* getInstance();

public:
    mainWnd(QWidget *parent = 0);
    virtual ~mainWnd();

public:
    void setCurVol(int);
    baseWidget* middle_widget() { return &mid_widget_; }

protected:
    void InitUi();
    void InitConnect();
    void InitTrayMenu();
    void InitVolItem();
    void InitPlayItem();

protected:
    virtual void mouseDoubleClickEvent(QMouseEvent *) override;
    virtual void closeEvent(QCloseEvent *event) override;

private:
    static QMutex mutex_;                          // 实例互斥锁。
    static QAtomicPointer<mainWnd> main_wnd_;      // <使用原子指针,默认初始化为0。

    topWidgets top_widget_;
    middleWidgets mid_widget_;
    bottomWidgets bottom_widget_;

    QSystemTrayIcon system_tray_;
    QMenu tray_menu_;

    baseWidget* tray_vol_widget_;
    Slider* tray_vol_slider_;
    QRadioButton* tray_vol_btn_;
    int store_vol_value_;

signals:

public slots :
    void systemTrayActived(QSystemTrayIcon::ActivationReason reason);
    void slot_quitApp();
    void updateBtnStatus(int volume);
    void setVolSliderStatus(int volume);
    void OnTrayVolClick(bool check);

};

#endif // MAINWND_H
