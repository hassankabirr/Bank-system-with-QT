#include "card_req_ui.h"
#include "ui_card_req_ui.h"
#include <QVector>
#include "Global_data_variables.h"
#include <QMessageBox>

card_req_ui::card_req_ui(QWidget *parent) :
    QDialog(parent),
     ui(new Ui::card_req_ui)

{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(4);
    QStringList header;
    header<<"account_num"<<"user/users"<<"accept "<<"decline";
    ui->tableWidget->setHorizontalHeaderLabels(header);

    QList<Card_request> card_req_list;
    QList<User> all_user_list;
    card_req_list=all_cardrequests.get_list();
    all_user_list=all_users.get_list();
    ui->tableWidget->setRowCount(card_req_list.size());



  //  qDebug()<<admin_accept_acc;

    for(int i=0;i<card_req_list.size();i++)
    {

        QString find_txt="";
        for (int k=0 ; k<all_user_list.size();k++){

         for(int j=0; j<all_user_list[k].get_list_of_accounts().size();j++)
         {
             if (card_req_list[i].get_acc_num()==all_user_list[k].get_list_of_accounts()[j]->getacc_num())
             {


                     find_txt=find_txt+all_user_list[k].get_name()+ " & ";


                break;
            }
        }

         ui->tableWidget->setItem(i,0,new QTableWidgetItem(card_req_list[i].get_acc_num()));

         ui->tableWidget->setItem(i,1,new QTableWidgetItem(find_txt));

       }



        yes=new QPushButton("قبول");
        no=new QPushButton("رد");
        ui->tableWidget->setCellWidget(i,2,yes);
        ui->tableWidget->setCellWidget(i,3,no);
        pbn_accept.append(yes);
        pbn_decline.append(no);
        connect(yes,SIGNAL(clicked()),this, SLOT(accept_card()));
        connect(no,SIGNAL(clicked()),this, SLOT(decline_card()));

    }
    ui->tableWidget->resizeColumnToContents(1);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);


}

card_req_ui::~card_req_ui()
{
    delete ui;
}

void card_req_ui::accept_card()
{
    srand(time(NULL));
            QString cvv="";
            QString card_n="";
            for(int i=0;i<8;i++){
               int random=rand()%10;
               card_n+=QString::number(random);
            }
            for(int i=0;i<4;i++){
                int random = rand()%10;
                cvv+=QString::number(random);
            }


            QObject* t = QObject::sender();


            for(int i=0;i<all_cardrequests.get_list().size();i++)
            {
                if(t==pbn_accept[i])
                {
                    pbn_accept[i]->hide();
                    pbn_decline[i]->hide();
                    pbn_accept.remove(i);
                    pbn_decline.remove(i);
                    QMessageBox QMB(this);
                    QMB.setText("درخواست کارت پذیرفته شد");
                    QMB.exec();
                    int j= all_bank_accounts.search(all_cardrequests.get_list()[i].get_acc_num());
                    all_bank_accounts.getlist()[j]->get_card().set_status(0);
                    all_bank_accounts.getlist()[j]->get_card().set_acc_num(all_cardrequests.get_list()[i].get_acc_num());
                    all_bank_accounts.getlist()[j]->get_card().set_cvvt(cvv);
                    QDate exp = QDate::currentDate().addYears(1);
                    all_bank_accounts.getlist()[j]->get_card().set_expiration(exp);
                    all_bank_accounts.getlist()[j]->get_card().set_cardnum(card_n);

                    all_cardrequests.remove(all_cardrequests.get_list()[i].get_acc_num());
                    save();
                }
            }

           //all_cardrequests.get_list()[i]. //.
//            get_card().set_acc_num(all_bank_accounts.getlist()[activeaccount]->getacc_num());
//            get_card().set_cvvt(cvv);
//            get_card().set_cardnum(card_n);
            //            get_card().set_expiration(exp);
}

void card_req_ui::decline_card()
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
            QMB.setText("درخواست کارت رد شد");
            QMB.exec();
            all_cardrequests.remove(all_cardrequests.get_list()[i].get_acc_num());
            save();


        }
        ///////////
    }
}
