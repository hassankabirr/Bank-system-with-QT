#ifndef CARD_REQ_UI_H
#define CARD_REQ_UI_H
#include <QLabel>
#include <QPushButton>
#include <QVector>
#include <QGridLayout>
#include <QDialog>
#include <QDate>

namespace Ui {
class card_req_ui;
}

class card_req_ui : public QDialog
{
    Q_OBJECT

public:
    explicit card_req_ui(QWidget *parent = nullptr);
    ~card_req_ui();
public slots:
  void  accept_card();
  void  decline_card();


private:
    Ui::card_req_ui *ui;

    QVector<QPushButton*> pbn_accept;
    QVector<QPushButton*> pbn_decline;


    QPushButton* yes;
    QPushButton* no;


};

#endif // CARD_REQ_UI_H
