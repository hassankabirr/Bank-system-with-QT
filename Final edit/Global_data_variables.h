#ifndef GLOBAL_DATA_VARIABLES_H
#define GLOBAL_DATA_VARIABLES_H
#include"list_of_users.h"
#include"list_of_bankaccounts.h"
#include"list_of_account_requests.h"
#include"list_of_card_requests.h"
#include"list_of_transactions.h"
#include"admin.h"
#include<QFile>
extern list_of_bankaccounts all_bank_accounts;
extern list_of_users all_users;
extern list_of_transactions all_transactions;
extern list_of_card_requests all_cardrequests;
extern list_of_account_requests all_accountrequests;
extern shortTermInvestment tmp;
extern int activeaccount;
extern int activeuser;
//extern admin manager;
extern QFile file;
 extern void load();
extern void save();
#endif // GLOBAL_DATA_VARIABLES_H
