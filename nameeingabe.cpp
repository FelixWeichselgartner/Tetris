#include "nameeingabe.h"
#include "ui_nameeingabe.h"
#include "QString"

Nameeingabe::Nameeingabe(QWidget *parent) ://, int *scorepointer
    QWidget(parent),
    ui(new Ui::Nameeingabe)
{
    this->scorepointer=scorepointer;
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
void highscore(std::string name, int score)
{
    int fehler;
    FILE *fptr;
    fptr = fopen("Highscores.txt", "a+");
    if (fptr == nullptr)
    {
        printf("\nDie Datei konnte nicht geoeffnet werden!\n");
        return;
    }
    fflush(stdin);
    while (getchar() != '\n')
        ;
    //hier virtuelles enter
    //system("cls");
    //ausgabe();
    printf("Name fuer die Highscoreliste eingeben (max 10 Buchstaben): ");
    //scanf("%s", name);

   // fprintf(fptr, "%s; %i;", name, score);
    fprintf(fptr, "\n");

    fehler = fclose(fptr);
    if (fehler != 0)
    {
        printf("\nFehler %i beim Schließen der Datei!\n", fehler);
    }
}

void Nameeingabe::on_pshOK_clicked()
{
    QString name = ui->lineName->text();
    int score = *scorepointer;    //liefert den score
    //highscore(name, score);
}
