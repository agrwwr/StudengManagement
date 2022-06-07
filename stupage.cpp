#include "stupage.h"
#include "ui_stupage.h"

stupage::stupage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::stupage)
{
    ui->setupUi(this);

    this->mydatabase.getConnection();
    this->dataTableModel = new QStandardItemModel();
    this->dataTableModel2 = new QStandardItemModel();
    this->dataTableModel3 = new QStandardItemModel();
    this->setWindowTitle("学生个人中心");

    ui->stackedWidget->setCurrentIndex(2);

    setComboboxText();

}

stupage::~stupage()
{
    delete ui;
}

void stupage::setTableInfo_tabview1()
{
    this->dataTableModel->setHorizontalHeaderItem(0,new QStandardItem("id"));
    this->dataTableModel->setHorizontalHeaderItem(1,new QStandardItem("name"));
    this->dataTableModel->setHorizontalHeaderItem(2,new QStandardItem("total"));
    this->dataTableModel->setHorizontalHeaderItem(3,new QStandardItem("高等数学"));
    this->dataTableModel->setHorizontalHeaderItem(4,new QStandardItem("高级语言程序设计"));
    this->dataTableModel->setHorizontalHeaderItem(5,new QStandardItem("离散数学"));
    this->dataTableModel->setHorizontalHeaderItem(6,new QStandardItem("大学物理"));

    ui->tableView->setModel(this->dataTableModel);

    ui->tableView->setColumnWidth(0,100);
    ui->tableView->setColumnWidth(1,100);
    ui->tableView->setColumnWidth(2,100);
    ui->tableView->setColumnWidth(3,100);
    ui->tableView->setColumnWidth(4,150);
    ui->tableView->setColumnWidth(5,100);
    ui->tableView->setColumnWidth(6,100);
}

void stupage::getDatabaseInfo_tabview1()
{
    QSqlQuery sql;
    sql.prepare("select * from student where SId = :id");
    sql.bindValue(":id",this->id);
    sql.exec();

    int row = 0;
    while(sql.next())
    {
        this->dataTableModel->setItem(row,0,new QStandardItem(sql.value("SId").toString()));
        this->dataTableModel->setItem(row,1,new QStandardItem(sql.value("Sname").toString()));
        this->dataTableModel->setItem(row,2,new QStandardItem(sql.value("Ssex").toString()));
    }
    sql.clear();

    sql.prepare("select * from sc where SId = :SId and CId = :CId");
    sql.bindValue(":SId",this->id);
    sql.bindValue(":CId",01);
    sql.exec();
    if(sql.first())                   //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    {
        this->dataTableModel->setItem(row,3,new QStandardItem(sql.value("score").toString()));
    }
    sql.clear();

    sql.prepare("select * from sc where SId = :SId and CId = :CId");
    sql.bindValue(":SId",this->id);
    sql.bindValue(":CId",02);
    sql.exec();
    if(sql.first())                   //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    {
        this->dataTableModel->setItem(row,4,new QStandardItem(sql.value("score").toString()));
    }
    sql.clear();

    sql.prepare("select * from sc where SId = :SId and CId = :CId");
    sql.bindValue(":SId",this->id);
    sql.bindValue(":CId",03);
    sql.exec();
    if(sql.first())                   //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    {
        this->dataTableModel->setItem(row,5,new QStandardItem(sql.value("score").toString()));
    }
    sql.clear();

    sql.prepare("select * from sc where SId = :SId and CId = :CId");
    sql.bindValue(":SId",this->id);
    sql.bindValue(":CId",04);
    sql.exec();
    if(sql.first())                   //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    {
        this->dataTableModel->setItem(row,6,new QStandardItem(sql.value("score").toString()));
    }
    sql.clear();
}

void stupage::setTableInfo_tabview2()
{
    this->dataTableModel2->setHorizontalHeaderItem(0,new QStandardItem("CId"));
    this->dataTableModel2->setHorizontalHeaderItem(1,new QStandardItem("Course_name"));
    this->dataTableModel2->setHorizontalHeaderItem(2,new QStandardItem("Teacher"));
    this->dataTableModel2->setHorizontalHeaderItem(3,new QStandardItem("Time"));
    this->dataTableModel2->setHorizontalHeaderItem(4,new QStandardItem("Site"));

    ui->tableView_2->setModel(this->dataTableModel2);

    ui->tableView_2->setColumnWidth(0,100);
    ui->tableView_2->setColumnWidth(1,200);
    ui->tableView_2->setColumnWidth(2,100);
    ui->tableView_2->setColumnWidth(3,150);
    ui->tableView_2->setColumnWidth(4,100);
}

void stupage::getDatabaseInfo_tabview2()
{
    QSqlQuery sql;
    sql.prepare("select * from course");

    sql.exec();

    int row = 0;
    while(sql.next())
    {
        this->dataTableModel2->setItem(row,0,new QStandardItem(sql.value("CId").toString()));
        this->dataTableModel2->setItem(row,1,new QStandardItem(sql.value("Cname").toString()));
        this->dataTableModel2->setItem(row,3,new QStandardItem(sql.value("Time").toString()));
        this->dataTableModel2->setItem(row,4,new QStandardItem(sql.value("Site").toString()));
        row++;
    }
    sql.clear();

    sql.prepare("select * from teacher t join course c on t.TId = c.TId and CId = :CId");
    sql.bindValue(":CId",01);
    sql.exec();
    if(sql.first())                   //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    {
        this->dataTableModel2->setItem(0,2,new QStandardItem(sql.value("Tname").toString()));
    }
    sql.clear();

    sql.prepare("select * from teacher t join course c on t.TId = c.TId and CId = :CId");
    sql.bindValue(":CId",02);
    sql.exec();
    if(sql.first())                   //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    {
        this->dataTableModel2->setItem(1,2,new QStandardItem(sql.value("Tname").toString()));
    }
    sql.clear();

    sql.prepare("select * from teacher t join course c on t.TId = c.TId and CId = :CId");
    sql.bindValue(":CId",03);
    sql.exec();
    if(sql.first())                   //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    {
        this->dataTableModel2->setItem(2,2,new QStandardItem(sql.value("Tname").toString()));
    }
    sql.clear();

    sql.prepare("select * from teacher t join course c on t.TId = c.TId and CId = :CId");
    sql.bindValue(":CId",04);
    sql.exec();
    if(sql.first())                   //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    {
        this->dataTableModel2->setItem(3,2,new QStandardItem(sql.value("Tname").toString()));
    }
    sql.clear();
}

void stupage::setTableInfo_tabview3()
{
    this->dataTableModel3->setHorizontalHeaderItem(0,new QStandardItem("CId"));
    this->dataTableModel3->setHorizontalHeaderItem(1,new QStandardItem("Course_name"));
    this->dataTableModel3->setHorizontalHeaderItem(2,new QStandardItem("Credit"));
    this->dataTableModel3->setHorizontalHeaderItem(3,new QStandardItem("Time"));
    this->dataTableModel3->setHorizontalHeaderItem(4,new QStandardItem("Period"));

    ui->tableView_3->setModel(this->dataTableModel3);

    ui->tableView_3->setColumnWidth(0,100);
    ui->tableView_3->setColumnWidth(1,200);
    ui->tableView_3->setColumnWidth(2,100);
    ui->tableView_3->setColumnWidth(3,100);
    ui->tableView_3->setColumnWidth(4,100);
}

void stupage::getDatabaseInfo_tabview3()
{
    QSqlQuery sql;
    sql.prepare("select * from project");
    sql.exec();

    int row = 0;
    while(sql.next())
    {
        this->dataTableModel3->setItem(row,0,new QStandardItem(sql.value("CId").toString()));
        this->dataTableModel3->setItem(row,1,new QStandardItem(sql.value("Cname").toString()));
        this->dataTableModel3->setItem(row,2,new QStandardItem(sql.value("Credit").toString()));
        this->dataTableModel3->setItem(row,3,new QStandardItem(sql.value("Time").toString()));
        this->dataTableModel3->setItem(row,4,new QStandardItem(sql.value("Period").toString()));
        row++;
    }
    sql.clear();
}

void stupage::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    this->setTableInfo_tabview1();
    this->getDatabaseInfo_tabview1();
}

void stupage::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    this->setTableInfo_tabview2();
    this->getDatabaseInfo_tabview2();
}

void stupage::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    this->setTableInfo_tabview3();
    this->getDatabaseInfo_tabview3();
}

void stupage::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void stupage::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);


    QSqlQuery sql;
    sql.prepare("select * from student where SId = :SId");
    sql.bindValue(":SId",this->id);
    sql.exec();

    if(sql.first())
    {
        ui->label_9->setText(sql.value("Sname").toString());
        ui->label_11->setText(sql.value("SId").toString());
        ui->label_13->setText(sql.value("Stel").toString());
        ui->label_15->setText(sql.value("Shome").toString());
        ui->label_17->setText(sql.value("Ssex").toString());
        ui->label_20->setText(sql.value("Id").toString());
        ui->label_21->setText(sql.value("Sinstitude").toString());
    }
    sql.clear();
}

void stupage::on_pushButton_6_clicked()
{
    modifypassword *mp = new modifypassword;
    mp->id = this->id;
    mp->p = 0;
    mp->show();
}

void stupage::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

    QSqlQuery sql;
    sql.prepare("select * from student where SId = :SId");
    sql.bindValue(":SId",this->id);
    sql.exec();

    if(sql.first())
    {
        ui->lineEdit_4->setText(sql.value("Sname").toString());
        ui->label_22->setText(sql.value("SId").toString());
        ui->lineEdit_2->setText(sql.value("Shome").toString());
        ui->lineEdit_3->setText(sql.value("Stel").toString());
        ui->lineEdit_5->setText(sql.value("Id").toString());

        if(sql.value("Ssex").toString() == "男")
        {
            ui->radioButton->click();
        }
        else
        {
            ui->radioButton_2->click();
        }


    }
    sql.clear();

}

void stupage::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void stupage::setComboboxText()
{
    QSqlQuery sql;
    sql.prepare("select * from institude");
    sql.exec();

    while(sql.next())
    {
        qDebug()<<sql.value("Iname").toString();
        ui->comboBox->addItem(sql.value("Iname").toString());

    }
    sql.clear();
}

void stupage::setInformationSave()
{
    QSqlQuery sql;
    sql.prepare("update student set Sname = :Sname where SId = :SId");
    sql.bindValue(":SId",this->id);
    sql.bindValue(":Sname",ui->lineEdit_4->text());
    sql.exec();
    sql.clear();

    sql.prepare("update student set Stel = :Stel  where SId = :SId");
    sql.bindValue(":SId",this->id);
    sql.bindValue(":Stel",ui->lineEdit_3->text());
    sql.exec();
    sql.clear();

    sql.prepare("update student set Shome = :Shome where SId = :SId");
    sql.bindValue(":SId",this->id);
    sql.bindValue(":Sname",ui->lineEdit_2->text());
    sql.exec();
    sql.clear();

    sql.prepare("update student set Id = :id where SId = :SId");
    sql.bindValue(":SId",this->id);
    sql.bindValue(":id",ui->lineEdit_5->text());
    sql.exec();
    sql.clear();

    sql.prepare("update student set Sinstitude = :Sinstitude where SId = :SId");
    sql.bindValue(":SId",this->id);
    sql.bindValue(":Sinstitude",ui->comboBox->currentText());
    sql.exec();
    sql.clear();

    sql.prepare("update student set Ssex = :Ssex where SId = :SId");
    sql.bindValue(":SId",this->id);
    if(ui->radioButton->isChecked())
    {
        sql.bindValue(":Ssex","男");
    }
    else
    {
        sql.bindValue(":Ssex","女");
    }
    sql.exec();
    sql.clear();

    sql.prepare("select * from student where SId = :SId");
    sql.bindValue(":SId",this->id);
    sql.exec();

    if(sql.first())
    {
        ui->label_9->setText(sql.value("Sname").toString());
        ui->label_11->setText(sql.value("SId").toString());
        ui->label_13->setText(sql.value("Stel").toString());
        ui->label_15->setText(sql.value("Shome").toString());
        ui->label_17->setText(sql.value("Ssex").toString());
        ui->label_20->setText(sql.value("Id").toString());
        ui->label_21->setText(sql.value("Sinstitude").toString());
        qDebug()<<sql.value("Sname").toString();
        qDebug()<<sql.value("SId").toString();
        qDebug()<<sql.value("Stel").toString();
        qDebug()<<sql.value("Shome").toString();
        qDebug()<<sql.value("Ssex").toString();
        qDebug()<<sql.value("Id").toString();
        qDebug()<<sql.value("Sinstitude").toString();
    }
    sql.clear();

    ui->stackedWidget->setCurrentIndex(4);
}

void stupage::on_pushButton_9_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("保存");
    msgBox.setText("The document has been modified.");
    msgBox.setInformativeText("Do you want to save your changes?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
    if(ret == QMessageBox::Save)
    {
        setInformationSave();
    }
    else
    {
        msgBox.close();
    }
}

void stupage::on_pushButton_10_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("注销");
    msgBox.setInformativeText("You sure?");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Ok);
    int ret = msgBox.exec();
    if(ret == QMessageBox::Ok)
    {
        signinpage* s = new signinpage;
        s->show();
        this->~stupage();
    }
    else
    {
        msgBox.close();
    }
}

void stupage::on_pushButton_11_clicked()
{
    QSqlQuery sql;
    sql.prepare("select * from student");
    sql.bindValue(":id",this->id);
    sql.exec();


}
