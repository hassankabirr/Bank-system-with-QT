#include "longterminvestment.h"
#include"Global_data_variables.h"
#include<QMessageBox>
 shortTermInvestment tmp;
longTermInvestment::longTermInvestment()
{
    set_interest_rate(15);
    set_last_date_of_interest_calculate(get_sub_date());
    set_type(4);
}
void longTermInvestment::calculateInterest(){

    QDateTime now;
    now = QDateTime::currentDateTime();
    if(get_last_date_of_interest_calculate().daysTo(now) > 90){

        int tmpMonths = get_last_date_of_interest_calculate().daysTo(now) / 90;

        for(int i =0; i < tmpMonths;i++)
            set_balance(get_balance() * (1 + (get_interest() / 100)));


        set_last_date_of_interest_calculate(get_last_date_of_interest_calculate().addMonths(tmpMonths));

    }


}


bool longTermInvestment::requestCard(){
    return false;
}
bool longTermInvestment::transferMoneyViaAccount(QString accStr, float amount){
    int index = all_bank_accounts.search(accStr);

        if(get_balance() >= amount){
            QList<Bank_account*> tmp = all_bank_accounts.getlist();
            tmp[index]->set_balance(tmp[index]->get_balance() + amount);
            set_balance(get_balance() - amount);
        }
        else
        return false;
        Bank_account* b = new Bank_account;

        tmp.set_card(this->get_card());
        tmp.set_type(2);
        tmp.set_balance(this->get_balance());
        tmp.set_userlist(this->get_userslist());
        tmp.set_no_users(this->get_no_users());
        tmp.setacc_number(this->getacc_num());
        tmp.set_trans_list(this->get_transactionslist());
        tmp.set_sub_date(this->get_sub_date());
        tmp.set_request_flag(this->get_request_flag());
        b= &tmp;
        all_bank_accounts.add_account(b);
        all_bank_accounts.remove(this->getacc_num());


}
