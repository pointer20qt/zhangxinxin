#ifndef UPDATEPWD_H
#define UPDATEPWD_H

#include <QWidget>

namespace Ui {
class UpdatePwd;
}

class UpdatePwd : public QWidget
{
    Q_OBJECT

public:
    explicit UpdatePwd(QWidget *parent = 0);
    ~UpdatePwd();

private slots:
    void on_pBtn_upp_enter_clicked();

    void on_pBtn_upp_back_clicked();

private:
    Ui::UpdatePwd *ui;
};

#endif // UPDATEPWD_H
