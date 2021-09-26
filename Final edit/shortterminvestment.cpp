#include "shortterminvestment.h"
#include"Global_data_variables.h"
shortTermInvestment::shortTermInvestment()
{
    set_interest_rate(5);
    set_last_date_of_interest_calculate(get_sub_date());
    set_type(2);


}
void shortTermInvestment::calculateInterest(){

    QDateTime now;
    now = QDateTime::currentDateTime();
    if(get_last_date_of_interest_calculate().daysTo(now) > 30){

        int tmpMonths = get_last_date_of_interest_calculate().daysTo(now) / 30;

        for(int i =0; i < tmpMonths;i++)
            set_balance(get_balance() * (1 + (get_interest() / 100)));


        set_last_date_of_interest_calculate(get_last_date_of_interest_calculate().addMonths(tmpMonths));

    }


}
bool shortTermInvestment::transferMoneyViaAccount(QString accStr, float amount){
    if(get_balance() >= amount){
        int index = all_bank_accounts.search(accStr);
        QList<Bank_account*> tmp = all_bank_accounts.getlist();
        tmp[index]->set_balance(tmp[index]->get_balance() + amount);
        set_balance(get_balance() - amount);
    }
    else
        return false;

}

