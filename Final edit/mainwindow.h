#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"bank_account.h"
#include"list_of_bankaccounts.h"
#include"savingsaccount.h"
#include"longterminvestment.h"
#include"shortterminvestment.h"
#include"shorttermsharedinvestment.h"
#include"Global_data_variables.h"
#include<QFile>
#include"accountwindow.h"
#include"accountlistoftransactionsdialog.h"
#include"main_user.h"
#include"admin_ui.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
   // list_of_bankaccounts list;
   //  list_of_bankaccounts bank_accounts;
    Ui::MainWindow *ui;
    accountwindow *acc_window;
    main_User* userwindow;
    admin_ui* admin_window;

};
#endif // MAINWINDOW_H
