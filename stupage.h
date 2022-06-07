#ifndef STUPAGE_H
#define STUPAGE_H

#include <QMainWindow>
#include<QStandardItemModel>
#include<database.h>
#include<modifypassword.h>
#include<signinpage.h>
#include<vector>
#include<algorithm>

namespace Ui {
class stupage;
}

class stupage : public QMainWindow
{
    Q_OBJECT

public:
    explicit stupage(QWidget *parent = nullptr);
    ~stupage();

    Database mydatabase;

    QString id;

    void setTableInfo_tabview1();

    void getDatabaseInfo_tabview1();

    void setTableInfo_tabview2();

    void getDatabaseInfo_tabview2();

    void setTableInfo_tabview3();

    void getDatabaseInfo_tabview3();

    void setComboboxText();

    void setInformationSave();

    QStandardItemModel* dataTableModel;

    QStandardItemModel* dataTableModel2;

    QStandardItemModel* dataTableModel3;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

private:
    Ui::stupage *ui;

signals:
    void infomationSave();
};

#endif // STUPAGE_H
