#include "login_logout2_ui.h"
#include "ui_login_logout2_ui.h"
#include "Global_data_variables.h"

login_logout2_ui::login_logout2_ui(QWidget *parent,int _key) :
    QDialog(parent),
    ui(new Ui::login_logout2_ui)
{
    key=_key;
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(2);
    QStringList header;
    header<<"Login"<<"logout";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    int rowmax=max(all_users.get_list()[key].get_login_time().size(),all_users.get_list()[key].get_logout_time().size());
    ui->tableWidget->setRowCount(rowmax);

    for(int i=0;i<all_users.get_list()[key].get_login_time().size();i++)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(all_users.get_list()[key].get_login_time()[i].toString("yy/M/d h:m:s")));

    }
    for(int i=0;i<all_users.get_list()[key].get_logout_time().size();i++)
    {
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(all_users.get_list()[key].get_logout_time()[i].toString("yy/M/d h:m:s")));

    }
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);



}

login_logout2_ui::~login_logout2_ui()
{
    delete ui;
}
