#ifndef LIST_OF_USERS_H
#define LIST_OF_USERS_H
#include"user.h"
#include<QJsonObject>
#include<QJsonArray>
#include<QList>
class list_of_users
{
    QList<User> user_list;
public:
    list_of_users();
    QList<User>& get_list(){return user_list;}
    void read(const QJsonObject &json);
    void write(QJsonObject &json);
    void add_user(User& obj){
        user_list.append(obj);
    }
    int search(QString _national_code);
    int search_byusername(QString _user);
    int search_byname(QString _name);
    void remove(QString _username);

};

#endif // LIST_OF_USERS_H
