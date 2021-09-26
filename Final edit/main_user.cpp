#include "main_user.h"
#include "ui_main_user.h"
#include "edit_profile_dialog.h"
#include "Global_data_variables.h"
#include"dialog_add_account.h"
#include<QDateTime>
#include"mainwindow.h"
main_User::main_User(int _index,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::main_User)
{
    setWindowFlags(Qt::Window
        | Qt::WindowMinimizeButtonHint
        | Qt::WindowMaximizeButtonHint);
    acc_window = new accountwindow;
        listok=new int;
        *listok=0;
        index=_index;
        tmp_a_l = new QList<QString>;
        ui->setupUi(this);

        ui->name_lbl->setText("نام : " + all_users.get_list()[_index].get_name());
        ui->birthdate_lbl->setText("تاریخ تولد : " + all_users.get_list()[_index].get_birthdate().toString(Qt::TextDate));
        ui->email_lbl->setText(all_users.get_list()[_index].get_email());
        ui->nc_lbl->setText(all_users.get_list()[_index].get_national_code());
        int size=all_users.get_list()[_index].get_list_of_accounts().size();
        for(int i=0;i<size;i++){
            ui->accounts_number_List->addItem(all_users.get_list()[_index].get_list_of_accounts()[i]->getacc_num());
        }


        int i1=all_users.get_list()[_index].get_login_time().size();
       for(int i=0;i<i1;i++){
        ui->log_listWidget->addItem("Login time : " + all_users.get_list()[_index].get_login_time()[i].toString("dd.MM.yyyy") + "  " + all_users.get_list()[_index].get_login_time()[i].toString("h:m:s ap"));
        if(i!=i1-1&&i1!=1)
        ui->log_listWidget->addItem("Logout time : " + all_users.get_list()[_index].get_logout_time()[i].toString("dd.MM.yyyy") + "  " + all_users.get_list()[_index].get_logout_time()[i].toString("h:m:s ap"));

        }
        connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(account_type_changed(int)));




}

main_User::~main_User()
{
    delete ui;
}


void main_User::on_edit_prof_button_clicked()
{
Edit_Profile_Dialog* d=new Edit_Profile_Dialog (index,this);
(*d).show();
connect(d,SIGNAL(update_profedit()),this,SLOT(update_prof()));

}

void main_User::on_accounts_number_List_itemDoubleClicked(QListWidgetItem *item)
{
   // item->text();
     int acc_index=all_bank_accounts.search(item->text());
     activeaccount = acc_index;
    accountwindow* acc_w =  new accountwindow;
            acc_w->show();
}
void main_User::account_type_changed(int i){
    if(i==2){
        *listok=0;
        delete tmp_a_l;
        tmp_a_l=new QList<QString>;
        Dialog_add_account *w=new Dialog_add_account(tmp_a_l,listok);
        w->show();
    }
}
void main_User::update_prof(){
    ui->name_lbl->setText("نام : " + all_users.get_list()[index].get_name());
    ui->birthdate_lbl->setText("تاریخ تولد : " + all_users.get_list()[index].get_birthdate().toString(Qt::TextDate));
    ui->email_lbl->setText(all_users.get_list()[index].get_email());
    ui->nc_lbl->setText(all_users.get_list()[index].get_national_code());
    repaint();
}

void main_User::on_pushButton_clicked()
{
    if(ui->ad_lineEdit->text() ==nullptr){
        QMessageBox::information(this, tr("اخطار"),tr("لطفا فیلد موجودی اولیه را پر کنید "));
        return;
    }
    if(ui->comboBox->currentIndex()==2){
        if(*listok==0){
            QMessageBox::information(this, tr("اخطار"),tr("لطفا حداقل یک کاربر برای حساب حقوقی خود وارد کنید "));
        account_type_changed(2);
        return;
        }
    }
    account_request ac;
    ac.set_type(ui->comboBox->currentIndex()+1);
    ac.setbalance(ui->ad_lineEdit->text().toDouble());
    (*tmp_a_l).append(all_users.get_list()[activeuser].get_national_code());
    ac.set_users(*tmp_a_l);
    ac.set_nousers((*tmp_a_l).size());
    QDateTime qdt;
    ac.setTOrequest(qdt.currentDateTime());
    ac.set_sender_ncode(all_users.get_list()[index].get_national_code());
    all_accountrequests.add_account(ac);
    save();
    QMessageBox::information(this, tr("اطلاعیه"),tr("درخواست ثبت شد "));
}

void main_User::on_pushButton_2_clicked()
{
    all_users.get_list()[activeuser].add_logout(QDateTime::currentDateTime());
    this->close();
    save();

    MainWindow *w = new MainWindow();
    w->show();

}
