#include "wiget.h"
#include "ui_wiget.h"
#include <QMessageBox>

wiget::wiget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::wiget)
{
    ui->setupUi(this);
}

wiget::~wiget()
{
    delete ui;
}

void wiget::set_money(int value)
{
    money_ += value;
    ui->lcdNumber->display(money_);
    onoff_button();
}

void wiget::onoff_button()
{

    ui->pbReset->setEnabled(money_ > 0);
    ui->pbCoffee->setEnabled(money_ > 100);
    ui->pbTea->setEnabled(money_ > 150);
    ui->pbCola->setEnabled(money_ > 200);
}

void wiget::on_pb500_clicked()
{
    set_money(500);
}

void wiget::on_pb100_clicked()
{
    set_money(100);
}

void wiget::on_pb50_clicked()
{
    set_money(50);
}

void wiget::on_pb10_clicked()
{
    set_money(10);
}

void wiget::on_pbCoffee_clicked()
{
    set_money(-100);
}

void wiget::on_pbTea_clicked()
{
    set_money(-150);
}

void wiget::on_pbCola_clicked()
{
    set_money(-200);
}

void wiget::on_pbReset_clicked()
{
    int coins[]={500,100,50,10};
    int count[4]={0};
    for(int i=0; i<4; i++)
    {
        count[i] = money_ / coins[i];
        money_ -= coins[i]*count[i];
    }
    QString status =
            QString("500 : %1, 100 : %2, 50 : %3, 10 : %4")
            .arg(count[0]).arg(count[1]).arg(count[2]).arg(count[3]);
    QMessageBox::
    QMessageBox::information(this, "reset", status);
    ui->lcdNumber->display(money_);
    onoff_button();
}
