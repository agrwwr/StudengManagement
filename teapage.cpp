#include "teapage.h"
#include "ui_teapage.h"

teapage::teapage(QWidget *parent,QString Uid) :
    QMainWindow(parent),
    ui(new Ui::teapage)
{
    ui->setupUi(this);

    id = Uid;

    this->mydatabase.getConnection();
    this->setWindowTitle("教师个人中心");

    this->dataTableModel = new QStandardItemModel();
    this->dataTableModel2 = new QStandardItemModel();

    getCourse();

    getCId();

    setComboBox();

    setTableInfo_tableView();

    ui->stackedWidget_2->setCurrentIndex(1);
}



teapage::~teapage()
{
    delete ui;
}

void teapage::setTableInfo_tableView()
{
    this->dataTableModel->setHorizontalHeaderItem(0,new QStandardItem("SId"));
    this->dataTableModel->setHorizontalHeaderItem(1,new QStandardItem("name"));
    this->dataTableModel->setHorizontalHeaderItem(2,new QStandardItem("institude"));
    this->dataTableModel->setHorizontalHeaderItem(3,new QStandardItem(course));

    ui->tableView->setModel(this->dataTableModel);

    ui->tableView->setColumnWidth(0,100);
    ui->tableView->setColumnWidth(1,100);
    ui->tableView->setColumnWidth(2,200);
    ui->tableView->setColumnWidth(3,150);

}

void teapage::setTableInfo_tableView2()
{
    this->dataTableModel2->setHorizontalHeaderItem(0,new QStandardItem("SId"));
    this->dataTableModel2->setHorizontalHeaderItem(1,new QStandardItem("name"));
    this->dataTableModel2->setHorizontalHeaderItem(2,new QStandardItem("institude"));
    this->dataTableModel2->setHorizontalHeaderItem(3,new QStandardItem(course));

    ui->tableView_2->setModel(this->dataTableModel2);

    ui->tableView_2->setColumnWidth(0,100);
    ui->tableView_2->setColumnWidth(1,100);
    ui->tableView_2->setColumnWidth(2,200);
    ui->tableView_2->setColumnWidth(3,150);
}

void teapage::getTabelInfo_tableView2()
{
    QSqlQuery sql;
    QString SId;
    int row = 0;
    sql.prepare("select * from student");
    sql.exec();

    while(sql.next())
    {
        this->dataTableModel2->setItem(row,0,new QStandardItem(sql.value("SId").toString()));
        this->dataTableModel2->setItem(row,1,new QStandardItem(sql.value("Sname").toString()));
        this->dataTableModel2->setItem(row,2,new QStandardItem(sql.value("Sinstitude").toString()));
        row++;
    }   
    sql.clear();

    ui->label_12->setText(QString::number(row));

    sql.prepare("select score from sc where CId = :CId");
    sql.bindValue(":CId",this->CId);
    sql.exec();

    row = 0;
    while(sql.next())               //?????????
    {
        this->dataTableModel2->setItem(row,3,new QStandardItem(sql.value("score").toString()));
        row++;
    }
    sql.clear();
}

void teapage::getCourse()
{
    QSqlQuery sql;
    sql.prepare("select Cname from course where TId = :TId");
    sql.bindValue(":TId",this->id);
    sql.exec();
    //qDebug()<<course;
    //qDebug()<<this->id;
    if(sql.first())
    {
        course = sql.value("Cname").toString();

    }
    sql.clear();
}

void teapage::setComboBox()
{
    ui->comboBox->addItem("学号");
    ui->comboBox->addItem("姓名");
}

void teapage::getCId()
{
    QSqlQuery sql;
    sql.prepare("select CId from course c join teacher t on c.TId = :TId and t.TId = :TId");
    sql.bindValue(":TId",this->id);
    sql.exec();
    if(sql.first())
    {
        this->CId = sql.value("CId").toString();
    }
    sql.clear();
}

void teapage::on_pushButton_clicked()
{
    ui->lineEdit->setText("");
    this->dataTableModel->setItem(0,0,new QStandardItem(" "));
    this->dataTableModel->setItem(0,1,new QStandardItem(" "));
    this->dataTableModel->setItem(0,2,new QStandardItem(" "));
    this->dataTableModel->setItem(0,3,new QStandardItem(" "));
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->stackedWidget->setCurrentIndex(1);
}

void teapage::on_pushButton_2_clicked()
{
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget_2->setCurrentIndex(0);
}

void teapage::on_pushButton_3_clicked()
{
    ui->lineEdit_5->setText("");
    ui->lineEdit_6->setText("");
    ui->lineEdit_7->setText("");
    ui->stackedWidget->setCurrentIndex(2);
    ui->stackedWidget_2->setCurrentIndex(0);
}

void teapage::on_pushButton_4_clicked()
{
    ui->lineEdit_8->setText("");
    ui->lineEdit_9->setText("");
    ui->stackedWidget->setCurrentIndex(3);
    ui->stackedWidget_2->setCurrentIndex(0);
}
void teapage::on_pushButton_5_clicked()
{
    this->dataTableModel->setItem(0,3,new QStandardItem(" "));
    QString searchMethod = ui->comboBox->currentText();
    QString input = ui->lineEdit->text();
    QSqlQuery sql;
    QString SId;
    qDebug()<<searchMethod;
    qDebug()<<input;
    if(searchMethod == "学号")
    {
        sql.prepare("select * from student where SId = :SId");
        sql.bindValue(":SId",input);
        sql.exec();

        if(sql.first())
        {
            this->dataTableModel->setItem(0,0,new QStandardItem(sql.value("SId").toString()));
            this->dataTableModel->setItem(0,1,new QStandardItem(sql.value("Sname").toString()));
            this->dataTableModel->setItem(0,2,new QStandardItem(sql.value("Sinstitude").toString()));
        }
        sql.clear();

        sql.prepare("select score from sc where CId = :CId and SId = :SId");
        sql.bindValue(":CId",this->CId);
        sql.bindValue(":SId",input);
        sql.exec();

        if(sql.first())               //?????????
        {
            this->dataTableModel->setItem(0,3,new QStandardItem(" "));
            this->dataTableModel->setItem(0,3,new QStandardItem(sql.value("score").toString()));
        }
        sql.clear();

    }
    else
    {
        sql.prepare("select * from student where Sname = :Sname");
        sql.bindValue(":Sname",input);
        sql.exec();

        if(sql.first())
        {
            this->dataTableModel->setItem(0,0,new QStandardItem(sql.value("SId").toString()));
            this->dataTableModel->setItem(0,1,new QStandardItem(sql.value("Sname").toString()));
            this->dataTableModel->setItem(0,2,new QStandardItem(sql.value("Sinstitude").toString()));
            SId = sql.value("SId").toString();
        }
        sql.clear();

        sql.prepare("select score from sc where CId = :CId and SId = :SId");
        sql.bindValue(":CId",this->CId);
        sql.bindValue(":SId",SId);
        sql.exec();

        if(sql.first())               //?????????
        {
            this->dataTableModel->setItem(0,3,new QStandardItem(" "));
            this->dataTableModel->setItem(0,3,new QStandardItem(sql.value("score").toString()));
        }
        sql.clear();
    }

}

void teapage::on_pushButton_6_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
}

void teapage::on_pushButton_7_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("注意");
    msgBox.setText("The score has been modified.");
    msgBox.setInformativeText("Do you want to save your changes?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
    if(ret == QMessageBox::Save)
    {
        QSqlQuery sql;
        sql.prepare("update sc set score = :score where SId = :SId and CId = :CId; ");
        sql.bindValue(":score",ui->lineEdit_4->text());
        sql.bindValue(":SId",ui->lineEdit_2->text());
        sql.bindValue(":CId",this->CId);
        sql.exec();
        sql.clear();
    }
    else
    {
        msgBox.close();
    }
}

void teapage::on_pushButton_8_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
}

void teapage::on_pushButton_9_clicked()
{
        QSqlQuery sql;
        QString SId = ui->lineEdit_6->text();
        QString CId = this->CId;
        QString score = ui->lineEdit_7->text();
        QString sqlstate = QString("insert into sc(SId,CId,score) values('%1','%2','%3')").arg(SId).arg(CId).arg(score);
        //sql.prepare("insert into sc values(':SId',':CId',':score')");
        //sql.bindValue(":score",ui->lineEdit_7->text());
        qDebug()<<ui->lineEdit_7->text();                                       //?????????????????
        qDebug()<<ui->lineEdit_6->text();
        qDebug()<<this->CId;
        qDebug()<<sqlstate;
        //sql.bindValue(":SId",ui->lineEdit_6->text());
        //sql.bindValue(":CId",this->CId);
        sql.exec(sqlstate);
        sql.clear();

}

void teapage::on_pushButton_10_clicked()
{
     ui->stackedWidget_2->setCurrentIndex(1);
}

void teapage::on_pushButton_11_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("注意");
    msgBox.setText("The score has been deleted.");
    msgBox.setInformativeText("Do you want to save your changes?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
    if(ret == QMessageBox::Save)
    {
        QSqlQuery sql;
        sql.exec("set sql_safe_updates=0; ");
        sql.clear();
        sql.prepare("delete from sc where SId = :SId and CId = :CId");
        sql.bindValue(":SId",ui->lineEdit_9->text());
        sql.bindValue(":CId",this->CId);
        sql.exec();
        sql.clear();
    }
    else
    {
        msgBox.close();
    }
}

void teapage::on_pushButton_12_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
}

void teapage::on_pushButton_13_clicked()
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
        this->~teapage();
    }
    else
    {
        msgBox.close();
    }
}

void teapage::on_pushButton_14_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(2);
    ui->stackedWidget_3->setCurrentIndex(4);
    QSqlQuery sql;
    sql.prepare("select * from teacher");
    sql.exec();
    if(sql.first())
    {
        ui->label_10->setText(sql.value("Tname").toString());
        ui->label_14->setText(sql.value("TId").toString());
        ui->label_22->setText(sql.value("Id").toString());
        ui->label_20->setText(sql.value("Ttel").toString());
        ui->label_17->setText(sql.value("Tsex").toString());
    }

}

void teapage::on_pushButton_15_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    ui->stackedWidget_2->setCurrentIndex(0);
    setTableInfo_tableView2();
    getTabelInfo_tableView2();
    QVector<int> score;
    QSqlQuery sql;
    sql.prepare("select score from sc where CId = :CId");
    sql.bindValue(":CId",this->CId);
    sql.exec();

    while(sql.next())
    {
        score.push_back(sql.value("score").toInt());
    }
    qDebug()<<score;

    aver = QString::number(std::accumulate(score.begin(),score.end(),0)/score.size());
    sql.clear();

}

void teapage::on_pushButton_16_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("平均分");
    msgBox.setText(aver);
    msgBox.resize(300,200);
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    int ret = msgBox.exec();
    if(ret == QMessageBox::Ok)
    {
        msgBox.close();
    }
}

void teapage::on_pushButton_17_clicked()
{
    dataTableModel2->sort(3,Qt::DescendingOrder);
}

void teapage::on_pushButton_18_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(5);
    QSqlQuery sql;
    sql.prepare("select * from teacher where TId = :TId");
    sql.bindValue(":TId",this->id);
    sql.exec();

    if(sql.first())
    {
        ui->lineEdit_12->setText(sql.value("Tname").toString());
        ui->label_29->setText(sql.value("TId").toString());
        ui->lineEdit_10->setText(sql.value("Ttel").toString());
        ui->lineEdit_13->setText(sql.value("Id").toString());

        if(sql.value("Tsex").toString() == "男")
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

void teapage::on_pushButton_19_clicked()
{
    modifypassword *mp = new modifypassword;
    mp->id = this->id;
    mp->p = 1;
    mp->show();
}

void teapage::on_pushButton_21_clicked()
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
        setInfomationSave();
    }
    else
    {
        msgBox.close();
    }
}

void teapage::on_pushButton_20_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(4);
}

void teapage::setInfomationSave()
{
    QSqlQuery sql;
    sql.prepare("update teacher set Tname = :Tname where TId = :TId");
    sql.bindValue(":TId",this->id);
    sql.bindValue(":Tname",ui->lineEdit_12->text());
    sql.exec();
    sql.clear();

    sql.prepare("update teacher set Ttel = :Ttel  where TId = :TId");
    sql.bindValue(":TId",this->id);
    sql.bindValue(":Ttel",ui->lineEdit_10->text());
    sql.exec();
    sql.clear();

    sql.prepare("update teacher set Id = :id where TId = :TId");
    sql.bindValue(":TId",this->id);
    sql.bindValue(":id",ui->lineEdit_13->text());
    sql.exec();
    sql.clear();

    sql.prepare("update teacher set Tsex = :Tsex where TId = :TId");
    sql.bindValue(":TId",this->id);
    if(ui->radioButton->isChecked())
    {
        sql.bindValue(":Tsex","男");
    }
    else
    {
        sql.bindValue(":Tsex","女");
    }
    sql.exec();
    sql.clear();

    sql.prepare("select * from teacher where TId = :TId");
    sql.bindValue(":TId",this->id);
    sql.exec();

    if(sql.first())
    {
        ui->label_10->setText(sql.value("Tname").toString());
        ui->label_14->setText(sql.value("TId").toString());
        ui->label_22->setText(sql.value("Id").toString());
        ui->label_20->setText(sql.value("Ttel").toString());
        ui->label_17->setText(sql.value("Tsex").toString());
    }
    sql.clear();

    ui->stackedWidget_3->setCurrentIndex(4);
}
