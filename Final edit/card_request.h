#ifndef CARD_REQUEST_H
#define CARD_REQUEST_H

#include <QDateTime>
#include <QJsonArray>
#include<QJsonObject>
class Card_request
{
private:
   QString sender_acc_num ;// be qstring taghiir dadam
   QDateTime time_of_request;
   int status;//1:accepted 2:rejected 0:not processed
public:
    Card_request();
    QString get_acc_num(){return sender_acc_num;}
    void set_acc_num(QString _acc_num){sender_acc_num=_acc_num;}
    QDateTime get_time_of_request(){return time_of_request;}
    void set_time_of_request(QDateTime _time_of_request){time_of_request=_time_of_request;}
    void read(const QJsonObject &json);//ezafe kardam
    void write(QJsonObject &json);//ezafe kardam

};

#endif // CARD_REQUEST_H
