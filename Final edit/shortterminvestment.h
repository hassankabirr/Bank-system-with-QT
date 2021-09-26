#ifndef SHORTTIMEINVESTMENT_H
#define SHORTTIMEINVESTMENT_H

#include "bank_account.h"

class shortTermInvestment :public Bank_account
{

public:
    shortTermInvestment();
  //  bool requestCard();
    void calculateInterest();
    bool transferMoneyViaAccount(QString, float);
    bool transferMoneyViaCard(QString, float);
};

#endif // SHORTTIMEINVESTMENT_H
