#include "register.h"
#include "ui_register.h"
#include "entersign.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QGraphicsOpacityEffect>

Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("://tutubiao.ico"));
    this->setWindowTitle("签到系统注册");

    this->resize(650,800);
    ui->widget->resize(650,800);
    QGraphicsOpacityEffect *opacityEffect=new QGraphicsOpacityEffect;
    ui->widget->setGraphicsEffect(opacityEffect);
    opacityEffect->setOpacity(0.6);

    ui->pBtn_r_back->setFlat(true);
    ui->pBtn_r_enter->setFlat(true);
}

Register::~Register()
{
    delete ui;
}

void Register::on_pBtn_r_enter_clicked()
{

    QString r_sname=ui->lE_r_sname->text();
    QString r_class=ui->lE_r_class->text();
    QString r_sno=ui->lE_r_sno->text();
    QString r_pwd=ui->lE_r_pwd->text();
    if(r_sname.isEmpty())
    {
        QMessageBox::warning(this,"提示","姓名不可为空");
    }
    if(r_class.isEmpty())
    {
        QMessageBox::warning(this,"提示","班级不可为空");
    }
    if(r_sno.isEmpty())
    {
        QMessageBox::warning(this,"提示","学号不可为空");
    }
    if(r_pwd.isEmpty())
    {
        QMessageBox::warning(this,"提示","密码不可为空");
    }

    QSqlQuery q;
    q.exec(QString("select * from studentInfo where sno = '%1'").arg(r_sno));
    if(q.next())
    {
        QMessageBox::warning(this,"提示","学号已存在");
    }
    else
    {
        QSqlQuery q1;
        q1.exec(QString("insert into studentInfo "
                        "values('%1','%2','%3','%4')").arg(r_sno).arg(r_sname).arg(r_class).arg(r_pwd));
        QMessageBox::information(this,"提示","注册成功");
        EnterSign *e = new EnterSign;
        this->close();
        e->show();
    }
}

void Register::on_pBtn_r_back_clicked()
{
    EnterSign *e = new EnterSign;
    this->close();
    e->show();
}
