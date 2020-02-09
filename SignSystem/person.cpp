#include "person.h"
#include "ui_person.h"
#include <QSqlQuery>
#include <QTextCharFormat>
#include <QGraphicsOpacityEffect>
#include <QDebug>

Person::Person(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Person)
{
    ui->setupUi(this);
    this->setWindowTitle("欢迎进入个人界面");

    this->resize(685,700);
    ui->widget->resize(685,700);


    QGraphicsOpacityEffect *opacityEffect1=new QGraphicsOpacityEffect;
    ui->widget->setGraphicsEffect(opacityEffect1);
    opacityEffect1->setOpacity(0.3);


}

void Person::init(QString sno,QString sname)
{
    ui->sno->setText("学号："+sno);
    ui->s_sname->setText("姓名："+sname);

    QSqlQuery q;
    q.exec(QString("select sig_time from sigInfo "
           "where sno = '%1' and date_format(sig_time,'%Y-%m')"
           "=date_format(curdate(),'%Y-%m') ").arg(sno));
    ui->label->setText("签到次数："+QString::number(q.size()));

    QTextCharFormat f;
    f.setBackground(Qt::black);
    f.setForeground(Qt::white);
    /*
    while(q.next())
    {
      ui->calendarWidget->setDateTextFormat(q.value(0).toDate(),f);
    }
    */

    QString numbers = QString::number(q.size());
    qDebug()<<numbers;
    ui->progressBar->setOrientation(Qt::Horizontal); // 水平方向
    ui->progressBar->setMinimum(0);  // 最小值
    ui->progressBar->setMaximum(356);  // 最大值
    ui->progressBar->setValue(q.size());  // 当前进度
    ui->progressBar->setAlignment(Qt::AlignRight | Qt::AlignVCenter);  // 对齐方式

    double dProgress = (ui->progressBar->value() - ui->progressBar->minimum()) * 100.0
                    / (ui->progressBar->maximum() - ui->progressBar->minimum()); // 百分比计算公式
    ui->progressBar->setFormat(QString::fromLocal8Bit("%1%").arg(QString::number(dProgress, 'f', 2)));
}

Person::~Person()
{
    delete ui;
}
