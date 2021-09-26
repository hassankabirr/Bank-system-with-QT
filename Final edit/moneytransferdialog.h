#ifndef MONEYTRANSFERDIALOG_H
#define MONEYTRANSFERDIALOG_H

#include <QDialog>
#include "smtp.h"
namespace Ui {
class moneytransferdialog;
}

class moneytransferdialog : public QDialog
{
    Q_OBJECT

public:
    explicit moneytransferdialog(QWidget *parent = nullptr);
    ~moneytransferdialog();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();
    void mailSent(QString status);
private:
    Ui::moneytransferdialog *ui;
};

#endif // MONEYTRANSFERDIALOG_H
