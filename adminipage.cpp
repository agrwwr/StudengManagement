#include "adminipage.h"
#include "ui_adminipage.h"

adminipage::adminipage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminipage)
{
    ui->setupUi(this);

    this->mydatabase.getConnection();

    this->setWindowTitle("管理员个人中心");

    this->dataTableModel = new QStandardItemModel();
    this->dataTableModel2 = new QStandardItemModel();

    setTableInfo_tableview1();
    getTableInfo_tableview1();

    setTableInfo_tableview2();
    getTableInfo_tableview2();
}

void adminipage::setTableInfo_tableview1()
{
    this->dataTableModel->setHorizontalHeaderItem(0,new QStandardItem("SId"));
    this->dataTableModel->setHorizontalHeaderItem(1,new QStandardItem("Sname"));
    this->dataTableModel->setHorizontalHeaderItem(2,new QStandardItem("Ssex"));
    this->dataTableModel->setHorizontalHeaderItem(3,new QStandardItem("Sage"));
    this->dataTableModel->setHorizontalHeaderItem(4,new QStandardItem("Stel"));
    this->dataTableModel->setHorizontalHeaderItem(5,new QStandardItem("Shome"));
    this->dataTableModel->setHorizontalHeaderItem(6,new QStandardItem("Id"));
    this->dataTableModel->setHorizontalHeaderItem(7,new QStandardItem("Sinstitude"));

    ui->tableView->setModel(this->dataTableModel);

    ui->tableView->setColumnWidth(0,100);
    ui->tableView->setColumnWidth(1,100);
    ui->tableView->setColumnWidth(2,100);
    ui->tableView->setColumnWidth(3,200);
    ui->tableView->setColumnWidth(4,200);
    ui->tableView->setColumnWidth(5,200);
    ui->tableView->setColumnWidth(6,200);
    ui->tableView->setColumnWidth(7,200);
}

void adminipage::getTableInfo_tableview1()
{
    QSqlQuery sql;
    sql.prepare("select * from student");
    sql.exec();

    int row = 0;
    while(sql.next())
    {
        this->dataTableModel->setItem(row,0,new QStandardItem(sql.value("SId").toString()));
        this->dataTableModel->setItem(row,1,new QStandardItem(sql.value("Sname").toString()));
        this->dataTableModel->setItem(row,2,new QStandardItem(sql.value("Ssex").toString()));
        this->dataTableModel->setItem(row,3,new QStandardItem(sql.value("Sage").toString()));
        this->dataTableModel->setItem(row,4,new QStandardItem(sql.value("Stel").toString()));
        this->dataTableModel->setItem(row,5,new QStandardItem(sql.value("Shome").toString()));
        this->dataTableModel->setItem(row,6,new QStandardItem(sql.value("Id").toString()));
        this->dataTableModel->setItem(row,7,new QStandardItem(sql.value("Sinstitude").toString()));
        row++;
    }
    sql.clear();

    ui->label_2->setText(QString::number(row));
}

void adminipage::setTableInfo_tableview2()
{
    this->dataTableModel2->setHorizontalHeaderItem(0,new QStandardItem("TId"));
    this->dataTableModel2->setHorizontalHeaderItem(1,new QStandardItem("Tname"));
    this->dataTableModel2->setHorizontalHeaderItem(2,new QStandardItem("Tsex"));
    this->dataTableModel2->setHorizontalHeaderItem(3,new QStandardItem("Ttel"));
    this->dataTableModel2->setHorizontalHeaderItem(4,new QStandardItem("Id"));

    ui->tableView_2->setModel(this->dataTableModel2);

    ui->tableView_2->setColumnWidth(0,100);
    ui->tableView_2->setColumnWidth(1,100);
    ui->tableView_2->setColumnWidth(2,100);
    ui->tableView_2->setColumnWidth(3,100);
    ui->tableView_2->setColumnWidth(4,200);
}

void adminipage::getTableInfo_tableview2()
{
    QSqlQuery sql;
    sql.prepare("select * from teacher");
    sql.exec();

    int row = 0;
    while(sql.next())
    {
        this->dataTableModel2->setItem(row,0,new QStandardItem(sql.value("TId").toString()));
        this->dataTableModel2->setItem(row,1,new QStandardItem(sql.value("Tname").toString()));
        this->dataTableModel2->setItem(row,2,new QStandardItem(sql.value("Tsex").toString()));
        this->dataTableModel2->setItem(row,3,new QStandardItem(sql.value("Ttel").toString()));
        this->dataTableModel2->setItem(row,4,new QStandardItem(sql.value("Id").toString()));
        row++;
    }
    sql.clear();

    ui->label_4->setText(QString::number(row));
}

adminipage::~adminipage()
{
    delete ui;
}

void adminipage::on_pushButton_clicked()
{
    this->~adminipage();

    if(ui->tabWidget->currentIndex() == 0)
    {
        adminiAdd* s = new adminiAdd(nullptr,0);
        s->show();
    }
    else
    {
        adminiAdd* s = new adminiAdd(nullptr,1);
        s->show();
    }
}

void adminipage::on_pushButton_4_clicked()
{
    this->~adminipage();

    if(ui->tabWidget->currentIndex() == 0)
    {
        adminiAdd* s = new adminiAdd(nullptr,0);
        s->show();
    }
    else
    {
        adminiAdd* s = new adminiAdd(nullptr,1);
        s->show();
    }
}

void adminipage::on_pushButton_2_clicked()
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
        this->~adminipage();
    }
    else
    {
        msgBox.close();
    }
}
