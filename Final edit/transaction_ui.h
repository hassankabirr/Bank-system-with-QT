#ifndef TRANSACTION_UI_H
#define TRANSACTION_UI_H

#include <QDialog>
#include <QGridLayout>
#include <QLabel>

namespace Ui {
class transaction_ui;
}

class transaction_ui : public QDialog
{
    Q_OBJECT

public:
    explicit transaction_ui(QWidget *parent = nullptr);
    ~transaction_ui();

private:
    Ui::transaction_ui *ui;
    QGridLayout* glo;
    QLabel* lbl1;
    QLabel* lbl2;
    QLabel* lbl3;
    QLabel* lbl4;
    QLabel* lbl5;

};

#endif // TRANSACTION_UI_H
