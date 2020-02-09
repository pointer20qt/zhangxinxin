#include "entersign.h"
#include "ui_entersign.h"
#include "widget.h"
#include "register.h"
#include "updatepwd.h"
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QDebug>
#include<QGraphicsOpacityEffect>


EnterSign::EnterSign(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EnterSign)
{
    ui->setupUi(this);

    this->setWindowIcon(QIcon("://tutubiao.ico"));
    this->setWindowTitle("签到系统");
    this->resize(650,800);
    ui->widget->resize(650,800);


    //addDatabase中加入代开数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("sigdata");
    db.setUserName("root");
    db.setPassword("123456");

    if(db.open())
    {
        qDebug()<<"打开数据库成功";
    }
    else
    {
        qDebug()<<"打开数据库失败";
    }



    QGraphicsOpacityEffect *opacityEffect=new QGraphicsOpacityEffect;
    ui->pBtn_for->setGraphicsEffect(opacityEffect);
    opacityEffect->setOpacity(0.6);

    ui->pbtn_enter->setFlat(true);
    ui->pbt_zhuce->setFlat(true);
    ui->pBtn_for->setFlat(true);
 }

EnterSign::~EnterSign()
{
    delete ui;
}

void EnterSign::on_pbtn_enter_clicked()
{
    QString sno=ui->lE_sno->text();
    QString pwd=ui->lE_pwd->text();

    QSqlQuery q3;
    qDebug()<<q3.exec (QString("select sno,pwd from studentInfo where sno = '%1'").arg(sno));
    if(q3.next())
    {
        if(ui->lE_pwd->text()==q3.value(1))
        {
            Widget *w = new Widget(NULL,sno);
            w->cur_sno = sno;
            this->close();
            w->show();
        }
        else if(pwd.isEmpty())
        {
            QMessageBox::warning(this,"提示","密码不可为空");
        }
        else if(sno.isEmpty())
        {
            QMessageBox::warning(this,"提示","用户名不可为空");
        }
        else
        {
            QMessageBox::warning(this,"提示","密码不正确");
        }
    }
    else
    {
        QMessageBox::warning(this,"提示","用户名不存在");
    }

}

void EnterSign::on_pbt_zhuce_clicked()
{
    Register *r = new Register;
    this->close();
    r->show();
}

void EnterSign::on_pBtn_for_clicked()
{
    UpdatePwd *upp=new UpdatePwd;
    this->close();
    upp->show();
}
