#include "nameeingabe.h"
#include "ui_nameeingabe.h"

Nameeingabe::Nameeingabe(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Nameeingabe)
{
    ui->setupUi(this);
}

Nameeingabe::~Nameeingabe()
{
    delete ui;
}


void Nameeingabe::on_pshCancel_clicked()
{
    close();
}
