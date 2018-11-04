#ifndef WIGET_H
#define WIGET_H

#include <QMainWindow>

namespace Ui {
class wiget;
}

class wiget : public QMainWindow
{
    Q_OBJECT

public:
    explicit wiget(QWidget *parent = nullptr);
    ~wiget();
    int money_{0};
    void set_money(int value);
    void onoff_button();

private slots:
    void on_pb500_clicked();

    void on_pb100_clicked();

    void on_pb50_clicked();

    void on_pb10_clicked();

    void on_pbCoffee_clicked();

    void on_pbTea_clicked();

    void on_pbCola_clicked();

    void on_pbReset_clicked();

private:
    Ui::wiget *ui;
};

#endif // WIGET_H
