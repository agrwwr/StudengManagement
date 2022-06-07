#include "adminifunc.h"
#include "ui_adminifunc.h"

adminifunc::adminifunc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminifunc)
{
    ui->setupUi(this);
}

adminifunc::~adminifunc()
{
    delete ui;
}
