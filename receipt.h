#ifndef RECEIPT_H
#define RECEIPT_H
#include <QSqlDatabase>
#include <QDialog>
#include <ssr.h>
namespace Ui {
class receipt;
}

class receipt : public QDialog
{

    Q_OBJECT




public:
    explicit receipt(QWidget *parent = nullptr);
    ~receipt();

    void connClose();


    bool connOpen();



private slots:


    void on_pushButton_2_clicked();

private:
    Ui::receipt *ui;
};

#endif // RECEIPT_H
