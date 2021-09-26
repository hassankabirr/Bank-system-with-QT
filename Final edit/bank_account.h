#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H
#include"transaction.h"
#include<QString>
#include<QDate>
#include<QDateTime>
#include"card.h"
#include<QList>
#include<QJsonObject>
#include<QJsonArray>
#include<QJsonDocument>
#include<QJsonValue>

class Bank_account
{
    QString acc_num;
    QDateTime submission_date;
    QDateTime last_date_of_interest_calculate;
    double balance;
    Card card;
    float interest_rate;
    int type;
    QList<QString> users_ids;
    QList<Transaction> transaction_list;
    int card_request_flag;
    int no_users;
    int status;//0:open  1:blocked
public:
    Bank_account();
    QString getacc_num(){return acc_num;}
    QDateTime get_sub_date(){return submission_date;}
    double get_balance(){return balance;}
    Card& get_card(){return card;}
    float get_interest(){return interest_rate;}
    int get_type(){return type;}
    QDateTime get_last_date_of_interest_calculate(){return last_date_of_interest_calculate;}
    QList<QString>& get_userslist(){return users_ids;}
    QList<Transaction>& get_transactionslist(){return transaction_list;}
    int get_no_users(){return no_users;}
    void setacc_number(QString _num){acc_num =_num; }
    void set_sub_date(QDateTime _date){submission_date = _date;}
    void set_card(Card _c){card = _c;}
    void set_balance(double _balance){balance = _balance;}
    void set_type(int _type){type = _type;}
    void set_userlist(QList<QString>& _list ){users_ids = _list;}
    void set_no_users(int _no){no_users = _no;}
    void set_trans_list(QList<Transaction> _list){transaction_list = _list;}
    void incoming_cash(double _cash);
    void add_transaction(Transaction obj);
    void set_interest_rate(float _interest_rate){interest_rate = _interest_rate;}
     void set_last_date_of_interest_calculate(QDateTime _last_date_of_interest_calculate){last_date_of_interest_calculate = _last_date_of_interest_calculate;}
   virtual void calculateInterest();//remaining
    virtual bool transferMoneyViaAccount(QString, float);//remaining
    //virtual bool transferMoneyViaCard(QString, float);//remaining
    virtual bool requestCard();//remaining
    void get_dynamic_pin();//remaining
    void read(const QJsonObject &json);
    void write(QJsonObject &json);
    int get_request_flag(){return card_request_flag;}
    void set_request_flag(int _flag){card_request_flag = _flag;}
    int get_status(){return status;}
    void set_status(int _status){status = _status;}


};



#endif // BANK_ACCOUNT_H
