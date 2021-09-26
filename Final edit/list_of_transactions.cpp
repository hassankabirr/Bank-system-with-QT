#include "list_of_transactions.h"

list_of_transactions::list_of_transactions()
{

}

void list_of_transactions::read(const QJsonObject &json)
{
    int i =0 ;
    QJsonArray arr=json["transactions"].toArray();
    tr_list.clear();
    if(arr.isEmpty()==false)
    for(i=0;i<arr.size();i++){
        QJsonObject obj = arr[i].toObject();
        Transaction r;
        r.read(obj);
        tr_list.append(r);
    }

}

void list_of_transactions::write(QJsonObject &json)
{
    int i;
    QJsonArray arr;
    QJsonObject obj;
    for(i=0;i<tr_list.size();i++){
        tr_list[i].write(obj);
        arr.append(obj);
    }
    json["transactions"] = arr;
}

int list_of_transactions::search(QString origin_acc_num)
{
    int i,flag=2;
    for(i=0;i<tr_list.size();i++){
        if(tr_list[i].get_origin_account()==origin_acc_num){
            flag=1;
            return i;
            break;
        }
    }
    if(flag!=1)return -1;
}

void list_of_transactions::remove(QString origin_acc_num)
{
    int tranindex = search(origin_acc_num);
    tr_list.removeAt(tranindex);
}

