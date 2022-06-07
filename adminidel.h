#ifndef ADMINIDEL_H
#define ADMINIDEL_H

#include <QMainWindow>
#include<database.h>
#include<adminipage.h>

namespace Ui {
class adminidel;
}

class adminidel : public QMainWindow
{
    Q_OBJECT

public:
    explicit adminidel(QWidget *parent = nullptr,int p = 0);
    ~adminidel();

    int page;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::adminidel *ui;
};

#endif // ADMINIDEL_H
