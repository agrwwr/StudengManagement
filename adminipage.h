#ifndef ADMINIPAGE_H
#define ADMINIPAGE_H

#include <QMainWindow>
#include<QStandardItemModel>
#include<database.h>
#include<adminiadd.h>
#include<signinpage.h>

namespace Ui {
class adminipage;
}

class adminipage : public QMainWindow
{
    Q_OBJECT

public:
    explicit adminipage(QWidget *parent = nullptr);
    ~adminipage();

    Database mydatabase;

    QString id;

    QStandardItemModel* dataTableModel;
    QStandardItemModel* dataTableModel2;

    void setTableInfo_tableview1();

    void getTableInfo_tableview1();

    void setTableInfo_tableview2();

    void getTableInfo_tableview2();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::adminipage *ui;
};

#endif // ADMINIPAGE_H
