#include "transaction.h"

Transaction::Transaction()
{

}
QString Transaction::get_origin_account(){
    return origin_account_num;
}
QString Transaction::get_destination_account(){
    return destination_account_num;
}
int Transaction::get_type(){
    return type;
}
double Transaction::get_amount(){
    return amount;
}
QDateTime Transaction::get_trans_time(){
    return time;
}
void Transaction::set_time(QDateTime _time){
    time=_time;
}
void Transaction::set_type(int _type){
    type=_type;
}
void Transaction::set_origin(QString _origin_num){
    origin_account_num=_origin_num;
}
void Transaction::set_destination(QString _destination_num){
    destination_account_num=_destination_num;
}
void Transaction::set_amount(double _amount){
    amount=_amount;
}

void Transaction::read(const QJsonObject &json)
{
    origin_account_num = json["from"].toString();
    destination_account_num = json["to"].toString();
    amount = json["ammount"].toDouble();
    type = json["type_of_trans"].toInt();
    QDate d(json["t_year"].toInt(),json["t_month"].toInt(),json["t_day"].toInt());
    QTime t(json["t_hour"].toInt(),json["t_min"].toInt(),json["t_sec"].toInt());
    QDateTime date(d,t);
    time = date;

}

void Transaction::write(QJsonObject &json)
{
    json["from"] = origin_account_num;
    json["to"] = destination_account_num;
    json["ammount"] = amount;
    json["type_of_trans"] = type;
    json["t_year"] = time.date().year();
    json["t_month"] = time.date().month();
    json["t_day"] = time.date().day();
    json["t_hour"] = time.time().hour();
    json["t_min"] = time.time().minute();
    json["t_sec"] = time.time().second();
}

