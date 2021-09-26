#include "moneytransferdialog.h"
#include "ui_moneytransferdialog.h"
#include"Global_data_variables.h"
#include<QMessageBox>

moneytransferdialog::moneytransferdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::moneytransferdialog)
{
    this->setFixedSize(439,127);
    ui->setupUi(this);
}

moneytransferdialog::~moneytransferdialog()
{
    delete ui;
}

void moneytransferdialog::on_pushButton_2_clicked()
{
    this->close();
}

void moneytransferdialog::on_pushButton_clicked()
{
   QString inputacc= ui->lineEdit->text();
   double ammount = ui->lineEdit_2->text().toDouble();
   int index;
    index= all_bank_accounts.search(inputacc);
    if(index==-1){
        QMessageBox msg;
        msg.setText("حساب مورد نظر یافت نشد");
        msg.exec();
    }
    else{
        QMessageBox msg2;
        QString detail;
        for(int i=0;i<all_bank_accounts.getlist()[index]->get_userslist().size();i++){
        QString userncode = all_bank_accounts.getlist()[index]->get_userslist()[i];
        int userindex = all_users.search(userncode);
         detail += all_users.get_list()[userindex].get_name()+"/";}
        detail+="\n";
        detail+="مبلغ: "+QString::number(ammount);
        msg2.setDetailedText(detail);
        msg2.setText("از انتقال به این حساب مطمين هستید؟");
        msg2.setStandardButtons(QMessageBox::Yes);
        msg2.addButton(QMessageBox::No);
        msg2.setDefaultButton(QMessageBox::No);

        int ret = msg2.exec();
        if(ret==QMessageBox::Yes){
            bool s =all_bank_accounts.getlist()[activeaccount]->transferMoneyViaAccount(all_bank_accounts.getlist()[index]->getacc_num(),ammount);
            if(s==false){
                QMessageBox msg4;
                msg4.setText("موجودی کافی نیست");
                msg4.exec();
            }
            else if(all_bank_accounts.getlist()[activeaccount]->get_status()==1){
                QMessageBox msg4;
                msg4.setText("حساب شما مسدود است");
                msg4.exec();
            }
            else{
            Transaction tr;

            tr.set_origin(all_bank_accounts.getlist()[activeaccount]->getacc_num());
            tr.set_type(1);
            tr.set_amount(ammount);
            tr.set_destination(all_bank_accounts.getlist()[index]->getacc_num());
            tr.set_time(QDateTime::currentDateTime());
            all_transactions.add_transaction(tr);
            all_bank_accounts.getlist()[index]->add_transaction(tr);
            all_bank_accounts.getlist()[activeaccount]->add_transaction(tr);
            QMessageBox msg3;
            msg3.setText("انتقال با موفقیت انجام شد");
            msg3.exec();
         /*  Smtp* smtp;
           smtp = new Smtp("bankmanagementproject711@gmail.com","Bankproject121212","smtp.gmail.com",465);
           connect(smtp,SIGNAL(status(QString)),this,SLOT(mailSent(QString)));
           QString sent = "Transaction was made\n";
           sent+="from: "+all_bank_accounts.getlist()[activeaccount]->getacc_num()+"\n";
           sent+="to: "+all_bank_accounts.getlist()[index]->getacc_num()+"\n";
           sent+="ammount: "+QString::number(ammount)+"\n";
           sent+="time: "+tr.get_trans_time().toString()+"\n";

           smtp->sendMail("bankmanagementproject711@gmail.com",all_users.get_list()[activeuser].get_email(),"transaction",sent);
           smtp->sendMail("bankmanagementproject711@gmail.com",all_users.get_list()[index].get_email(),"transaction",sent);
*/
            save();}
        }

    }
}

void moneytransferdialog::mailSent(QString status)
{
    if(status=="Message sent")
        QMessageBox::warning(0,tr("Qt Simple SMTP client"),tr("Message sent:\n\n"));
}
