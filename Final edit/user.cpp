#include "user.h"
#include"Global_data_variables.h"
User::User()
{

}
void User::set_name(QString _Name){
    Name=_Name;
}
void User::set_birthdate(QDate _birthdate){
    birthdate=_birthdate;
}
void User::set_national_code(QString _nationalcode){
    national_code=_nationalcode;
}
void User::set_username(QString _username){
    username=_username;
}
void User::set_password(QString _password){
    password=_password;
}
void User::set_email(QString _email){
    email=_email;
}

void User::read(const QJsonObject &json)
{
    Name = json["name"].toString();
    national_code = json["national_code"].toString();
    QDate d(json["b_year"].toInt(),json["b_month"].toInt(),json["b_day"].toInt());
    birthdate = d;
    username = json["username"].toString();
    password = json["password"].toString();
    QJsonArray arr = json["accounts"].toArray();
    bank_accounts.clear();
    if(arr.isEmpty()==false){
    for(int i=0;i<arr.size();i++){//bug
     int index = all_bank_accounts.search(arr[i].toString());
  //  qDebug()<<arr[i].toString();
    // qDebug()<<index;
     bank_accounts.append(  all_bank_accounts.getlist()[index]);
    }
    }
    email = json["email"].toString();
    arr = json["login"].toArray();
    if(arr.isEmpty()==false){
    for(int i=0;i<arr.size();i++){
       QJsonObject obj=  arr[i].toObject();
       QDate d(obj["lin_year"].toInt(),obj["lin_month"].toInt(),obj["lin_day"].toInt());
       QTime t(obj["lin_hour"].toInt(),obj["lin_min"].toInt(),obj["lin_sec"].toInt());
       QDateTime date(d,t);
       logintime.append(date);}
    }
    arr = json["logout"].toArray();
    if(arr.isEmpty()==false){
    for(int i=0;i<arr.size();i++){
       QJsonObject obj=  arr[i].toObject();
       QDate d(obj["lout_year"].toInt(),obj["lout_month"].toInt(),obj["lout_day"].toInt());
       QTime t(obj["lout_hour"].toInt(),obj["lout_min"].toInt(),obj["lout_sec"].toInt());
       QDateTime date(d,t);
       logouttime.append(date);}
    }

}

void User::write(QJsonObject &json)
{
    json["name"] = Name;
    json["national_code"] = national_code;
    json["b_year"] = birthdate.year();
    json["b_month"] = birthdate.month();
    json["b_day"] = birthdate.day();
    json["username"] = username;
    json["password"] = password;
    QJsonArray accountarr;
    for(int i=0;i<bank_accounts.size();i++){
        accountarr.append(bank_accounts[i]->getacc_num());
    }
    json["accounts"] = accountarr;
    json["email"] = email;
    QJsonArray _logintimes ;

    for(int i=0;i<logintime.size();i++){
    QJsonObject date;
    date["lin_year"] = logintime[i].date().year();
    date["lin_month"] = logintime[i].date().month();
    date["lin_day"] = logintime[i].date().day();
    date["lin_hour"] = logintime[i].time().hour();
    date["lin_min"] = logintime[i].time().minute();
    date["lin_sec"] = logintime[i].time().second();
    _logintimes.append(date);
    }
    json["login"] = _logintimes;
    QJsonArray _logouttimes ;

    for(int i=0;i<logouttime.size();i++){
    QJsonObject date;
    date["lout_year"] = logouttime[i].date().year();
    date["lout_month"] = logouttime[i].date().month();
    date["lout_day"] = logouttime[i].date().day();
    date["lout_hour"] = logouttime[i].time().hour();
    date["lout_min"] = logouttime[i].time().minute();
    date["lout_sec"] = logouttime[i].time().second();
    _logouttimes.append(date);
    }
    json["logout"] = _logouttimes;


}
QList<Bank_account*> User::get_list_of_accounts(){
   return bank_accounts;
}
void User::set_logintime(QList<QDateTime>& _logintime){
    logintime=_logintime;
}
void User::set_logouttime(QList<QDateTime>&  _logoutime){
    logouttime=_logoutime;
}

void User::add_login(QDateTime _d)
{
    logintime.append(_d);
}

void User::add_logout(QDateTime _d)
{
    logouttime.append(_d);
}
QString User::get_name(){
    return Name;
}
QString User::get_email(){
    return email;
}
QString User::get_password(){
    return password;
}
QString User::get_username(){
    return username;
}
QDate User::get_birthdate(){
    return birthdate;
}
QList<QDateTime>& User::get_login_time(){
    return logintime;
}
QList<QDateTime>& User::get_logout_time(){
    return logouttime;
}
QString User::get_national_code(){
    return national_code;
}
void User::add_account(Bank_account* _bank_account){
    bank_accounts.push_back(_bank_account);
}
void request_new_account(){

}





















