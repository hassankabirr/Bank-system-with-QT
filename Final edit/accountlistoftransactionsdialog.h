#ifndef ACCOUNTLISTOFTRANSACTIONSDIALOG_H
#define ACCOUNTLISTOFTRANSACTIONSDIALOG_H

#include <QDialog>
#include "Global_data_variables.h"
namespace Ui {
class accountlistoftransactionsDialog;
}

class accountlistoftransactionsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit accountlistoftransactionsDialog(QWidget *parent = nullptr);
    ~accountlistoftransactionsDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::accountlistoftransactionsDialog *ui;
};

#endif // ACCOUNTLISTOFTRANSACTIONSDIALOG_H
