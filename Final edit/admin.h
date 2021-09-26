#ifndef ADMIN_H
#define ADMIN_H
#include <string>
#include <QString>
#include <iostream>
#include <card_request.h>
using namespace std;
#include "user.h"
#include "account_request.h"
#include "Global_data_variables.h"


class admin
{
private:
    QString Name;
    QString national_code;
    QString username;
    QString password;

public:
    admin();
    QString get_name(){return Name;}
    void set_name(QString _Name){Name=_Name;}
    QString get_nationalcode(){return national_code;}
    void set_nationalcode(QString _national_code){national_code=_national_code;}
    QString get_username(){return username; }
    void set_username(QString _username){username=_username;}
    QString get_pass(){return password;}
    void set_pass(QString _password){password=_password;}
    void add_user(User);
    void delete_user(User&);
    void get_user_info();   // khoroji ro motmaen nistam
    void accept_acc(account_request);
    void decline_acc(account_request);
    void get_transactions(); // khoroji ro motmaen nistam
    void get_card_requests(); // khoroji ro motmaen nistam
    void get_acc_requests(); // khoroji ro motmaen nistam
    void accept_card(Card_request);
    void decline_card(Card_request);
    void get_user(int);


};

#endif // ADMIN_H
