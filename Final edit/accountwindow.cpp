#include "accountwindow.h"
#include "ui_accountwindow.h"
#include<QMessageBox>
#include"Global_data_variables.h"
#include<math.h>

#include<QDateTime>
#include<QLabel>

accountwindow::accountwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::accountwindow)
{
    this->setFixedSize(332,405);
    ui->setupUi(this);
    QLabel* lbl1 = new QLabel(this);
    lbl1->setText("نوع حساب:");
    QLabel* lbl2 = new QLabel(this);
    QString lbl2txt;
    int _type = all_bank_accounts.getlist()[activeaccount]->get_type();
   // qDebug()<<_type;
    if(_type==1){
         lbl2txt = "س.قرض الحسنه";
    }
    else if(_type==2){
         lbl2txt = "س.س.كوتاه مدت";
    }
    else if(_type==3){
        lbl2txt = "س.كوتاه مدت حقوقی";
    }
    else if(_type==4){
        lbl2txt = "س.س.بلند مدت";
    }

    lbl2->setText(lbl2txt);
    lbl1->setGeometry(225,2,100,50);
    lbl2->setGeometry(225,15,100,50);
    if(all_bank_accounts.getlist()[activeaccount]->get_card().get_cardnum()!="0"){
        ui->pushButton_6->setText("مشخصات کارت");
    }
    all_bank_accounts.getlist()[activeaccount]->calculateInterest();
}

accountwindow::~accountwindow()
{
    delete ui;
}

void accountwindow::on_pushButton_clicked()
{
    QMessageBox msg;
    QString text = "موجودی:  "+QString::number(all_bank_accounts.getlist()[activeaccount]->get_balance(),'f')+" تومان";
    msg.setText(text);
    msg.exec();

}

void accountwindow::on_pushButton_2_clicked()
{
    acctransdialog = new accountlistoftransactionsDialog(this);
    acctransdialog->show();
}

void accountwindow::on_pushButton_3_clicked()
{
    if( all_bank_accounts.getlist()[activeaccount]->get_card().get_cardnum()!="0"){
    QString _pin="";
    srand(time(NULL));
    for(int i=0;i<6;i++){
        int random = rand()%10;
         _pin+=QString::number(random);
    }

    all_bank_accounts.getlist()[activeaccount]->get_card().set_dynamic_pin(_pin);
    all_bank_accounts.getlist()[activeaccount]->get_card().set_pin_time(QTime::currentTime());
    QMessageBox msg;
    msg.setText(_pin);
    msg.exec();}
    else {
        QMessageBox msg2;
        msg2.setText("حساب شما فاقد کارت معتبر میباشد");
        msg2.exec();
    }

}

void accountwindow::on_pushButton_6_clicked()
{
    qDebug()<<all_bank_accounts.getlist()[activeaccount]->get_card().get_expiration();

    if(all_bank_accounts.getlist()[activeaccount]->requestCard()==false)
{
        if(all_bank_accounts.getlist()[activeaccount]->get_type()==4){
            QMessageBox msg;
            msg.setText("حساب شما قابلیت درخواست کارت ندارد");
            msg.exec();
        }
        else{

            QMessageBox msg2;
            QString txt = "شماره کارت:"+all_bank_accounts.getlist()[activeaccount]->get_card().get_cardnum()+"||cvv2:"+all_bank_accounts.getlist()[activeaccount]->get_card().get_cvvt()+"||تاریخ انقضا: "+QString::number(all_bank_accounts.getlist()[activeaccount]->get_card().get_expiration().year())+"/"+QString::number(all_bank_accounts.getlist()[activeaccount]->get_card().get_expiration().month());
            msg2.setText(txt);
            msg2.exec();
        }

    }
    else{
        QMessageBox msg3;
        if(all_bank_accounts.getlist()[activeaccount]->get_request_flag()==0){
            Card_request req;
            req.set_acc_num(all_bank_accounts.getlist()[activeaccount]->getacc_num());
            req.set_time_of_request(QDateTime::currentDateTime());
            all_cardrequests.add_request(req);

        all_bank_accounts.getlist()[activeaccount]->set_request_flag(1);
        msg3.setText("درخواست شما ارسال شد");
        save();
        }
        else {
            msg3.setText("درخواست شمادر حال پردازش است");
        }
        msg3.exec();

    }

   // else if
}

void accountwindow::on_pushButton_5_clicked()
{
    montransdialog = new moneytransferdialog(this);
    montransdialog->show();
}

void accountwindow::on_pushButton_4_clicked()
{
    p = new paymentGateWay;
    p->show();
}

void accountwindow::on_pushButton_7_clicked()
{
    this->close();
}
