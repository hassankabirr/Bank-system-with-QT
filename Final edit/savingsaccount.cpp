#include "savingsaccount.h"
#include"Global_data_variables.h"
savingsAccount::savingsAccount()
{
    set_interest_rate( 0 );
    set_type(1);



}

void savingsAccount::calculateInterest(){
    return;
}
bool savingsAccount::transferMoneyViaAccount(QString accStr, float amount){
    if(get_balance() >= amount){
        int index = all_bank_accounts.search(accStr);
        QList<Bank_account*> tmp = all_bank_accounts.getlist();
        tmp[index]->set_balance(tmp[index]->get_balance() + amount);
        set_balance(get_balance() - amount);
    }
    else
        return false;

}
