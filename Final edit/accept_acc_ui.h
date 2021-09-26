#ifndef ACCEPT_ACC_UI_H
#define ACCEPT_ACC_UI_H
#include <QLabel>
#include <QPushButton>
#include <QVector>
#include "Global_data_variables.h"
#include <QGridLayout>

#include <QDialog>


namespace Ui {
class accept_acc_ui;
}

class accept_acc_ui : public QDialog
{
    Q_OBJECT

public:
    explicit accept_acc_ui(QWidget *parent = nullptr);
    ~accept_acc_ui();
public slots:
    void accept_acc();
    void decline_acc();



private:
    Ui::accept_acc_ui *ui;

    QVector<QPushButton*> pbn_accept;
    QVector<QPushButton*> pbn_decline;
//    QLabel* username_ui;
    QPushButton* yes;
    QPushButton* no;
    savingsAccount acc1;
    longTermInvestment acc4;
    shortTermInvestment acc2;
    shortTermSharedInvestment acc3;
    QList<savingsAccount> acc1arr;
    QList<longTermInvestment> acc4arr;
    QList<shortTermInvestment> acc2arr;
    QList<shortTermSharedInvestment> acc3arr;


};

#endif // ACCEPT_ACC_UI_H
