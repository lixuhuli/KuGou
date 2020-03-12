#ifndef TOPWIDGETS_H
#define TOPWIDGETS_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

class QPushButton;
class topWidgets : public QWidget {
    Q_OBJECT
public:
    explicit topWidgets(QWidget *parent = nullptr);

protected:
    virtual void paintEvent(QPaintEvent *e) override;
    virtual void mouseMoveEvent(QMouseEvent*);

signals:

public slots:

protected:
    void initWidget();

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

};

#endif // TOPWIDGETS_H
