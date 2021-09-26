#include "dialog_add_account.h"
#include "ui_dialog_add_account.h"
#include<QMessageBox>
#include "Global_data_variables.h"
Dialog_add_account::Dialog_add_account(QList<QString>* al,int* listok2,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_add_account)
{
    ql=new QList<QString>;
    _listok=new int;
    _listok=listok2;
    ql=al;
    ui->setupUi(this);
}

Dialog_add_account::~Dialog_add_account()
{
    delete ui;
}

void Dialog_add_account::on_pushButton_clicked()
{
    if(ui->lineEdit->text()==nullptr){
        QMessageBox::information(this, tr("اخطار"),tr("لطفا فیلد را پر کنید "));
        return;
    }
    int k;
    k=0;
    int s=all_users.get_list().size();
    for(int i=0;i<s;i++){
        if(all_users.get_list()[i].get_name()==ui->lineEdit->text())
        {
        k=1;
        break;
        }
    }
    if(k==1){
    (*ql).push_back (all_users.get_list()[(all_users.search_byname( ui->lineEdit->text()))].get_national_code());
    QMessageBox::information(this, tr("اطلاعیه"),tr("کاربر اضافه شد "));
    *_listok =1;
    }
    else{
        QMessageBox::information(this, tr("اخطار"),tr("کاربر ورودی در لیست کاربرها وجود ندارد "));
    }

}

void Dialog_add_account::on_pushButton_2_clicked()
{
    close();
}

void Dialog_add_account::on_pushButton_3_clicked()
{
    *_listok = 0;
    close();
}
