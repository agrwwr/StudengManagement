#ifndef MODIFYPASSWORD_H
#define MODIFYPASSWORD_H

#include <QMainWindow>
#include<database.h>
#include<vector>
#include<algorithm>

namespace Ui {
class modifypassword;
}

class modifypassword : public QMainWindow
{
    Q_OBJECT

public:
    explicit modifypassword(QWidget *parent = nullptr);
    ~modifypassword();

    Database database;

    QString id;

    int p;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::modifypassword *ui;
};

#endif // MODIFYPASSWORD_H
