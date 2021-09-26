#ifndef DEL_UI_H
#define DEL_UI_H

#include <QDialog>
#include <QVector>

namespace Ui {
class Del_ui;
}

class Del_ui : public QDialog
{
    Q_OBJECT

public:
    explicit Del_ui(QWidget *parent = nullptr);
    ~Del_ui();
//signals:
//    void del_signal(QString);
public slots:
    void del_slot();

private:
    int j;
    QVector<QPushButton *> pbn_address;
    Ui::Del_ui *ui;
};

#endif // DEL_UI_H
