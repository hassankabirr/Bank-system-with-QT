#ifndef USERS_INFO_UI_H
#define USERS_INFO_UI_H

#include <QDialog>

namespace Ui {
class Users_info_ui;
}

class Users_info_ui : public QDialog
{
    Q_OBJECT

public:
    explicit Users_info_ui(QWidget *parent = nullptr);
    ~Users_info_ui();

private:
    Ui::Users_info_ui *ui;
};

#endif // USERS_INFO_UI_H
