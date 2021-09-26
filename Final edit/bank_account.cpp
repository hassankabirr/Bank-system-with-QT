#include "bank_account.h"
#include "Global_data_variables.h"
Bank_account::Bank_account()
{
interest_rate=0;
card_request_flag=0;

}

void Bank_account::incoming_cash(double _cash)
{
    balance+=_cash;

}

void Bank_account::add_transaction(Transaction obj)
{
    transaction_list.append(obj);

}

void Bank_account::calculateInterest()
{
    return;

}

bool Bank_account::transferMoneyViaAccount(QString, float)
{
    return true;

}

bool Bank_account::requestCard()
{
    if((all_bank_accounts.getlist()[activeaccount]->get_card().get_cardnum()!="0")&&(all_bank_accounts.getlist()[activeaccount]->get_card().get_expiration()>QDate::currentDate())){
    return false;
    }
    else{

        return true;
    }

}

void Bank_account::read(const QJsonObject &json)
{
   acc_num =json["acc_num"].toString();
   type = json["type"].toInt();
   QDate q(json["sub_year"].toInt(),json["sub_month"].toInt(),json["sub_day"].toInt());
   QTime t(json["sub_hour"].toInt(),json["sub_min"].toInt(),json["sub_sec"].toInt());
   QDateTime date(q,t);
   submission_date = date;
   balance = json["balance"].toDouble();
   QJsonArray _card = json["card"].toArray();

   card.set_cardnum(_card[0].toString());
   card.set_acc_num(_card[1].toString());
   QDate cdate(_card[2].toInt(),_card[3].toInt(),1);
   card.set_expiration(cdate);
   card.set_cvvt(_card[4].toString());
   card.set_status(_card[5].toInt());

   status = json["status"].toInt();
   card_request_flag = json["request_flag"].toInt();
   QJsonArray _userarr = json["users"].toArray();
   users_ids.clear();

   for(int i=0;i<_userarr.size();i++){
       users_ids.append(_userarr[i].toString());
   }

   QJsonArray _transactions = json["transactions"].toArray();
   transaction_list.clear();
   if(_transactions.isEmpty()==false){
    for(int i=0;i<_transactions.size();i++){
        QJsonObject obj = _transactions[i].toObject();
        Transaction t;
        t.read(obj);
        transaction_list.append(t);

    }
   }

}

void Bank_account::write(QJsonObject &json)
{
    json["acc_num"] = acc_num;
    json["type"] = type;
    json["sub_year"]=submission_date.date().year();
    json["sub_month"]=submission_date.date().month();
    json["sub_day"]=submission_date.date().day();
    json["sub_hour"]=submission_date.time().hour();
    json["sub_min"]=submission_date.time().minute();
    json["sub_sec"]=submission_date.time().second();
    json["balance"] = balance;
    QJsonArray _cardarr;
    _cardarr.append(card.get_cardnum());
    _cardarr.append(card.get_acc_num());
    _cardarr.append(card.get_expiration().year());
    _cardarr.append(card.get_expiration().month());
    _cardarr.append(card.get_cvvt());
    _cardarr.append(card.get_status());
    json["card"] = _cardarr;
    json["status"] = status;
    json["request_flag"] = card_request_flag;
    QJsonArray _userarr;
    for(int i=0;i<users_ids.size();i++){
        _userarr.append(users_ids[i]);
    }
    json["users"] = _userarr;
    int i;
    QJsonArray arr;
    QJsonObject obj;
    for(i=0;i<transaction_list.size();i++){
        transaction_list[i].write(obj);
        arr.append(obj);
    }
    json["transactions"] = arr;
}
