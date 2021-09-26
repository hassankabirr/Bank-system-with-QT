#ifndef EDIT_PROFILE_DIALOG_H
#define EDIT_PROFILE_DIALOG_H

#include<QDate>
#include<QDateTime>
#include<QMessageBox>
#include <QDialog>

namespace Ui {
class Edit_Profile_Dialog;
}

class Edit_Profile_Dialog : public QDialog
{
    Q_OBJECT
signals:
    void update_profedit();
public:
    explicit Edit_Profile_Dialog(int,QWidget *parent = nullptr);
    ~Edit_Profile_Dialog();

private slots:
    void on_buttonBox_accepted();

private:
    int id;
    Ui::Edit_Profile_Dialog *ui;
};

#endif // EDIT_PROFILE_DIALOG_H
