#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0,QString cur_sno = NULL);
    ~Widget();
    void enterdate();
    void createtable(QString sql);
    void displayClass();
    void displaySno();
    QString cur_sno;
private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
