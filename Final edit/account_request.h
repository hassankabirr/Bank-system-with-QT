#ifndef ACCOUNT_REQUEST_H
#define ACCOUNT_REQUEST_H
#include<QString>
#include<QDateTime>
#include<QList>
#include<QJsonObject>
#include<QJsonArray>
#include<QJsonObject>
#include<QJsonValue>
class account_request
{
    QString sender_national_code;
    QDateTime time_of_request;
    double starting_balance;
    int type;
    QList<QString> users_ids;
    int no_users;
    int status;//1:accepted 2:rejected 0:not processed
public:
    account_request();
    QString& get_sender_ncode(){return sender_national_code;}
    void set_sender_ncode(QString _nc){sender_national_code = _nc;}
    QDateTime& getTOrequest(){return  time_of_request;}
    void setTOrequest(QDateTime _date){time_of_request = _date;}
    double getbalance(){return starting_balance;}
    void setbalance(double _balance){starting_balance = _balance;}
    int get_type(){return type;}
    void set_type(int _type){type = _type;}
    QList<QString>& get_users_ids(){return users_ids;}
    void add_user(QString& _id){users_ids.append(_id);}
    void set_users(QList<QString>& _list){users_ids = _list;}
    int get_nousers(){return no_users;}
    void set_nousers(int _n){no_users = _n;}
    void read(const QJsonObject &json);
    void write(QJsonObject &json);
    int get_status(){return status;}
    void set_status(int _status){status = _status;}
};

#endif // ACCOUNT_REQUEST_H
