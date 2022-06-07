#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "signinpage.h"
#include "teapage.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    change();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::change()
{
    this->hide();
    s = new signinpage;
    s->show();
}
