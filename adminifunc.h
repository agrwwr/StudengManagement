#ifndef ADMINIFUNC_H
#define ADMINIFUNC_H

#include <QMainWindow>
#include<database.h>
#include<adminipage.h>

namespace Ui {
class adminifunc;
}

class adminifunc : public QMainWindow
{
    Q_OBJECT

    int page;

public:
    explicit adminifunc(QWidget *parent = nullptr);
    ~adminifunc();

private:
    Ui::adminifunc *ui;
};

#endif // ADMINIFUNC_H
