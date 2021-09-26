#include "del_ui.h"
#include "ui_del_ui.h"
#include "Global_data_variables.h"
#include "QPushButton"
#include<QMessageBox>


Del_ui::Del_ui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Del_ui)
{
    ui->setupUi(this);
    //j=all_users.get_list().size();

    pbn_address.clear();

    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setRowCount(all_users.get_list().size());
    for( int i=0 ; i<all_users.get_list().size();i++)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(all_users.get_list()[i].get_name()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(all_users.get_list()[i].get_username()));
        QPushButton * del= new QPushButton("حذف");
        ui->tableWidget->setCellWidget(i,2,del);
        connect(del,SIGNAL(clicked()),this,SLOT(del_slot()));
        pbn_address.append(del);
        //qDebug()<<pbn_address[i];



    }
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);


    //qDebug()<<i;

    //i++;
//    for(j=0 ; j<all_users.get_list().size();j++)
//    {
//         connect(pbn_address[j],SIGNAL(clicked()),this,SLOT(del_slot()));
//    }




}

Del_ui::~Del_ui()
{
    delete ui;
}

//void Del_ui::slot_i()
//{
//    emit del_signal()
//}

void Del_ui::del_slot()
{
    load();
    //qDebug()<<i;
    QObject* t = QObject::sender();
    qDebug()<<t;

    for(int i=0;i<all_users.get_list().size();i++)
    {
        if(t==pbn_address[i])
        {
            pbn_address[i]->hide();
            QMessageBox QMB(this);
            QMB.setText("با موفقیت حذف شد");
            QMB.exec();
            for(int rmv=0;rmv<all_users.get_list()[i].get_list_of_accounts().size();rmv++)
            {
                qDebug()<<"for rmv";
                if(all_users.get_list()[i].get_list_of_accounts()[rmv]->get_type()==3)
                {
                    for(int j=0;j<all_users.get_list()[i].get_list_of_accounts()[rmv]->get_userslist().size();j++)
                    {
                        if(all_users.get_list()[i].get_national_code()==all_users.get_list()[i].get_list_of_accounts()[rmv]->get_userslist()[j])
                        {
                            all_users.get_list()[i].get_list_of_accounts()[rmv]->get_userslist().removeAt(j);
                        }
                    }
                    if(all_users.get_list()[i].get_list_of_accounts()[rmv]->get_userslist().size()==1)
                    {
                       all_users.get_list()[i].get_list_of_accounts()[rmv]->set_type(2);
                    }

                    if(all_users.get_list()[i].get_list_of_accounts()[rmv]->get_userslist().size()<1)
                    {
                        all_bank_accounts.remove(all_users.get_list()[i].get_list_of_accounts()[rmv]->getacc_num());
                    }

                }
                else{
                    all_bank_accounts.remove(all_users.get_list()[i].get_list_of_accounts()[rmv]->getacc_num());

                }
            }
            qDebug()<<"bad for";
            pbn_address.remove(i);
            all_users.remove(all_users.get_list()[i].get_username());

            //qDebug()<<pbn_address.size();

            save();
        }
//        qDebug()<<"newad";
//        qDebug()<<pbn_address[i];
    }
   // qDebug()<<all_users.get_list().size();


    //all_users.remove(all_users.get_list()[i].get_username());
    //qDebug()<<all_users.get_list()[i].get_username();

}
