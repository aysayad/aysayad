#include "ui_mainwindow.h"
#include <mainwindow.h>
#include <ssr.h>
#include <receipt.h>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <Global.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QMessageBox::warning(this, "Notice", "Busses are only avaialable for students \n 1 Bus Functional\t2 Busses under maintenance",
                         QMessageBox::Ok);
    QMessageBox::warning(this, "Notice", "Double check your credentials",
                         QMessageBox::Ok);
}

MainWindow::~MainWindow()
{


    delete ui;
}


void MainWindow::on_proceed_clicked()
{
    QMessageBox::warning(this, "Notice", "Failure to attend reservation will lead to penalty",
                         QMessageBox::Ok);


    Globals::getInstance().ID = ui->lineEdit_2->text();
    Globals::getInstance().name = ui->lineEdit_3->text();






    close();
    ssr sched;
    sched.setModal(true);
    sched.exec();


}





