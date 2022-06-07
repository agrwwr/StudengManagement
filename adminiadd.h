#ifndef ADMINIADD_H
#define ADMINIADD_H

#include <QMainWindow>
#include<database.h>
#include<adminipage.h>
#include<adminifunc.h>

namespace Ui {
class adminiAdd;
}

class adminiAdd : public QMainWindow
{
    Q_OBJECT

public:
    explicit adminiAdd(QWidget *parent = nullptr,int p = 0);
    ~adminiAdd();

    int page;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::adminiAdd *ui;
};

#endif // ADMINIADD_H
