#include "modifypassword.h"
#include "ui_modifypassword.h"

modifypassword::modifypassword(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::modifypassword)
{
    ui->setupUi(this);

    database.getConnection();

    this->setWindowTitle("修改密码");
}

modifypassword::~modifypassword()
{
    delete ui;
}

void modifypassword::on_pushButton_clicked()
{
    QString original = ui->lineEdit_2->text();
    qDebug()<<original;
    QVector<QString> data;
    QString op;
    QSqlQuery sql;

    if(p == 0)
    {
        QString op;
        QSqlQuery sql;
        sql.prepare("select password from signinstu where id = :id");
        sql.bindValue(":id",this->id);
        sql.exec();
        if(sql.first())
        {
            op = sql.value("password").toString();
            qDebug()<<op<<op;
        }
        sql.clear();

        if(original == op)
        {

            QMessageBox msgBox;
            msgBox.setText("The password has been modified.");
            msgBox.setWindowTitle("注意");
            msgBox.setInformativeText("Do you want to save your changes?");
            msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
            msgBox.setDefaultButton(QMessageBox::Save);
            int ret = msgBox.exec();
            if(ret == QMessageBox::Save)
            {

                sql.prepare("update signinstu set password = :password where id = :id");
                sql.bindValue(":id",this->id);
                sql.bindValue(":password",ui->lineEdit->text());
                sql.exec();
                sql.clear();

                this->close();
            }
            else
            {
                msgBox.close();
            }

        }
        else
        {
            QMessageBox msgBox;
            msgBox.setText("The original password is wrong");
            msgBox.setInformativeText("Please enter again");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.setDefaultButton(QMessageBox::Ok);
            msgBox.exec();
        }

    }
    else
    {
        QString op;

        QSqlQuery sql;
        sql.prepare("select password from signintea where id = :id");
        sql.bindValue(":id",this->id);
        sql.exec();
        if(sql.first())
        {
            op = sql.value("password").toString();
            qDebug()<<op;
        }
        sql.clear();

        if(original == op)
        {
            QMessageBox msgBox;
            msgBox.setText("The password has been modified.");
            msgBox.setWindowTitle("注意");
            msgBox.setInformativeText("Do you want to save your changes?");
            msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
            msgBox.setDefaultButton(QMessageBox::Save);
            int ret = msgBox.exec();
            if(ret == QMessageBox::Save)
            {

                sql.prepare("update signintea set password = :password where id = :id");
                sql.bindValue(":id",this->id);
                sql.bindValue(":password",ui->lineEdit->text());
                sql.exec();
                sql.clear();

                this->close();
            }
            else
            {
                msgBox.close();
            }

        }
        else
        {
            qDebug()<<op;
            QMessageBox msgBox;
            msgBox.setText("The original password is wrong");
            msgBox.setWindowTitle("注意");
            msgBox.setInformativeText("Please enter again");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.setDefaultButton(QMessageBox::Ok);
            msgBox.exec();
        }
    }
}

void modifypassword::on_pushButton_2_clicked()
{
    this->close();
}
