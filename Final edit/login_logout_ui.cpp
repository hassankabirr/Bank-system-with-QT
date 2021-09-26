#include "login_logout_ui.h"
#include "ui_login_logout_ui.h"
#include "Global_data_variables.h"
#include<QPushButton>
#include "login_logout2_ui.h"
login_logout_ui::login_logout_ui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login_logout_ui)
{
    ui->setupUi(this);

//    QPushButton* t= new QPushButton();
    for(int i=0 ; i<all_users.get_list().size();i++)
    ui->listWidget->addItem(new QListWidgetItem(all_users.get_list()[i].get_username()));
    connect(ui->listWidget,SIGNAL(itemClicked(QListWidgetItem *)),this,SLOT(loged(QListWidgetItem *)));
}

login_logout_ui::~login_logout_ui()
{
    delete ui;
}

void login_logout_ui::loged(QListWidgetItem *item)
{
    int i=all_users.search_byusername(item->text());
    login_logout2_ui *ll2=new login_logout2_ui(this,i);
//    ll2->setkey(i);
    ll2->show();


}

