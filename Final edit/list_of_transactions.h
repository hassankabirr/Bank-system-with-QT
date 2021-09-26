#ifndef LIST_OF_TRANSACTIONS_H
#define LIST_OF_TRANSACTIONS_H

#include"transaction.h"
#include<QList>
#include<QJsonObject>
#include<QJsonArray>
class list_of_transactions
{
    QList<Transaction> tr_list;
public:
    list_of_transactions();
    QList<Transaction>& get_list(){return tr_list;}
    void read(const QJsonObject &json);
    void write(QJsonObject &json );
    void add_transaction(Transaction& obj){
        tr_list.append(obj);
    }
    int search(QString origin_acc_num);
    void remove(QString origin_acc_num);
};

#endif // LIST_OF_TRANSACTIONS_H
