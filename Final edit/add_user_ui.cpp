#include "add_user_ui.h"
#include "ui_add_user_ui.h"
#include "Global_data_variables.h"
#include "user.h"
#include<QMessageBox>


add_user_ui::add_user_ui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_user_ui)
{
    ui->setupUi(this);
    ui->lineEdit_6->setEchoMode(QLineEdit::Password);

}

add_user_ui::~add_user_ui()
{
    delete ui;
}

void add_user_ui::on_pushButton_clicked()
{
    if(ui->lineEdit->text()==""||ui->lineEdit_2->text()==""||ui->lineEdit_3->text()==""||ui->lineEdit_5->text()==""||ui->lineEdit_6->text()=="" )
    {
        QMessageBox mb;
        mb.setText("لطفا تمام فیلد ها را پر کنید");
        mb.exec();
    }
    else{

    if(all_users.search(ui->lineEdit_3->text())>-1)
    {
        QMessageBox mb;
        mb.setText("این کد ملی قبلا ثبت شده است");
        mb.exec();

    }
    else {
        if(all_users.search_byusername(ui->lineEdit_2->text())>-1)
        {
            QMessageBox mb;
            mb.setText("این نام کاربری قبلا ثبت شده است");
            mb.exec();
        }
        else{
            QDate Date = QDate::fromString(ui->lineEdit_4->text(),"yyyy/MM/dd");
            if(!Date.isNull()){
            User new_user;
            new_user.set_name(ui->lineEdit->text());
            new_user.set_username(ui->lineEdit_2->text());
            new_user.set_password(ui->lineEdit_6->text());
            new_user.set_national_code(ui->lineEdit_3->text());

            new_user.set_birthdate(Date);
            new_user.set_email(ui->lineEdit_5->text());
            all_users.add_user(new_user);
            save();
            this->close();
            }
            else{
                QMessageBox mb;

                mb.setText("تاریخ تولد را به صورت صحیح وارد کنید");
                mb.exec();
            }
        }
    }
    }

}
