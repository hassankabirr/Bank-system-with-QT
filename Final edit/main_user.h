#ifndef MAIN_USER_H
#define MAIN_USER_H
#include<QDateTime>
#include<QString>
#include<QListWidgetItem>
#include<QListWidget>
#include <QWidget>
#include "accountwindow.h"
#include"list_of_account_requests.h"
#include<QDateTime>
QT_BEGIN_NAMESPACE
namespace Ui { class main_User; }
QT_END_NAMESPACE

class main_User : public QWidget
{
    Q_OBJECT

public:

    main_User(int,QWidget *parent = nullptr);
    ~main_User();

private slots:
    void account_type_changed(int);
    void on_edit_prof_button_clicked();
    void update_prof();
    //void on_log_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_accounts_number_List_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    int* listok;
    QList<QString>* tmp_a_l;
    int index;
    Ui::main_User *ui;
    accountwindow* acc_window;
};
#endif // MAIN_USER_H
