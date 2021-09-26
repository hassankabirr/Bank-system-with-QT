#include "card.h"
#include <QDateTime>

Card::Card()
{
    status  = 0;

}

void Card::read(const QJsonObject &json)
{
    card_num = json["card_number"].toString();
    account_num = json["acc_number"].toString();
    QDate d(json["exp_year"].toInt(),json["exp_month"].toInt(),0);
   expiration_date = d;
   cvvt = json["cvvt"].toString();
    status = json["status"].toInt();
}

void Card::write(QJsonObject &json)
{
    json["card_number"] = card_num;
    json["acc_number"] = account_num;
    json["exp_year"] = expiration_date.year();
    json["exp_month"] = expiration_date.month();


}
