#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "bank_account.h"

class savingsAccount : public Bank_account
{

public:
    savingsAccount();
 //   bool requestCard();
    void calculateInterest();
    bool transferMoneyViaAccount(QString, float);
    bool transferMoneyViaCard(QString, float);
};


#endif // SAVINGSACCOUNT_H
