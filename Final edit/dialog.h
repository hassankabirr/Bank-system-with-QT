#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QComboBox>
#include<QMessageBox>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
public slots:
    void card_situation();
    void acc_situation();
    void card_slot(int row,int column);


private:
    QVector<QPushButton*> card_block;
    QVector<QPushButton*> acc_block;

    QComboBox * cb;
    Ui::Dialog *ui;
};

#endif // DIALOG_H
