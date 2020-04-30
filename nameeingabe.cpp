#include "nameeingabe.h"
#include "ui_nameeingabe.h"
#include "QString"

Nameeingabe::Nameeingabe(int *scorepointer, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Nameeingabe)
{
    this->scorepointer = scorepointer;
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

//Speicherung in einer Textdatei
/*
void highscore(QString name, int score)
{
    FILE *fptr;
    fptr = fopen("Highscores.txt", "a+");

    if (fptr == nullptr)
    {
        return;
    }

    fprintf(fptr, "%s; %i;", "Name", score);
    fprintf(fptr, "\n");

    fclose(fptr);
}
*/

void Nameeingabe::on_pshOK_clicked()
{
    QString name = ui->lineName->text();
    int score = *scorepointer;
    //highscore(name, score);
}
