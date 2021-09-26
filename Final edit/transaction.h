#ifndef TRANSACTION_H
#define TRANSACTION_H
#include<QString>
#include<QDateTime>
#include<QJsonObject>
#include<QJsonArray>
class Transaction
{
    QString origin_account_num;
    QString destination_account_num;
    double amount;
    QDateTime time;
    int type;

public:
    Transaction();
    QString get_origin_account();
    QString get_destination_account();
    double get_amount();
    QDateTime get_trans_time();
    int get_type();

    void set_origin(QString);
    void set_destination(QString);
    void set_time(QDateTime);
    void set_type(int);
    void set_amount(double);
    void read(const QJsonObject& json);
    void write(QJsonObject& json);
};

#endif // TRANSACTION_H
