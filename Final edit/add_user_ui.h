#ifndef ADD_USER_UI_H
#define ADD_USER_UI_H

#include <QDialog>

namespace Ui {
class add_user_ui;
}

class add_user_ui : public QDialog
{
    Q_OBJECT

public:
    explicit add_user_ui(QWidget *parent = nullptr);
    ~add_user_ui();

private slots:
    void on_pushButton_clicked();

private:

    Ui::add_user_ui *ui;
};

#endif // ADD_USER_UI_H
