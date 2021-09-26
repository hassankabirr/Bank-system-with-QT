#include "list_of_account_requests.h"

list_of_account_requests::list_of_account_requests()
{

}

void list_of_account_requests::read(const QJsonObject &json)
{
    int i =0 ;
    QJsonArray arr=json["acc_requests"].toArray();
    request_list.clear();
    if(arr.isEmpty()==false){
    for(i=0;i<arr.size();i++){
        QJsonObject obj = arr[i].toObject();
        account_request r;
        r.read(obj);
        request_list.append(r);
    }
    }
    else qDebug()<<"empty";
}

void list_of_account_requests::write(QJsonObject &json)
{
    int i;
    QJsonArray arr;
    QJsonObject obj;
    for(i=0;i<request_list.size();i++){
        request_list[i].write(obj);
        arr.append(obj);
    }
    json["acc_requests"] = arr;
}

int list_of_account_requests::search(QString sender_national_code)
{
    int i,flag=2;
    for(i=0;i<request_list.size();i++){
        if(request_list[i].get_sender_ncode()==sender_national_code){
            flag=1;
            return i;
            break;
        }
    }
    if(flag!=1)return -1;
}

void list_of_account_requests::remove(QString sender_ncode)
{
    int senderindex = search(sender_ncode);
    request_list.removeAt(senderindex);
}
