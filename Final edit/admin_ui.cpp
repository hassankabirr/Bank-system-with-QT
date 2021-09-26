#include "admin_ui.h"
#include "ui_admin_ui.h"
#include "del_ui.h"
#include "transaction_ui.h"
#include "dialog.h"
#include "accept_acc_ui.h"
#include "card_req_ui.h"
#include "login_logout_ui.h"
#include "mainwindow.h"



admin_ui::admin_ui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::admin_ui)
{
    ui->setupUi(this);
    load();

    this->setFixedSize(684,256);

}

admin_ui::~admin_ui()
{
    delete ui;
    save();
}

void admin_ui::on_pushButton_3_clicked()
{
    Users_info_ui * uiu =new Users_info_ui(this);
    uiu->show();
}

void admin_ui::on_pushButton_2_clicked()
{
    add_user_ui * aui= new add_user_ui(this);
    aui->show();
}

void admin_ui::on_pushButton_clicked()
{
    Del_ui * d = new Del_ui(this);
    d->show();


}

void admin_ui::on_pushButton_4_clicked()
{
    transaction_ui * t= new transaction_ui(this);
    t->show();

}

void admin_ui::on_pushButton_7_clicked()
{
    Dialog * d = new Dialog(this);
    d->show();

}

void admin_ui::on_pushButton_5_clicked()
{
    accept_acc_ui * aa = new accept_acc_ui(this);
    aa->show();


}

void admin_ui::on_pushButton_6_clicked()
{
    card_req_ui * cr = new card_req_ui(this);
    cr->show();

}

void admin_ui::on_pushButton_8_clicked()
{
    login_logout_ui * llu=new login_logout_ui(this);
    llu->show();
}

void admin_ui::on_actionlogout_triggered()
{
    save();
    this->close();
    MainWindow *mw=new MainWindow();
    mw->show();


}

void admin_ui::on_pushButton_9_clicked()
{
    save();
    this->close();
    MainWindow *mw=new MainWindow();
    mw->show();
}
