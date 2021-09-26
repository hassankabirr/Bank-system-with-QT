#include "account_request.h"

account_request::account_request()
{
    status = 0;
}

void account_request::read(const QJsonObject &json)
{
    sender_national_code = json["sender"].toString();
    QDate d(json["request_year"].toInt(),json["request_month"].toInt(),json["request_day"].toInt());
    QTime t(json["request_hour"].toInt(),json["request_min"].toInt(),json["request_sec"].toInt());
    QDateTime date(d,t);
    time_of_request = date;
    starting_balance = json["balance"].toDouble();
    type = json["type"].toInt();
    status = json["status"].toInt();

    users_ids.clear();
    QJsonArray userarr = json["users"].toArray();
    for(int i=0;i<userarr.size();i++){
        users_ids.append(userarr[i].toString());
    }
    no_users = users_ids.size();

}

void account_request::write(QJsonObject &json)
{
    json["sender"] = sender_national_code;
    json["request_year"] = time_of_request.date().year();
    json["request_month"] = time_of_request.date().month();
    json["request_day"] = time_of_request.date().day();
    json["request_hour"] = time_of_request.time().hour();
    json["request_min"] = time_of_request.time().minute();
    json["request_sec"] = time_of_request.time().second();
    json["balance"] = starting_balance;
    json["type"] = type;
    json["status"] = status;
    QJsonArray userarr;
    for(int i=0;i<users_ids.size();i++){
        userarr.append(users_ids[i]);
    }
    json["users"] = userarr;
}
