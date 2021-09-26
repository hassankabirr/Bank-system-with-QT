#include "accept_acc_ui.h"
#include "ui_accept_acc_ui.h"
#include "Global_data_variables.h"
#include <QDebug>
#include <QMessageBox>

accept_acc_ui::accept_acc_ui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::accept_acc_ui)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(5);
    QStringList header;
    header<<"Name"<<"Userame"<<"type"<<"accept "<<"decline";
    ui->tableWidget->setHorizontalHeaderLabels(header);





    QList<account_request> all_acc_req_list;
    QList<User> all_user_list;
    all_acc_req_list=all_accountrequests.getlist();
    all_user_list=all_users.get_list();

    ui->tableWidget->setRowCount(all_acc_req_list.size());


  //  qDebug()<<admin_accept_acc;

    for(int i=0;i<all_acc_req_list.size();i++)
    {
        QString find_txt;

        for(int j=0; j<all_user_list.size();j++)
        {
            if (all_acc_req_list[i].get_sender_ncode()==all_user_list[j].get_national_code())
            {
                ui->tableWidget->setItem(i,0,new QTableWidgetItem(all_user_list[j].get_name()));
                ui->tableWidget->setItem(i,1,new QTableWidgetItem(all_user_list[j].get_username()));
                switch (all_acc_req_list[i].get_type()) {
                case 1:
                     ui->tableWidget->setItem(i,2, new QTableWidgetItem("س.قرض الحسنه"));
                    break;



                case 2:
                    ui->tableWidget->setItem(i,2, new QTableWidgetItem("س.س.كوتاه مدت"));
                    break;
                case 3:

                    ui->tableWidget->setItem(i,2, new QTableWidgetItem("س.س.كوتاه مدت حقوقی"));
                    break;
                 case 4:
                    ui->tableWidget->setItem(i,2, new QTableWidgetItem("س.س.بلند مدت"));
                    break;


                }

                break;
            }
        }

        yes=new QPushButton("قبول");
        no=new QPushButton("رد");
        ui->tableWidget->setCellWidget(i,3,yes);
        ui->tableWidget->setCellWidget(i,4,no);

        pbn_accept.append(yes);
        pbn_decline.append(no);
        connect(yes,SIGNAL(clicked()),this,SLOT(accept_acc()));
        connect(no,SIGNAL(clicked()),this,SLOT(decline_acc()));



    }
    ui->tableWidget->resizeColumnToContents(2);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);


}

accept_acc_ui::~accept_acc_ui()
{
    delete ui;
}

void accept_acc_ui::accept_acc()
{
    QObject* t = QObject::sender();
    srand(time(NULL));
            QString acc_n="";

            for(int i=0;i<8;i++){
               int random=rand()%10;
               acc_n+=QString::number(random);
            }


    for(int i=0;i<all_accountrequests.getlist().size();i++)
    {
        if(t== pbn_accept[i])
        {
            pbn_accept[i]->hide();
            pbn_decline[i]->hide();
            pbn_accept.remove(i);
            pbn_decline.remove(i);
            QMessageBox QMB(this);
            QMB.setText("درخواست حساب پذیرفته شد");
            QMB.exec();

            Bank_account * new_acc= new Bank_account();
            int _type = all_accountrequests.getlist()[i].get_type();
            Card initial_card;
            Transaction initial_transaction;
            initial_card.set_cvvt("0");
            initial_card.set_acc_num("0");
            initial_card.set_status(0);
            initial_card.set_cardnum("0");
            QDate d(0,0,0);
            QTime t(0,0,0);
            QDateTime initial(d,t);
            initial_card.set_expiration(d);/*
            initial_transaction.set_origin("0");
            initial_transaction.set_destination("0");
            initial_transaction.set_amount(0);
            initial_transaction.set_type(0);
            initial_transaction.set_time(initial);
*/
            if(_type==1){
                acc1.set_card(initial_card);
                acc1.set_type(1);
                acc1.set_status(0);
                acc1.set_balance(all_accountrequests.getlist()[i].getbalance());
                acc1.set_no_users(all_accountrequests.getlist()[i].get_nousers());
                QDateTime exp = QDateTime::currentDateTime();
                acc1.set_sub_date(exp);
                acc1.set_userlist(all_accountrequests.getlist()[i].get_users_ids());
                acc1.setacc_number(acc_n);
 //               acc1.add_transaction(initial_transaction);
                acc1.set_request_flag(0);
                acc1arr.append(acc1);
                new_acc = &acc1arr[acc1arr.size()-1];

            }
            else if(_type==2){
               acc2.set_card(initial_card);
                acc2.set_type(2);
                acc2.set_status(0);
                acc2.set_balance(all_accountrequests.getlist()[i].getbalance());
                acc2.set_no_users(all_accountrequests.getlist()[i].get_nousers());
                QDateTime exp = QDateTime::currentDateTime();
                acc2.set_sub_date(exp);
                acc2.set_userlist(all_accountrequests.getlist()[i].get_users_ids());
                acc2.setacc_number(acc_n);
 //               acc2.add_transaction(initial_transaction);
                acc2.set_request_flag(0);
                acc2arr.append(acc2);
                new_acc = &acc2arr[acc2arr.size()-1];
            }
            else if(_type==3){
                acc3.set_card(initial_card);
                acc3.set_type(3);
                acc3.set_status(0);
                acc3.set_balance(all_accountrequests.getlist()[i].getbalance());
                acc3.set_no_users(all_accountrequests.getlist()[i].get_nousers());
                QDateTime exp = QDateTime::currentDateTime();
                acc3.set_sub_date(exp);
                acc3.set_userlist(all_accountrequests.getlist()[i].get_users_ids());
                acc3.setacc_number(acc_n);
    //            acc3.add_transaction(initial_transaction);
                acc3.set_request_flag(0);
                acc3arr.append(acc3);
                new_acc = &acc3arr[acc3arr.size()-1];
            }
            else if(_type==4){
                acc4.set_card(initial_card);
                acc4.set_type(4);
                acc4.set_status(0);
                acc4.set_balance(all_accountrequests.getlist()[i].getbalance());
                acc4.set_no_users(all_accountrequests.getlist()[i].get_nousers());
                QDateTime exp = QDateTime::currentDateTime();
                acc4.set_sub_date(exp);
                acc4.set_userlist(all_accountrequests.getlist()[i].get_users_ids());
                acc4.setacc_number(acc_n);
//                acc4.add_transaction(initial_transaction);
                acc4.set_request_flag(0);
                acc4arr.append(acc4);
                new_acc = &acc4arr[acc4arr.size()-1];
            }

            /*

            new_acc->setacc_number(acc_n);
            new_acc->set_type(all_accountrequests.getlist()[i].get_type());
            new_acc->set_userlist(all_accountrequests.getlist()[i].get_users_ids());
            new_acc->set_balance(all_accountrequests.getlist()[i].getbalance());
            new_acc->set_no_users(all_accountrequests.getlist()[i].get_nousers());
            QDateTime exp = QDateTime::currentDateTime();
            new_acc->set_sub_date(exp);
            new_acc->set_status(0);*/
            ///time
            for(int j=0;j<all_accountrequests.getlist()[i].get_users_ids().size();j++)
            {
              int f=all_users.search(all_accountrequests.getlist()[i].get_users_ids()[j]);
              all_users.get_list()[f].add_account(new_acc);

            }
            all_bank_accounts.add_account(new_acc);
            all_accountrequests.remove(all_accountrequests.getlist()[i].get_sender_ncode());


            save();



        }
        ///////////
    }

}

void accept_acc_ui::decline_acc()
{
    QObject* t = QObject::sender();


    for(int i=0;i<all_cardrequests.get_list().size();i++)
    {
        if(t==pbn_decline[i])
        {
            pbn_accept[i]->hide();
            pbn_decline[i]->hide();
            pbn_accept.remove(i);
            pbn_decline.remove(i);
            QMessageBox QMB(this);
            QMB.setText("درخواست حساب رد شد");
            QMB.exec();
            all_accountrequests.remove(all_accountrequests.getlist()[i].get_sender_ncode());
            save();
        }
    }
}


