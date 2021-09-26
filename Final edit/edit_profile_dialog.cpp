#include "edit_profile_dialog.h"
#include "ui_edit_profile_dialog.h"
#include "Global_data_variables.h"
Edit_Profile_Dialog::Edit_Profile_Dialog(int _current_user_index,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit_Profile_Dialog)
{
    id=_current_user_index;
    ui->setupUi(this);
    ui->Name_EditProf_lineEdit->setText(all_users.get_list()[id].get_name());
    ui->nc_EditProf_lineEdit->setText(all_users.get_list()[id].get_national_code());
    ui->Day_spinBox->setValue(all_users.get_list()[id].get_birthdate().day());
    ui->Month_spinBox->setValue(all_users.get_list()[id].get_birthdate().month());
    ui->Year_spinBox->setValue(all_users.get_list()[id].get_birthdate().year());
    ui->email_EditProf_lineEdit->setText(all_users.get_list()[id].get_email());

}
Edit_Profile_Dialog::~Edit_Profile_Dialog()
{
    delete ui;
}

void Edit_Profile_Dialog::on_buttonBox_accepted()
{
    if(ui->Name_EditProf_lineEdit->text()==nullptr ||ui->nc_EditProf_lineEdit->text()==nullptr ||ui->email_EditProf_lineEdit->text()==nullptr){
        QMessageBox::information(this, tr("اخطار"),tr(" ویرایش ناموفق \n فیلدی را خالی نگذارید"));
        return;
    }
    all_users.get_list()[id].set_name(ui->Name_EditProf_lineEdit->text());
    all_users.get_list()[id].set_national_code( ui->nc_EditProf_lineEdit->text());
    all_users.get_list()[id].set_email(ui->email_EditProf_lineEdit->text());
    QDate bdate(ui->Year_spinBox->value(),ui->Month_spinBox->value(),ui->Day_spinBox->value());
    all_users.get_list()[id].set_birthdate(bdate);
    QMessageBox::information(this, tr("اطلاعیه"),tr("پروفایل با موفقیت ویرایش شد "));
   // qDebug()<<all_users.get_list()[id].get_name();
    emit update_profedit();
    save();
    close();
}
