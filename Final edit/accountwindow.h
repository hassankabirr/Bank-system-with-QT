#ifndef ACCOUNTWINDOW_H
#define ACCOUNTWINDOW_H

#include <QWidget>
#include "Global_data_variables.h"
#include"accountlistoftransactionsdialog.h"
#include"moneytransferdialog.h"
#include "paymentgateway.h"
namespace Ui {
class accountwindow;
}

class accountwindow : public QWidget
{
    Q_OBJECT

public:
    explicit accountwindow(QWidget *parent = nullptr);
    ~accountwindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::accountwindow *ui;
    accountlistoftransactionsDialog *acctransdialog;
    moneytransferdialog* montransdialog;
    paymentGateWay* p;

};

#endif // ACCOUNTWINDOW_H
