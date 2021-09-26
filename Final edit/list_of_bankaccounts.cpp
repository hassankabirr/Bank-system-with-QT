#include "list_of_bankaccounts.h"
#include<QDebug>
list_of_bankaccounts::list_of_bankaccounts()
{

}

void list_of_bankaccounts::read(const QJsonObject &json)
{
    int j=0;
    QJsonArray account_arr = json["accounts"].toArray();
    accs_list.clear();

    if(account_arr.isEmpty()==false)
    for(int i=0;i<account_arr.size();i++){
        Bank_account* b ;
        Bank_account _ba;

        QJsonObject obj = account_arr[i].toObject();
     //   qDebug()<<obj;
        // b = new Bank_account;
        _ba.read(obj);
        int _type = _ba.get_type();

        if(_type==1){
            acc1.set_card(_ba.get_card());
            acc1.set_type(1);
            acc1.set_balance(_ba.get_balance());
            acc1.set_userlist(_ba.get_userslist());
            acc1.set_no_users(_ba.get_no_users());
            acc1.setacc_number(_ba.getacc_num());
            acc1.set_trans_list(_ba.get_transactionslist());
            acc1.set_sub_date(_ba.get_sub_date());
            acc1.set_request_flag(_ba.get_request_flag());
            acc1.set_status(_ba.get_status());
            acc1arr.append( acc1);
           b = &acc1arr[acc1arr.size()-1];

        }
        else if(_type==2){
            acc2.set_card(_ba.get_card());
            acc2.set_type(2);
            acc2.set_balance(_ba.get_balance());
            acc2.set_userlist(_ba.get_userslist());
            acc2.set_no_users(_ba.get_no_users());
            acc2.setacc_number(_ba.getacc_num());
            acc2.set_trans_list(_ba.get_transactionslist());
            acc2.set_sub_date(_ba.get_sub_date());
            acc2.set_request_flag(_ba.get_request_flag());
            acc2.set_status(_ba.get_status());
            acc2arr.append( acc2);
           b = &acc2arr[acc2arr.size()-1];

        }
        else if(_type==3){
            acc3.set_card(_ba.get_card());
            acc3.set_type(3);
            acc3.set_balance(_ba.get_balance());
            acc3.set_userlist(_ba.get_userslist());
            acc3.set_no_users(_ba.get_no_users());
            acc3.setacc_number(_ba.getacc_num());
            acc3.set_trans_list(_ba.get_transactionslist());
            acc3.set_sub_date(_ba.get_sub_date());
            acc3.set_request_flag(_ba.get_request_flag());
            acc3.set_status(_ba.get_status());
            acc3arr.append( acc3);
           b = &acc3arr[acc3arr.size()-1];
        }
        else if(_type==4){
            acc4.set_card(_ba.get_card());
            acc4.set_type(4);
            acc4.set_balance(_ba.get_balance());
            acc4.set_userlist(_ba.get_userslist());
            acc4.set_no_users(_ba.get_no_users());
            acc4.setacc_number(_ba.getacc_num());
            acc4.set_trans_list(_ba.get_transactionslist());
            acc4.set_sub_date(_ba.get_sub_date());
            acc4.set_request_flag(_ba.get_request_flag());
            acc4.set_status(_ba.get_status());
            acc4arr.append(acc4);
           b = &acc4arr[acc4arr.size()-1];
        }
        //qDebug()<<b;
        accs_list.append(b);

      //  delete b;
    }

}

void list_of_bankaccounts::write(QJsonObject &json)
{
    QJsonObject obj;
    QJsonArray arr;
    int i;
    for(i=0;i<accs_list.size();i++){
        accs_list[i]->write(obj);
        arr.append(obj);
    }
    json["accounts"] = arr;


}

int list_of_bankaccounts::search(QString _accnum)
{
    int i=0;
    int flag=2;

    for(i=0;i<accs_list.size();i++){
        if(accs_list[i]->getacc_num()==_accnum){
            flag=1;
            return i;
            break;
        }
    }
    if(flag!=1)return -1;

}

void list_of_bankaccounts::add_account(Bank_account *obj)
{
    accs_list.append(obj);
}
int list_of_bankaccounts::search_via_card(QString _cardNUmb){ // Ediiiiiiiiiiiitted
    for(int i = 0; i < accs_list.size(); i++){
        //qDebug()<<accs_list[i]->get_card().get_cardnum();
        if(accs_list[i]->get_card().get_cardnum() == _cardNUmb)
            return i;
    }
    return -1;

};

void list_of_bankaccounts::remove(QString _accnum)
{
    int acc_index = search(_accnum);
    accs_list.removeAt(acc_index);
}
