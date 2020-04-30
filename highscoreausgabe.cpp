#include "highscoreausgabe.h"
#include "ui_highscoreausgabe.h"

Highscoreausgabe::Highscoreausgabe(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Highscoreausgabe)
{
    ui->setupUi(this);
}

Highscoreausgabe::~Highscoreausgabe()
{
    delete ui;
}
