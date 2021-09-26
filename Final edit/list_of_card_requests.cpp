#include "list_of_card_requests.h"

list_of_card_requests::list_of_card_requests()
{

}

void list_of_card_requests::read(const QJsonObject &json)
{
    int i =0 ;
    QJsonArray arr=json["requests"].toArray();
    request_list.clear();
    if(arr.isEmpty()==false){
    for(i=0;i<arr.size();i++){
        QJsonObject obj = arr[i].toObject();
        Card_request r;
        r.read(obj);
        request_list.append(r);
    }
    }
    else qDebug()<<"empty";

}

void list_of_card_requests::write(QJsonObject &json)
{
    int i;
    QJsonArray arr;
    QJsonObject obj;
    for(i=0;i<request_list.size();i++){
        request_list[i].write(obj);
        arr.append(obj);
    }
    json["requests"] = arr;

}

int list_of_card_requests::search(QString acc_num)
{
    int i,flag=2;
    for(i=0;i<request_list.size();i++){
        if(request_list[i].get_acc_num()==acc_num){
            flag=1;
            return i;
            break;
        }
    }
    if(flag!=1)return -1;

}

void list_of_card_requests::remove(QString sender_acc)
{
    int senderindex = search(sender_acc);
    request_list.removeAt(senderindex);

}
