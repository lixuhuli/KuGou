#ifndef TOPWIDGETS_H
#define TOPWIDGETS_H

#include <QWidget>
#include <QPushButton>

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

};

#endif // TOPWIDGETS_H
