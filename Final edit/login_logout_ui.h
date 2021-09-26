#ifndef LOGIN_LOGOUT_UI_H
#define LOGIN_LOGOUT_UI_H

#include <QDialog>
#include <QListWidget>
#include "login_logout2_ui.h"

namespace Ui {
class login_logout_ui;
}

class login_logout_ui : public QDialog
{
    Q_OBJECT

public:
    explicit login_logout_ui(QWidget *parent = nullptr);
    ~login_logout_ui();
public slots:
    void loged(QListWidgetItem *item);


private:
    Ui::login_logout_ui *ui;
};

#endif // LOGIN_LOGOUT_UI_H
