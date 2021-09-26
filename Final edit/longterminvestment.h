#ifndef LONGTERMINVESTMENT_H
#define LONGTERMINVESTMENT_H

#include "bank_account.h"

class longTermInvestment : public Bank_account
{

public:
    longTermInvestment();
    bool requestCard();
    void calculateInterest();
    bool transferMoneyViaAccount(QString, float);
    bool transferMoneyViaCard(QString, float);
};

#endif // LONGTERMINVESTMENT_H
