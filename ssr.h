#ifndef SSR_H
#define SSR_H
#include <QSqlDatabase>
#include <QDialog>

namespace Ui {
class ssr;
}

class ssr : public QDialog
{
    Q_OBJECT

public:
    explicit ssr(QWidget *parent = nullptr);
    ~ssr();

    QSqlDatabase db;
    bool connOpen() {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("D:/2nd Year PLM/final proj/BusData.db");

        if (!db.open()) {
            qDebug() << "Failed to open database";
            return false;
        } else {
            qDebug() << "Connected";
            return true;
        }

    }

    void connClose(){
        db.close();
        db.removeDatabase(QSqlDatabase::defaultConnection);
    }

private slots:
    void on_pushButton_clicked();

private:
    Ui::ssr *ui;
};

#endif // SSR_H
