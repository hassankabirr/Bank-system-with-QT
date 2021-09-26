#include "card_request.h"

Card_request::Card_request()
{
status = 0;
}

void Card_request::read(const QJsonObject &json)
{
    sender_acc_num = json["sender"].toString();
    QDate d(json["request_year"].toInt(),json["request_month"].toInt(),json["request_day"].toInt());
    QTime t(json["request_hour"].toInt(),json["request_min"].toInt(),json["request_sec"].toInt());
    QDateTime date(d,t);
    time_of_request = date;
    status = json["status"].toInt();

}

void Card_request::write(QJsonObject &json)
{
    json["sender"] = sender_acc_num;
    QDate d = time_of_request.date();
    QTime t = time_of_request.time();
    json["request_year"] = d.year();
    json["request_month"] = d.month();
    json["request_day"] = d.day();
    json["request_hour"] = t.hour();
    json["request_min"] = t.minute();
    json["request_sec"] = t.second();
    json["status"] = status;
}
