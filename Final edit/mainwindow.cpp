#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "Global_data_variables.h"
#include<QMessageBox>
#include "admin_ui.h"
 list_of_bankaccounts all_bank_accounts;
 list_of_users all_users;
 list_of_transactions all_transactions;
 list_of_card_requests all_cardrequests;
 list_of_account_requests all_accountrequests;
 admin manager;
 int activeuser=0;
 int activeaccount=0;

 QFile file;
  void load(){
     file.setFileName("C:/Users/saman/Desktop/project_data2.json");
     file.open(QIODevice::ReadOnly|QIODevice::Text);
     QJsonParseError JsonParseError;
     QJsonDocument JsonDocument = QJsonDocument::fromJson(file.readAll(), &JsonParseError);
     file.close();
     QJsonObject obj = JsonDocument.object();
     all_bank_accounts.read(obj);



     file.setFileName("C:/Users/saman/Desktop/usersdata.json");
     file.open(QIODevice::ReadOnly|QIODevice::Text);
     //QJsonParseError JsonParseError;
      JsonDocument = QJsonDocument::fromJson(file.readAll(), &JsonParseError);
     file.close();
      obj = JsonDocument.object();
      all_users.read(obj);





      file.setFileName("C:/Users/saman/Desktop/transactions.json");
      file.open(QIODevice::ReadOnly|QIODevice::Text);
      //QJsonParseError JsonParseError;
       JsonDocument = QJsonDocument::fromJson(file.readAll(), &JsonParseError);
      file.close();
       obj = JsonDocument.object();
       all_transactions.read(obj);


       file.setFileName("C:/Users/saman/Desktop/accountrequests.json");
       file.open(QIODevice::ReadOnly|QIODevice::Text);
       //QJsonParseError JsonParseError;
        JsonDocument = QJsonDocument::fromJson(file.readAll(), &JsonParseError);
       file.close();
        obj = JsonDocument.object();
        all_accountrequests.read(obj);



        file.setFileName("C:/Users/saman/Desktop/cardrequests.json");
        file.open(QIODevice::ReadOnly|QIODevice::Text);
        //QJsonParseError JsonParseError;
         JsonDocument = QJsonDocument::fromJson(file.readAll(), &JsonParseError);
        file.close();
         obj = JsonDocument.object();
         all_cardrequests.read(obj);


 }
  void save(){
      file.setFileName("C:/Users/saman/Desktop/project_data2.json");
      file.open(QIODevice::WriteOnly);
      QJsonDocument jsondoc;
      QJsonObject obj;
      all_bank_accounts.write(obj);
      jsondoc.setObject(obj);
      file.write(jsondoc.toJson());
      file.close();


      file.setFileName("C:/Users/saman/Desktop/usersdata.json");
      file.open(QIODevice::WriteOnly);
     obj= QJsonObject();
     jsondoc = QJsonDocument();
      all_users.write(obj);
      jsondoc.setObject(obj);
      file.write(jsondoc.toJson());
      file.close();


      file.setFileName("C:/Users/saman/Desktop/transactions.json");
      file.open(QIODevice::WriteOnly);
      obj= QJsonObject();
      jsondoc = QJsonDocument();
      all_transactions.write(obj);
      jsondoc.setObject(obj);
      file.write(jsondoc.toJson());
      file.close();


      file.setFileName("C:/Users/saman/Desktop/accountrequests.json");
      file.open(QIODevice::WriteOnly);
      obj= QJsonObject();
      jsondoc = QJsonDocument();
      all_accountrequests.write(obj);
      jsondoc.setObject(obj);
      file.write(jsondoc.toJson());
      file.close();



      file.setFileName("C:/Users/saman/Desktop/cardrequests.json");
      file.open(QIODevice::WriteOnly);
      obj= QJsonObject();
      jsondoc = QJsonDocument();
      all_cardrequests.write(obj);
      jsondoc.setObject(obj);
      file.write(jsondoc.toJson());
      file.close();



  }
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    load();
    ui->setupUi(this);
    ui->lineEditpass->setEchoMode(QLineEdit::Password);

    this->setFixedSize(263,320);
   // qDebug()<<all_bank_accounts.getlist()[0]->get_request_flag();




}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_clicked()
{
    QString user = ui->lineEdituser->text();
    QString pass = ui->lineEditpass->text();
    int _index = all_users.search_byusername(user);
    QMessageBox msg;
    msg.setText("!نام کاربری یا رمز عبور اشتباه است");
    if(_index==-1){

        msg.exec();
    }
    else{
        if(all_users.get_list()[_index].get_password()!=pass)msg.exec();
        else {
            activeuser = _index;
            all_users.get_list()[_index].add_login(QDateTime::currentDateTime());
           // qDebug()<<activeuser;
            userwindow = new main_User(activeuser);
//            acc_window = new accountwindow;
//            acc_window->show();
            userwindow->show();
            this->close();
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QString user = ui->lineEdituser->text();
    QString pass = ui->lineEditpass->text();
    QMessageBox msg;
    msg.setText("!نام کاربری یا رمز عبور اشتباه است");
    if(user=="hsn"){
        if(pass=="123456789"){
            admin_ui *au= new admin_ui();

            this->close();
            au ->show();
        }
        else msg.exec();
    }
    else msg.exec();





}
