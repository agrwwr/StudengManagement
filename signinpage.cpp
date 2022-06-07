#include "signinpage.h"
#include "ui_signinpage.h"
#include<QApplication>
#include<teapage.h>
#include<QMessageBox>
#include<stupage.h>
#include<adminipage.h>


signinpage::signinpage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::signinpage)
{
    ui->setupUi(this);
    this->mydatabase.getConnection();
    this->setWindowTitle("登录界面");
}

signinpage::~signinpage()
{
    delete ui;
}

void signinpage::checkinformation(QString userInputType)
{
    QString userInputNumber = ui->InputNumber->text();
    QString userInputPassword = ui->InputPassword->text();

    QSqlQuery sql;
    sql.prepare("select * from "+userInputType+" where id = :userInputNumber");
    sql.bindValue(":userInputNumber",userInputNumber);
    sql.exec();

    QString userNumber;
    QString userPassword;

    while(sql.next())
    {
        userNumber = sql.value("id").toString();
        userPassword = sql.value("password").toString();
    }
    sql.clear();

    if(userInputNumber == userNumber&&userInputPassword == userPassword&&userInputType == "signinstu")
    {
        qDebug()<<"登录成功";
        this->~signinpage();
        stupage* m = new stupage;
        m->id = userInputNumber;
        m->show();
    }
    else if(userInputNumber == userNumber&&userInputPassword == userPassword&&userInputType == "signintea")
    {
        qDebug()<<"登录成功";
        this->~signinpage();
        teapage* m = new teapage(nullptr,userInputNumber);      //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        //qDebug()<<m->id;
        //qDebug()<<userInputNumber;
        m->show();
    }
    else if(userInputNumber == userNumber&&userInputPassword == userPassword&&userInputType == "signinadmini")
    {
        qDebug()<<"登录成功";
        this->~signinpage();
        adminipage* m = new adminipage;
        m->show();
    }
    else
    {
        QMessageBox::information(this,"注意","用户名或密码不正确",QMessageBox::Ok);
    }
}

void signinpage::on_pushButton_clicked()
{
    QString userInputType;
    if(ui->radioButton->isChecked())
    {
        userInputType = "student";
    }

    else if(ui->radioButton_2->isChecked())
    {
        userInputType = "teacher";
    }

    else if(ui->radioButton_3->isChecked())
    {
        userInputType = "administrator";
    }

    else
    {
        QMessageBox::information(this,QString("注意"),QString("请选择身份!"),QMessageBox::Ok);
    }

    if(userInputType == "student")
    {
        checkinformation(QString("signinstu"));
    }

    else if(userInputType == "teacher")
    {
        checkinformation(QString("signintea"));
    }

    else if(userInputType == "administrator")
    {
        checkinformation(QString("signinadmini"));
    }
}
