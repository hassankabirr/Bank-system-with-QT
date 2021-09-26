#include "users_info_ui.h"
#include "ui_users_info_ui.h"
#include <Global_data_variables.h>
#include <QStringList>
#include <iostream>
#include <QTableView>

using namespace std;
#include <stdio.h>
#include <stdlib.h>
Users_info_ui::Users_info_ui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Users_info_ui)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(6);
    QStringList header;
    header<<"Name"<<"Userame"<<"Password"<<"National Cod"<<"Birthdate"<<"E-Mail";
    ui->tableWidget->setHorizontalHeaderLabels(header);
     QList<User> users_=all_users.get_list();
     ui->tableWidget->setRowCount(users_.size());


//    std::string title;
//    sprintf(title,"%d",use)
//    ui->label->setNum(users_.size());
    for(int i=0;i<users_.size();i++)
    {



        ui->tableWidget->setItem(i,0,new QTableWidgetItem(users_[i].get_name()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(users_[i].get_username()));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(users_[i].get_password()));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(users_[i].get_national_code()));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(users_[i].get_birthdate().toString("yyyy/MM/dd")));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(users_[i].get_email()));
        ui->tableWidget->resizeColumnToContents(5);
        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);




//        add = "E-Mail : "+users_[i].get_email();
//        ui->listWidget->addItem(add);
//        add = "National Code : "+users_[i].get_national_code();
//        ui->listWidget->addItem(add);
//        add = "Birthdate : "+users_[i].get_birthdate().toString("yyyy/MM/dd");
//        ui->listWidget->addItem(add);

//        add="- - - - - - - - - - - - - - - - - - - - - - - -";
//         ui->listWidget->addItem(add);

    }

}

Users_info_ui::~Users_info_ui()
{
    delete ui;
}
