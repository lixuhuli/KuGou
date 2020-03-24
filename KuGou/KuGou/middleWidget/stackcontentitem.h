#ifndef STACKCONTENTITEM_H
#define STACKCONTENTITEM_H

#include <QPushButton>
#include <QLabel>
#include <QMenu>

class stackContentItem : public QPushButton {
    Q_OBJECT
public:
    explicit stackContentItem(const QString& name, QWidget *parent = nullptr);
    virtual ~stackContentItem() {}

    void setEnabledMenuItem(bool isSetting = false); //menu!!
    void setExpand(bool expand);

protected:
    void InitUi();
    void InitConnect();
    void initMenu();

    virtual void paintEvent(QPaintEvent *) override;

signals:
    void addContentItem();
    void delContentItem(stackContentItem*);
    void needSetLayout();

public slots :
    void onContentSelected(bool checked);
    void onTopButtonSelected(bool checked);
    void onTrackMenu();  
    void onDelContentItem();

private:
    QString play_list_name_;
    QLabel* lbl_play_list_;
    QWidget* leave_widget_;
    QPushButton* top_button_;
    QMenu m_menu;

};

#endif // STACKCONTENTITEM_H