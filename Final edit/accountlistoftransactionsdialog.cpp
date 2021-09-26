#include "accountlistoftransactionsdialog.h"
#include "ui_accountlistoftransactionsdialog.h"

accountlistoftransactionsDialog::accountlistoftransactionsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::accountlistoftransactionsDialog)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(5);
    QStringList headerlabel;
    headerlabel<<"Time"<<"From(acc.number)"<<"To(acc.number)"<<"Ammount"<<"Type";
    ui->tableWidget->setHorizontalHeaderLabels(headerlabel);
    for(int i=all_bank_accounts.getlist()[activeaccount]->get_transactionslist().size()-1;i>all_bank_accounts.getlist()[activeaccount]->get_transactionslist().size()-10&&i>=0;i--){
        if(all_bank_accounts.getlist()[activeaccount]->get_transactionslist()[i].get_origin_account()!="0"){
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,new QTableWidgetItem(all_bank_accounts.getlist()[activeaccount]->get_transactionslist()[i].get_trans_time().toString()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1,new QTableWidgetItem(all_bank_accounts.getlist()[activeaccount]->get_transactionslist()[i].get_origin_account()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2,new QTableWidgetItem(all_bank_accounts.getlist()[activeaccount]->get_transactionslist()[i].get_destination_account()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,3,new QTableWidgetItem(QString::number(all_bank_accounts.getlist()[activeaccount]->get_transactionslist()[i].get_amount())));
        if(all_bank_accounts.getlist()[activeaccount]->get_transactionslist()[i].get_type()==1){
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,4,new QTableWidgetItem("حساب به حساب"));
        }
        else if(all_bank_accounts.getlist()[activeaccount]->get_transactionslist()[i].get_type()==2){
             ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,4,new QTableWidgetItem("کارت به کارت"));
        }
    }
    }
}

accountlistoftransactionsDialog::~accountlistoftransactionsDialog()
{
    delete ui;
}

void accountlistoftransactionsDialog::on_pushButton_clicked()
{
    this->close();
}
