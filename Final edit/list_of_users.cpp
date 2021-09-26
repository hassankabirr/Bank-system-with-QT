#include "list_of_users.h"

list_of_users::list_of_users()
{

}

void list_of_users::read(const QJsonObject &json)
{
    int i =0 ;
    QJsonArray arr=json["users"].toArray();
    user_list.clear();
    if(arr.isEmpty()==false)
    {
    for(i=0;i<arr.size();i++){
        QJsonObject obj = arr[i].toObject();
        User r;
        r.read(obj);
        user_list.append(r);
    }
}

}

void list_of_users::write(QJsonObject &json)
{
    int i;
    QJsonArray arr;
    QJsonObject obj;
    for(i=0;i<user_list.size();i++){
        user_list[i].write(obj);
        arr.append(obj);
    }
    json["users"] = arr;


}

int list_of_users::search(QString _national_code)
{
    int i,flag=2;
    for(i=0;i<user_list.size();i++){
        if(user_list[i].get_national_code()==_national_code){
            flag=1;
            return i;
            break;
        }
    }
    if(flag!=1)return -1;

}

int list_of_users::search_byusername(QString _user)
{
    int i,flag=2;
    for(i=0;i<user_list.size();i++){
        if(user_list[i].get_username()==_user){
            flag=1;
            return i;
            break;
        }
    }
    if(flag!=1)return -1;

}

int list_of_users::search_byname(QString _name)
{
    int i,flag=2;
    for(i=0;i<user_list.size();i++){
        if(user_list[i].get_name()==_name){
            flag=1;
            return i;
            break;
        }
    }
    if(flag!=1)return -1;

}

void list_of_users::remove(QString _username)
{
    int userindex = search_byusername(_username);
    user_list.removeAt(userindex);

}
