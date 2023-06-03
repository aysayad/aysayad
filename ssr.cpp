#include "ssr.h"
#include "ui_ssr.h"
#include <QMessageBox>
#include "receipt.h"
#include <receipt.h>
#include <QSqlQuery>
#include <Global.h>
#include <QDate>
#include <QSqlRecord>
#include <QDebug>
Globals::Globals(QObject *parent):QObject (parent){




}
ssr::ssr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ssr)
{



    QMessageBox::warning(this, "Notice", "Double check your reservation",
                         QMessageBox::Ok);
    ui->setupUi(this);


}

ssr::~ssr()
{
    delete ui;
}


void ssr::on_pushButton_clicked()
{

    connOpen();

    QDate currentDate = QDate::currentDate();

    QDate tomorrowDate = currentDate.addDays(1);

    QString dateString = tomorrowDate.toString(Qt::ISODate);

    if(ui->tayuman->isChecked() && ui->am->isChecked()) {

        QSqlQuery qry;

        QString route = "Tayuman to PLM";
        QString num = Globals::getInstance().ID;
        QString nam = Globals::getInstance().name;
        QString Sched = "5:30 am";


        qry.prepare("INSERT INTO reservation (Route, StudentName, StudentNo, Schedule, Date) "
                    "VALUES (:route, :nam, :num, :sched, :dateString)");
        qry.bindValue(":route", route);
        qry.bindValue(":nam", nam);
        qry.bindValue(":num", num);
        qry.bindValue(":sched", Sched);
        qry.bindValue(":dateString", dateString);
        qry.exec();

    }
    if(ui->tayuman->isChecked() && ui->pm->isChecked()) {

            QSqlQuery qry;
            QString route2 = "PLM to Tayuman";
            QString num2 = Globals::getInstance().ID;
            QString nam2 = Globals::getInstance().name;
            QString Sched2 = "4:30 pm";


            qry.prepare("INSERT INTO reservation (Route, StudentName, StudentNo, Schedule, Date) "
                        "VALUES (:route, :nam, :num, :sched, :dateString)");
            qry.bindValue(":route", route2);
            qry.bindValue(":nam", nam2);
            qry.bindValue(":num", num2);
            qry.bindValue(":sched", Sched2);
            qry.bindValue(":dateString", dateString);
            qry.exec();

    }
    if(ui->paco->isChecked() && ui->am->isChecked()) {

            QSqlQuery qry;
            QString route3 = "Paco to PLM";
            QString num3 = Globals::getInstance().ID;
            QString nam3 = Globals::getInstance().name;
            QString Sched3 = "7:30 am";


            qry.prepare("INSERT INTO reservation (Route, StudentName, StudentNo, Schedule, Date) "
                        "VALUES (:route, :nam, :num, :sched, :dateString)");
            qry.bindValue(":route", route3);
            qry.bindValue(":nam", nam3);
            qry.bindValue(":num", num3);
            qry.bindValue(":sched", Sched3);
            qry.bindValue(":dateString", dateString);
            qry.exec();
    }
    if(ui->paco->isChecked() && ui->pm->isChecked()) {

            QSqlQuery qry;
            QString route4 = "PLM to Paco";
            QString num4 = Globals::getInstance().ID;
            QString nam4 = Globals::getInstance().name;
            QString Sched4 = "6:30 pm";


            qry.prepare("INSERT INTO reservation (Route, StudentName, StudentNo, Schedule, Date) "
                        "VALUES (:route, :nam, :num, :sched, :dateString)");
            qry.bindValue(":route", route4);
            qry.bindValue(":nam", nam4);
            qry.bindValue(":num", num4);
            qry.bindValue(":sched", Sched4);
            qry.bindValue(":dateString", dateString);
            qry.exec();

            QMessageBox::warning(this, "Notice", "Do not forget to screenshot your E-Receipt",
                                 QMessageBox::Ok);



    }
    close();
    receipt rcpt;
    rcpt.setModal(true);
    rcpt.exec();


}




