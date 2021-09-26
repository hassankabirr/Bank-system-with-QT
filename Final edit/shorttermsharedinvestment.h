#ifndef SHORTTERMSHAREDINVESTMENT_H
#define SHORTTERMSHAREDINVESTMENT_H

#include "bank_account.h"
class shortTermSharedInvestment:public Bank_account
{
public:
    shortTermSharedInvestment();
   // bool requestCard();
    void calculateInterest();
    bool transferMoneyViaAccount(QString, float);
    bool transferMoneyViaCard(QString, float);
};

#endif // SHORTTERMSHAREDINVESTMENT_H
