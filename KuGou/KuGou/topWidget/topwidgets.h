#ifndef TOPWIDGETS_H
#define TOPWIDGETS_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include "baseWnd/basewidget.h"
#include "skinWidget/skinwidget.h"

class QPushButton;
class topWidgets : public baseWidget {
    Q_OBJECT
public:
    explicit topWidgets(QWidget *parent = nullptr);
    virtual ~topWidgets();

protected:
    virtual void mouseMoveEvent(QMouseEvent*);

signals:

public slots:
    void onClickSkin(bool);

protected:
    void InitUi();
    void InitConnect();

private:
    QPushButton btn_login_;
    QPushButton btn_register_;
    QPushButton m_btnregister;
    QLineEdit m_lineEdit;

    QPushButton m_btntool;
    QPushButton m_btnplaycard;
    QPushButton m_btngame;
    QPushButton m_btnmessage;
    QPushButton m_btnskin;
    QPushButton m_btnsetting;
    QPushButton m_btnmobile;
    QPushButton m_btnminiframe;
    QPushButton m_btnmini;
    QPushButton m_btnexit;

    skinWidget* skin_widget_;

};

#endif // TOPWIDGETS_H
