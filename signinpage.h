#ifndef SIGNINPAGE_H
#define SIGNINPAGE_H

#include <QMainWindow>
#include "database.h"
#include<QString>
#include<QDebug>

namespace Ui {
class signinpage;
}

class signinpage : public QMainWindow
{
    Q_OBJECT

public:
    explicit signinpage(QWidget *parent = nullptr);
    ~signinpage();

    Database mydatabase;

private slots:
    void on_pushButton_clicked();

    void checkinformation(QString userInputType);

signals:
    void  try_login();


private:
    Ui::signinpage *ui;
};

#endif // SIGNINPAGE_H
