#include "adminidel.h"
#include "ui_adminidel.h"

adminidel::adminidel(QWidget *parent,int p) :
    QMainWindow(parent),
    ui(new Ui::adminidel)
{
    ui->setupUi(this);

    this->page = p;
    if(p == 0)
    {
        this->setWindowTitle("学生账户删除");
    }
    else
    {
        this->setWindowTitle("老师账户删除");
    }

    ui->stackedWidget->setCurrentIndex(page);
}

adminidel::~adminidel()
{
    delete ui;
}

void adminidel::on_pushButton_clicked()
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
            QString sqlstate = QString("delete from student where SId = '%1'").arg(SId);
            sql.exec(sqlstate);
            sql.clear();

            QString sqlstate2 = QString("delete from signinstu where id = '%1'").arg(SId);
        }
        else if(this->page == 1)
        {
            QSqlQuery sql;
            QString Tsex;
            QString TId = ui->lineEdit_8->text();
            QString Tname = ui->lineEdit_9->text();
            QString sqlstate = QString("delete from teacher where TId = '%1'").arg(TId);
            sql.exec(sqlstate);
            sql.clear();

            QString sqlstate2 = QString("delete from signintea where id = '%1'").arg(TId);
        }
        adminipage* s = new adminipage;
        s->show();
        this->~adminidel();
    }
    else
    {
        msgBox.close();
    }

}

void adminidel::on_pushButton_2_clicked()
{
    adminipage* s = new adminipage;
    s->show();
    this->~adminidel();
}
