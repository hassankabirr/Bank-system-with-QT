#ifndef DIALOG_ADD_ACCOUNT_H
#define DIALOG_ADD_ACCOUNT_H

#include <QDialog>

namespace Ui {
class Dialog_add_account;
}

class Dialog_add_account : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_add_account(QList<QString>*,int*,QWidget *parent = nullptr);
    ~Dialog_add_account();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    int* _listok;
    Ui::Dialog_add_account *ui;
    QList<QString>* ql;
};

#endif // DIALOG_ADD_ACCOUNT_H
