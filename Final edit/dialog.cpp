#include "dialog.h"
#include "Global_data_variables.h"
#include "ui_dialog.h"
#include<QPushButton>

#include <QComboBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
     QList<User> all_user_list=all_users.get_list();
    ui->setupUi(this);
    QStringList header;
    header<<"####"<<"user/users "<<"card"<<"Balance"<<"acount type"<<"card status"<<"acc status";
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setRowCount(all_bank_accounts.getlist().size());
    QString txt="";
    for(int i=0 ; i<all_bank_accounts.getlist().size();i++)
    {
         ui->tableWidget->setItem(i, 0, new QTableWidgetItem(all_bank_accounts.getlist()[i]->getacc_num()));
         if(all_bank_accounts.getlist()[i]->get_card().get_cardnum()=="0")
         {
             ui->tableWidget->setItem(i, 2, new QTableWidgetItem("ندارد"));
         }
         else{
             ui->tableWidget->setItem(i, 2, new QTableWidgetItem(all_bank_accounts.getlist()[i]->get_card().get_cardnum()));
         }
         txt="";
         for(int j=0; j < all_bank_accounts.getlist()[i]->get_userslist().size();j++)
         {
             int finder=all_users.search(all_bank_accounts.getlist()[i]->get_userslist()[j]);
             if(finder==-1)
                 continue;
              if(j == all_bank_accounts.getlist()[i]->get_userslist().size()-1)
                  txt=txt + all_users.get_list()[finder].get_username();
              else
                  txt=txt + all_users.get_list()[finder].get_username()+" & ";

         }
          ui->tableWidget->setItem(i,1, new QTableWidgetItem(txt));
          ui->tableWidget->setItem(i,3, new QTableWidgetItem(QString::number(all_bank_accounts.getlist()[i]->get_balance(),'f')));
          ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
          switch (all_bank_accounts.getlist()[i]->get_type()) {
          case 1:
               ui->tableWidget->setItem(i,4, new QTableWidgetItem("س.قرض الحسنه"));
              break;



          case 2:
              ui->tableWidget->setItem(i,4, new QTableWidgetItem("س.س.كوتاه مدت"));
              break;
          case 3:

              ui->tableWidget->setItem(i,4, new QTableWidgetItem("س.س.كوتاه مدت حقوقی"));
              break;
           case 4:
              ui->tableWidget->setItem(i,4, new QTableWidgetItem("س.س.بلند مدت"));
              break;


          }
          ui->tableWidget->resizeColumnToContents(4);
          ui->tableWidget->resizeColumnToContents(1);
//          cb=new QComboBox();
//          cb->addItem("");
//          cb->addItem("block card");
//          cb->addItem("block acc");
          QPushButton * b_acc;
          QPushButton * b_card;
          if(all_bank_accounts.getlist()[i]->get_status()==0)
          {
              b_acc=new QPushButton("مسدود کردن حساب");
          }
          else if (all_bank_accounts.getlist()[i]->get_status()==1)
          {
              b_acc=new QPushButton("خروج از مسدودی");
          }
          if(all_bank_accounts.getlist()[i]->get_card().get_status()==0)
          {
              b_card=new QPushButton("مسدود کردن کارت");
          }
          else if (all_bank_accounts.getlist()[i]->get_card().get_status()==1)
          {
              b_card=new QPushButton("خروج از مسدودی");
          }



          ui->tableWidget->resizeColumnToContents(6);
          ui->tableWidget->resizeColumnToContents(5);
          card_block.append(b_card);
          acc_block.append(b_acc);

          ui->tableWidget->setCellWidget(i,5,b_card);
          ui->tableWidget->setCellWidget(i,6,b_acc);



          connect(b_card,SIGNAL(clicked()),this,SLOT(card_situation()));
         connect(b_acc, SIGNAL(clicked()), this, SLOT(acc_situation()));



    }
    connect(ui->tableWidget,SIGNAL(cellClicked(int, int )),this,SLOT(card_slot(int,int)));


}
Dialog::~Dialog()
{
    delete ui;
}

void Dialog::card_situation()
{
    QObject* t = QObject::sender();


    for(int i=0;i<all_bank_accounts.getlist().size();i++)
    {
        if(t==card_block[i])
        {
            if(card_block[i]->text()=="مسدود کردن کارت")
            {
                all_bank_accounts.getlist()[i]->get_card().set_status(1);
                card_block[i]->setText("خروج از مسدودی");

            }
            else if(card_block[i]->text()=="خروج از مسدودی")
            {
                all_bank_accounts.getlist()[i]->get_card().set_status(0);
                card_block[i]->setText("مسدود کردن کارت");
            }


            }

            save();


        }

}

void Dialog::acc_situation()
{
    QObject* t = QObject::sender();


    for(int i=0;i<all_bank_accounts.getlist().size();i++)
    {
        if(t==acc_block[i])
        {
            if(acc_block[i]->text()=="مسدود کردن حساب")
            {
//                qDebug()<<"h1";
                all_bank_accounts.getlist()[i]->set_status(1);
                acc_block[i]->setText("خروج از مسدودی");

            }
            else if(acc_block[i]->text()=="خروج از مسدودی")
            {
//                qDebug()<<"h0";
                all_bank_accounts.getlist()[i]->set_status(0);
                acc_block[i]->setText("مسدود کردن حساب");
            }


            }

            save();


        }

}
void Dialog::card_slot(int row, int column)
{
    if(column==2)
    {

        QMessageBox mb;
        if(all_bank_accounts.getlist()[row]->get_card().get_cardnum()=="0")
            mb.setText("فاقد کارت");

            else {
            mb.setText(all_bank_accounts.getlist()[row]->get_card().get_cvvt()+" :CVV2"+"\n"+all_bank_accounts.getlist()[row]->get_card().get_expiration().toString("yyyy/MM/dd")+" : تاریخ انقضا");

        }
        double asdf=0;
        qDebug()<<QString::number(asdf,'f');

        mb.exec();
    }
}




