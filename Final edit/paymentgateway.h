#ifndef PAYMENTGATEWAY_H
#define PAYMENTGATEWAY_H

#include <QWidget>

namespace Ui {
class paymentGateWay;
}

class paymentGateWay : public QWidget
{
    Q_OBJECT

public:
    explicit paymentGateWay(QWidget *parent = nullptr);
    ~paymentGateWay();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::paymentGateWay *ui;
};

#endif // PAYMENTGATEWAY_H
