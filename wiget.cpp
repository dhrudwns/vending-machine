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
    this->money_ += value;
    ui->lcdNumber->display(this->money_);
    onoff_button();
}

void wiget::onoff_button()
{
    if(this->money_ > 0) ui->reset->setEnabled(true);
    else ui->reset->setEnabled(false);
    if(this->money_ >= 100) ui->pbCoffee->setEnabled(true);
    else ui->pbCoffee->setEnabled(false);
    if(this->money_ >= 150) ui->pbTea->setEnabled(true);
    else ui->pbTea->setEnabled(false);
    if(this->money_ >= 200) ui->pbCola->setEnabled(true);
    else ui->pbCola->setEnabled(false);
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


void wiget::on_reset_clicked()
{
    int number_500, number_100, number_50, number_10;
    number_500 = this->money_ / 500;
    this->money_ -= number_500 * 500;
    number_100 = this->money_ / 100;
    this->money_ -= number_100 * 100;
    number_50 = this->money_ / 50;
    this->money_ -= number_50 * 50;
    number_10 = this->money_ / 10;
    this->money_ -= number_10 * 10;

    QString status =
            QString("500 : %1, 100 : %2, 50 : %3, 10 : %4")
            .arg(number_500).arg(number_100).arg(number_50).arg(number_10);
    QMessageBox::information(this, "reset", status);
    ui->lcdNumber->display(this->money_);
}
