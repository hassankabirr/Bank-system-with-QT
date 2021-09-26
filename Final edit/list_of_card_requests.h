#ifndef LIST_OF_CARD_REQUESTS_H
#define LIST_OF_CARD_REQUESTS_H

#include"card.h"
#include"card_request.h"
#include<QList>
class list_of_card_requests
{
    QList<Card_request> request_list;
public:
    list_of_card_requests();
    QList<Card_request>& get_list(){return request_list;}
    void read(const QJsonObject& json);
    void write(QJsonObject& json);
    int search(QString acc_num);
    void add_request(Card_request obj){request_list.append(obj);}
    void remove(QString sender_acc);
};

#endif // LIST_OF_CARD_REQUESTS_H
