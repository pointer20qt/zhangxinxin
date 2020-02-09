#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <qDebug>
#include <QSqlQuery>
#include <QCheckBox>
#include <QDateTime>
#include <QMessageBox>
#include "person.h"
#include "entersign.h"
#include <QGraphicsOpacityEffect>

Widget::Widget(QWidget *parent, QString cur_sno) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("请进行签到");
    this->resize(800,510);
    ui->widget->resize(800,510);
    ui->tableWidget->resize(790,510);
    QGraphicsOpacityEffect *opacityEffect2=new QGraphicsOpacityEffect;
    ui->widget->setGraphicsEffect(opacityEffect2);
    opacityEffect2->setOpacity(0.6);

    ui->tableWidget->setStyleSheet("background-color:rgba(0,0,0,0)");
    QGraphicsOpacityEffect *opacityEffect1=new QGraphicsOpacityEffect;
    ui->lineEdit->setGraphicsEffect(opacityEffect1);
    opacityEffect1->setOpacity(0.7);

    ui->pushButton->setFlat(true);

    //将学号进行新的学号进行新的命名
    this->cur_sno = cur_sno;

    enterdate();

    createtable("select * from studentInfo");

    displayClass();

    displaySno();

    connect(ui->tableWidget,QTableWidget::cellDoubleClicked,[=](int r,int c){
        Person *p = new Person;
        p->init(ui->tableWidget->item(r,0)->text(),ui->tableWidget->item(r,1)->text());
        p->show();

    });
}

void Widget::enterdate()
{
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

}

//将数据显示到表格中
void Widget::createtable(QString sql)
{
    QSqlQuery q;

    if(q.exec(sql))
    {
        //q.next();
        //没有这个next时，在刚开始时在一个的上边的位置，在最后一条的时候.next也会有错
        ui->tableWidget->setRowCount(q.size());//设置表中的行数，q.size是返回行数
        int i=0;//第0行
        while (q.next())
        {
            //qDebug()<<q.value(0);
            //将xx放在某行某列
            QCheckBox *c=new QCheckBox("未签到");
            QString sno=q.value(0).toString();
            //q.value(0).toString();将q.value(0)转换成字符串类型

            QSqlQuery q2;
            q2.exec(QString("select sig_time from sigInfo "
                            "where sno = '%1' and date(sig_time)=curdate()"
                            "order by sig_time desc").arg(sno));//curdate() 与date()返回当前日期，格式如下：2013-01-17
            q2.next();

            //学号不相等的选项不可进行改变
            if(sno!=cur_sno)
            {
                c->setDisabled(true);
            }

            if(q2.size())
            {
               c->setText("已签到");
               c->setDisabled(true);
               c->setChecked(true);
               ui->tableWidget->setItem(i,4,new QTableWidgetItem(q2.value(0).toString()));
            }

            ui->tableWidget->setItem(i,0,new QTableWidgetItem(sno));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(q.value(1).toString()));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(q.value(2).toString()));
            ui->tableWidget->setCellWidget(i,3,c);

            connect(c,QCheckBox::clicked,[=](){
                //1.修改控件本身状态
                c->setText("已签到");
                c->setDisabled(true);
                //2.向表格中添加签到时间
                ui->tableWidget->setItem(i,4,new QTableWidgetItem(QDateTime::currentDateTime().toString()));
                //3.向数据库中插入数据
                QSqlQuery q1;
                //%1,'%2'，占位符(arg函数)
                qDebug()<<q1.exec(QString("insert into sigInfo values('%1',now())").arg(sno));
            });
            i++;
        }
    }
}
//按照班级显示
void Widget::displayClass()
{
    QSqlQuery q3;
    q3.exec("select distinct class from studentInfo");
    ui->comboBox->addItem("全部班级");
    while(q3.next())
    {
        ui->comboBox->addItem(q3.value(0).toString());
    }
    connect(ui->comboBox,QComboBox::currentTextChanged,[=](QString text){
        if(text=="全部班级")
        {
            createtable("select * from studentInfo");
        }
        else
        {
            createtable(QString("select * from studentInfo where class = '%1'").arg(text));
        }
    });
}
//按照学号显示
void Widget::displaySno()
{
    connect(ui->pushButton,QPushButton::clicked,[=](){
        if(ui->lineEdit->text().isEmpty())
        {
            QMessageBox::warning(this,"warn","您输入为空");
        }
        else
        {
            createtable(QString("select * from studentInfo where sno like '%1'").arg(ui->lineEdit->text()));
        }
    });

}

Widget::~Widget()
{
    delete ui;
}









