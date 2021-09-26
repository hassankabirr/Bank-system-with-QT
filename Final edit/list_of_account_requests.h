#ifndef LIST_OF_ACCOUNT_REQUESTS_H
#define LIST_OF_ACCOUNT_REQUESTS_H
#include"account_request.h"
#include<QList>
#include<QJsonArray>
#include<QJsonObject>

class list_of_account_requests
{
    QList<account_request>request_list;
public:
    list_of_account_requests();
    QList<account_request>& getlist(){return request_list;}
    void read(const QJsonObject& json);
    void write(QJsonObject& json);
    int search(QString sender_national_code);
    void add_account(account_request obj){request_list.append(obj);}
    void remove(QString sender_ncode);
};

#endif // LIST_OF_ACCOUNT_REQUESTS_H
