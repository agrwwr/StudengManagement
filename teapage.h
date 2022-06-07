#ifndef TEAPAGE_H
#define TEAPAGE_H

#include <QMainWindow>
#include<QStandardItemModel>
#include<database.h>
#include<signinpage.h>
#include<modifypassword.h>
#include<vector>
#include<algorithm>

namespace Ui {
class teapage;
}

class teapage : public QMainWindow
{
    Q_OBJECT

public:
    explicit teapage(QWidget *parent = nullptr, QString Uid = 0);

    ~teapage();

    Database mydatabase;

    QString id;

    QString CId;

    QString course;

    QString aver;

    QStandardItemModel* dataTableModel;
    QStandardItemModel* dataTableModel2;

    void setTableInfo_tableView();
    void setTableInfo_tableView2();

    void getTabelInfo_tableView2();

    void getCourse();

    void setComboBox();

    void getCId();

    void setInfomationSave();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_20_clicked();

private:
    Ui::teapage *ui;
};

#endif // TEAPAGE_H
