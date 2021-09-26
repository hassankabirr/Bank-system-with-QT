#ifndef ADMIN_UI_H
#define ADMIN_UI_H
#include "users_info_ui.h"
#include "add_user_ui.h"

#include <QMainWindow>

namespace Ui {
class admin_ui;
}

class admin_ui : public QMainWindow
{
    Q_OBJECT

public:
    explicit admin_ui(QWidget *parent = nullptr);
    ~admin_ui();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_actionlogout_triggered();

    void on_pushButton_9_clicked();

private:

    Ui::admin_ui *ui;
};

#endif // ADMIN_UI_H
