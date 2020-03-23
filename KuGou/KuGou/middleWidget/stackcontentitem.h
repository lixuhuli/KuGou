#ifndef STACKCONTENTITEM_H
#define STACKCONTENTITEM_H

#include <QPushButton>
#include <QLabel>

class stackContentItem : public QPushButton {
    Q_OBJECT
public:
    explicit stackContentItem(int& id, QWidget *parent = nullptr);
    virtual ~stackContentItem() {}

protected:
    void InitUi();
    void InitConnect();

    virtual void paintEvent(QPaintEvent *) override;

signals:

public slots :
    void onContentSelected(bool checked);
    void onTopButtonSelected(bool checked);

private:
    QString play_list_name_;

    QLabel* lbl_play_list_;

};

#endif // STACKCONTENTITEM_H