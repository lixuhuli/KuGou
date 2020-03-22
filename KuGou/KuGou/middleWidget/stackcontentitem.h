#ifndef STACKCONTENTITEM_H
#define STACKCONTENTITEM_H

#include <QPushButton>

class stackContentItem : public QPushButton {
    Q_OBJECT
public:
    explicit stackContentItem(QWidget *parent = nullptr);
    virtual ~stackContentItem() {}

protected:
    void InitUi();
    void InitConnect();

    virtual void paintEvent(QPaintEvent *) override;

signals:

public slots :
    void onContentSelected(bool checked);
    void onTopButtonSelected(bool checked);

};

#endif // STACKCONTENTITEM_H