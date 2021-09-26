#include "Global_data_variables.h"

#include "transaction_ui.h"
#include "ui_transaction_ui.h"

transaction_ui::transaction_ui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::transaction_ui)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(5);
    QStringList headers;
    headers<<"origin account"<<"destination account"<<"amount"<<"type"<<"time of transaction";
    ui->tableWidget->setHorizontalHeaderLabels(headers);


//    glo= new QGridLayout();
//    this->setWindowTitle("لیست تراکنش ها");


    QList<Transaction> trn;
    trn=all_transactions.get_list();
    ui->tableWidget->setRowCount(trn.size());

    for(int i=0 ; i<trn.size();i++)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(trn[i].get_origin_account()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(trn[i].get_destination_account()));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(trn[i].get_amount())));
        if(trn[i].get_type()==1)
            ui->tableWidget->setItem(i,3,new QTableWidgetItem("حساب به حساب"));
        else if(trn[i].get_type()==2)  {
            ui->tableWidget->setItem(i,3,new QTableWidgetItem("کارت به کارت"));
        }

        ui->tableWidget->setItem(i,4,new QTableWidgetItem(trn[i].get_trans_time().toString("yy/M/d  h:m:s")));


//        lbl5=new QLabel(QString::number(i+1)+". ");
//        lbl1=new QLabel("origin account: "+trn[i].get_origin_account()+" ||");
//        lbl2=new QLabel("destination account: "+trn[i].get_destination_account()+" ||");
//        lbl3=new QLabel("amount: "+QString::number(trn[i].get_amount())+" ||");
//        lbl4=new QLabel("time of transaction: "+trn[i].get_trans_time().toString("yy/M/d h:m:s"));
//        glo->addWidget(lbl5,i,1,1,3);
//        glo->addWidget(lbl1,i,3,1,5);
//        glo->addWidget(lbl2,i,8,1,5);
//        glo->addWidget(lbl3,i,13,1,5);
//        glo->addWidget(lbl4,i,19,1,5);
    }
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
//    setLayout(glo);
}

transaction_ui::~transaction_ui()
{
    delete ui;
}
