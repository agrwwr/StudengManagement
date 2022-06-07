#include "adminiadd.h"
#include "ui_adminiadd.h"

adminiAdd::adminiAdd(QWidget *parent,int p) :
    QMainWindow(parent),
    ui(new Ui::adminiAdd)
{
    ui->setupUi(this);

    this->page = p;
    if(p == 0)
    {
        this->setWindowTitle("学生账户增加");
    }
    else
    {
        this->setWindowTitle("老师账户增加");
    }
    ui->stackedWidget->setCurrentIndex(page);
}

adminiAdd::~adminiAdd()
{
    delete ui;
}

void adminiAdd::on_pushButton_clicked()
{
    QMessageBox msgBox;
    msgBox.setInformativeText("You sure?");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Ok);
    int ret = msgBox.exec();
    if(ret == QMessageBox::Ok)
    {
        if(this->page == 0)
        {
            QSqlQuery sql;
            QString Ssex;
            QString SId = ui->lineEdit_5->text();
            QString Sname = ui->lineEdit_4->text();
            QString Sage = ui->lineEdit_3->text();
            QString Shome = ui->lineEdit_6->text();
            QString Stel = ui->lineEdit_2->text();
            QString Id = ui->lineEdit->text();
            QString Sinstitude = ui->lineEdit_7->text();
            QString password = ui->lineEdit_10->text();
            if(ui->radioButton->isChecked())
            {
                Ssex = "男";
            }
            else if(ui->radioButton_2->isChecked())
            {
                Ssex = "女";
            }
            QString sqlstate = QString("insert into student(SId,Sname,Sage,Ssex,Shome,Stel,Id,Sinstitude) values('%1','%2','%3','%4','%5','%6','%7','%8')").arg(SId).arg(Sname).arg(Sage).arg(Ssex).arg(Shome).arg(Stel).arg(Id).arg(Sinstitude);
            qDebug()<<sqlstate;
            sql.exec(sqlstate);
            sql.clear();

            QString sqlstate2 = QString("insert into signinstu(id,password) values('%1','%2')").arg(SId).arg(password);
            sql.exec(sqlstate2);
            sql.clear();
        }
        else if(this->page == 1)
        {
            QSqlQuery sql;
            QString Tsex;
            QString TId = ui->lineEdit_8->text();
            QString Tname = ui->lineEdit_9->text();
            QString Ttel = ui->lineEdit_12->text();
            QString Id = ui->lineEdit_11->text();
            QString password = ui->lineEdit_13->text();
            if(ui->radioButton_3->isChecked())
            {
                Tsex = "男";
            }
            else if(ui->radioButton_4->isChecked())
            {
                Tsex = "女";
            }
            QString sqlstate = QString("insert into teacher(SId,Sname,Ssex,Stel,Id) values('%1','%2','%3','%4','%5')").arg(TId).arg(Tname).arg(Tsex).arg(Ttel).arg(Id);
            sql.exec(sqlstate);
            sql.clear();

            QString sqlstate2 = QString("insert into signintea(id,password) values('%1','%2')").arg(TId).arg(password);
            sql.exec(sqlstate2);
            sql.clear();
        }
        adminipage* s = new adminipage;
        s->show();
        this->~adminiAdd();
    }
    else
    {
        msgBox.close();
    }
}

void adminiAdd::on_pushButton_2_clicked()
{
    adminipage* s = new adminipage;
    s->show();
    this->~adminiAdd();
}
