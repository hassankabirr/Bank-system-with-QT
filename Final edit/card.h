#ifndef CARD_H
#define CARD_H
#include <QString>
#include<QDateTime>
#include<QDate>
#include<QJsonObject>
#include<QJsonArray>
#include<QJsonDocument>
#include<QJsonValue>
class Card
{
private:
    QString card_num;
    QString account_num;
    QString dynamic_pin;//taghir be qstring
    QTime pin_time;
    QDate expiration_date;
    QString cvvt;
    int status;//0:open  1:blocked


public:
    Card();
    QString get_cardnum(){return card_num;}
    void set_cardnum(QString _cardnum){card_num=_cardnum;}
    QString get_cvvt(){return cvvt;}
    void set_cvvt(QString _cvvt){cvvt=_cvvt;}
    QDate get_expiration(){return expiration_date;}
    void set_expiration(QDate _expiration_date){expiration_date=_expiration_date;}
    void read(const QJsonObject &json);//ezafe kardam
    void write(QJsonObject &json);//ezafe kardam
    QString& get_acc_num(){return account_num;}// ezafe kardam
    void set_acc_num(QString _num){account_num = _num;}//ezafe kardam
    int get_status(){return status;}
    void set_status(int _status){status = _status;}
    void set_dynamic_pin(QString _pin){dynamic_pin = _pin;}
    QString get_pin(){return dynamic_pin;}
    void set_pin_time(QTime _time){pin_time=_time;}
    QTime get_pin_time(){return pin_time;}
};

#endif // CARD_H
