#include "paymentgateway.h"
#include "ui_paymentgateway.h"
#include "QMessageBox"
#include "Global_data_variables.h"
paymentGateWay::paymentGateWay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::paymentGateWay)
{
    ui->setupUi(this);
}

paymentGateWay::~paymentGateWay()
{
    delete ui;
}

void paymentGateWay::on_pushButton_3_clicked()
{
    QString originCardNum, destCardNumb, cvv2, secondPass;
    int year , month;
    originCardNum = ui->lineEdit_2->text();
    destCardNumb = ui->lineEdit->text();
    cvv2 = ui->lineEdit_3->text();
    secondPass = ui->lineEdit_6->text();
    year = ui->lineEdit_5->text().toInt();
    month = ui->lineEdit_4->text().toInt();
    double ammount = ui->lineEdit_7->text().toDouble();

    int Index = all_bank_accounts.search_via_card(originCardNum);
    if(Index == -1){
        QMessageBox msg;
        msg.setText("شماره کارت مبدا وجود نداشت !");
        msg.exec();
    }else{
        int tmpIndex = all_bank_accounts.search_via_card(destCardNumb);
            if(tmpIndex == -1){
                QMessageBox msg;
                msg.setText("شماره کارت مقصد وجود نداشت !");
                msg.exec();
            }else{
                QList<Bank_account*> tmp = all_bank_accounts.getlist();
                if(tmp[Index]->get_card().get_cvvt() == cvv2){
                    if(tmp[Index]->get_card().get_expiration().month() == month){
                        if(tmp[Index]->get_card().get_expiration().year()-2000 == year){
                            if(tmp[Index]->get_balance() >= ammount){
                                if(tmp[Index]->get_card().get_pin() == secondPass){
                                QMessageBox msg;
                                QString userncode = all_bank_accounts.getlist()[tmpIndex]->get_userslist()[0];
                                int userindex = all_users.search(userncode);
                                QString detail = all_users.get_list()[userindex].get_name()+"  مبلغ:"+ui->lineEdit_2->text();
                                msg.setDetailedText(detail);
                                msg.setText("از انتقال به این کارت مطمين هستید؟");
                                msg.setStandardButtons(QMessageBox::Yes);
                                msg.addButton(QMessageBox::No);
                                msg.setDefaultButton(QMessageBox::No);

                                int ret = msg.exec();
                                if(ret==QMessageBox::Yes){
                                    QTime TimeTmp = QTime::currentTime();
                                    if(tmp[Index]->get_card().get_pin_time().hour() == TimeTmp.hour() && TimeTmp.minute()-  tmp[Index]->get_card().get_pin_time().minute()  <= 2){
                                        if(tmp[Index]->get_card().get_pin_time().minute() - TimeTmp.minute() != 2){
                                            if(all_bank_accounts.getlist()[activeaccount]->get_card().get_status()==0){
                                                if(all_bank_accounts.getlist()[activeaccount]->get_status()==0){
                                            all_bank_accounts.getlist()[Index]->transferMoneyViaAccount(all_bank_accounts.getlist()[tmpIndex]->getacc_num(),ammount);
                                            Transaction tr;
                                            tr.set_origin(originCardNum);
                                            tr.set_type(2);
                                            tr.set_amount(ammount);
                                            tr.set_destination(destCardNumb);
                                            tr.set_time(QDateTime::currentDateTime());
                                            all_transactions.add_transaction(tr);
                                            tmp[Index]->add_transaction(tr);
                                            tmp[tmpIndex]->add_transaction(tr);
                                            QMessageBox msg3;
                                            msg3.setText("انتقال با موفقیت انجام شد");
                                            msg3.exec();
                                            save();
                                                }
                                                else{
                                                    QMessageBox msg4;
                                                    msg4.setText("حساب شما مسدود است");
                                                }
                                            }
                                            else{
                                                QMessageBox msg4;
                                                msg4.setText("کارت شما مسدود است");
                                            }
                                    }
                                    else{
                                        if(tmp[Index]->get_card().get_pin_time().second() >= TimeTmp.second()){
                                            if(all_bank_accounts.getlist()[activeaccount]->get_card().get_status()==0){
                                                if(all_bank_accounts.getlist()[activeaccount]->get_status()==0){
                                             all_bank_accounts.getlist()[Index]->transferMoneyViaAccount(all_bank_accounts.getlist()[tmpIndex]->getacc_num(),ammount);
                                            Transaction tr;
                                            tr.set_origin(originCardNum);
                                            tr.set_type(2);
                                            tr.set_amount(ammount);
                                            tr.set_destination(destCardNumb);
                                            tr.set_time(QDateTime::currentDateTime());
                                            all_transactions.add_transaction(tr);
                                            tmp[Index]->add_transaction(tr);
                                            tmp[tmpIndex]->add_transaction(tr);
                                            QMessageBox msg3;
                                            msg3.setText("انتقال با موفقیت انجام شد");
                                            msg3.exec();
                                            save();}
                                            }
                                        }

                                        else{

                                        QMessageBox msg;
                                        msg.setText("رمز دوم منقضی شده است");
                                        msg.exec();

                                        }
                                    }
                                    }else{

                                    QMessageBox msg;
                                    msg.setText("رمز دوم منقضی شده است");
                                    msg.exec();


                                    }
                                }
                            }else{

                                QMessageBox msg;
                                msg.setText("رمز دوم اشتباه است");
                                msg.exec();

                            }
                        }else{
                            QMessageBox msg;
                            msg.setText("موجودی کافی نیست");
                            msg.exec();
                        }
                        }else{
                            QMessageBox msg;
                            msg.setText("تاریخ انقضا اشتباه است");
                            msg.exec();
                        }
                    }else{
                        QMessageBox msg;
                        msg.setText("تاریخ انقضا اشتباه است");
                        msg.exec();
                    }

                }else{
                    QMessageBox msg;
                    msg.setText(".اشتباه است cvv2 شماره");
                    msg.exec();

                }

            }
        }//Ok
    }
