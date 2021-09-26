#ifndef LOGIN_LOGOUT2_UI_H
#define LOGIN_LOGOUT2_UI_H

#include <QDialog>

namespace Ui {
class login_logout2_ui;
}

class login_logout2_ui : public QDialog
{
    Q_OBJECT

public:
    explicit login_logout2_ui(QWidget *parent = nullptr,int _key=-1);
    ~login_logout2_ui();
    void setkey(int i){
       key=i;
    }

private:
    int key;
    Ui::login_logout2_ui *ui;
};

#endif // LOGIN_LOGOUT2_UI_H
