#include "updatepwd.h"
#include "ui_updatepwd.h"
#include "entersign.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QGraphicsOpacityEffect>
UpdatePwd::UpdatePwd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UpdatePwd)
{
    ui->setupUi(this);
    this->setWindowTitle("密码修改");
    this->resize(800,500);
    ui->widget->resize(800,500);

    QGraphicsOpacityEffect *opacityEffect1=new QGraphicsOpacityEffect;
    opacityEffect1->setOpacity(0.6);

    ui->lineEdit->setGraphicsEffect(opacityEffect1);
    ui->lineEdit_2->setGraphicsEffect(opacityEffect1);
    ui->lineEdit_3->setGraphicsEffect(opacityEffect1);
    ui->lineEdit_4->setGraphicsEffect(opacityEffect1);
    ui->pBtn_upp_back->setFlat(true);
    ui->pBtn_upp_enter->setFlat(true);
}

UpdatePwd::~UpdatePwd()
{
    delete ui;
}

void UpdatePwd::on_pBtn_upp_enter_clicked()
{
    QString upp_sname=ui->lineEdit->text();
    QString upp_sno=ui->lineEdit_2->text();
    QString upp_class=ui->lineEdit_3->text();
    QString upp_npwd=ui->lineEdit_4->text();
    if(upp_sname.isEmpty())
    {
        QMessageBox::warning(this,"提示","姓名不可为空");
    }
    if(upp_class.isEmpty())
    {
        QMessageBox::warning(this,"提示","班级不可为空");
    }
    if(upp_sno.isEmpty())
    {
        QMessageBox::warning(this,"提示","学号不可为空");
    }
    if(upp_npwd.isEmpty())
    {
        QMessageBox::warning(this,"提示","新密码不可为空");
    }

    QSqlQuery q;
    q.exec(QString("select * from studentInfo where sno = '%1'").arg(upp_sno));
    if(q.next())
    {
        QSqlQuery q1;
        q1.exec(QString("update studentInfo set pwd = '%1' where sno = '%2'" ).arg(upp_npwd).arg(upp_sno));
        QMessageBox::information(this,"提示","密码修改成功");
        EnterSign *e = new EnterSign;
        this->close();
        e->show();

    }
    else
    {
        QMessageBox::warning(this,"提示","用户不存在");
    }
}

void UpdatePwd::on_pBtn_upp_back_clicked()
{
    EnterSign *e = new EnterSign;
    this->close();
    e->show();
}
