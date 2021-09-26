#ifndef LIST_OF_BANKACCOUNTS_H
#define LIST_OF_BANKACCOUNTS_H

#include"bank_account.h"
#include<QList>
#include<QJsonObject>
#include<QJsonArray>
#include<QJsonValue>
#include"savingsaccount.h"
#include"longterminvestment.h"
#include"shortterminvestment.h"
#include"shorttermsharedinvestment.h"
class list_of_bankaccounts
{
    QList<Bank_account*> accs_list;
    savingsAccount acc1;
    longTermInvestment acc4;
    shortTermInvestment acc2;
    shortTermSharedInvestment acc3;
    QList<savingsAccount> acc1arr;
    QList<longTermInvestment> acc4arr;
    QList<shortTermInvestment> acc2arr;
    QList<shortTermSharedInvestment> acc3arr;
public:
    list_of_bankaccounts();
    QList<Bank_account*>& getlist(){return accs_list;}
    void read(const QJsonObject& json);
    void write(QJsonObject& json);
    int search(QString _accnum);
    void add_account(Bank_account* obj);
    void remove(QString _accnum);
    int search_via_card(QString _cardNUmb);
};

#endif // LIST_OF_BANKACCOUNTS_H
