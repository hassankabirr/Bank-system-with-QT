#include "mainwindow.h"
#include"Global_data_variables.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

   // qDebug()<<bank_accounts.getlist()[0]->get_transactionslist()[0].get_amount();
    return a.exec();
}
