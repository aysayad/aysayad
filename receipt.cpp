#include "receipt.h"
#include "ui_receipt.h"

#include <Global.h>
#include <QSqlQuery>
#include <QMessageBox>

receipt::receipt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::receipt)
{
    ui->setupUi(this);


    QSqlQuery query;
    if (query.exec("SELECT StudentName, StudentNo, Date, Schedule, Route  FROM reservation")) {
        QString name, number, route, schedule, date;
        while (query.next()) {
            name = query.value("StudentName").toString();
            number = query.value("StudentNo").toString();
            route = query.value("Route").toString();
            date = query.value("Date").toString();
            schedule = query.value("Schedule").toString();



            ui->textBrowser->setText(name);
            ui->textBrowser_2->setText(number);
            ui->textBrowser_3->setText(schedule);
            ui->textBrowser_4->setText(date);
            ui->textBrowser_5->setText(route);
        }
    } else {
        qDebug() << "Query execution failed";
    }

}

receipt::~receipt()
{
    delete ui;
}




void receipt::on_pushButton_2_clicked()
{

    close();


}

