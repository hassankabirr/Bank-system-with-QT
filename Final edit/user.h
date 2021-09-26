#ifndef USER_H
#define USER_H
#include"bank_account.h"
#include <QDateTime>
#include<QList>


class User
{
    QString Name;
    QDate birthdate;
    QString national_code;
    QString username;
    QString password;
    QList<Bank_account*> bank_accounts;
    QString email;
    QList< QDateTime> logintime;
    QList< QDateTime> logouttime;
    public:
    User();
    QString get_name();
    QDate get_birthdate();
    QString get_username();
    QString get_password();
    QString get_national_code();
    QList<Bank_account*> get_list_of_accounts();
    QString get_email();
    QList<QDateTime>& get_login_time();
    QList<QDateTime>& get_logout_time();
    void set_name(QString);
    void set_birthdate(QDate);
    void set_national_code(QString);
    void set_username(QString);
    void set_password(QString);
    void add_account(Bank_account*);
    void request_new_account();
    void set_logintime(QList<QDateTime>&);
    void set_logouttime(QList<QDateTime>&);
    void add_login(QDateTime);
    void add_logout(QDateTime);
    void set_email(QString);
    void read(const QJsonObject& json);
    void write(QJsonObject &json);

};

#endif // USER_H
