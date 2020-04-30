#ifndef HIGHSCORE_HPP
#define HIGHSCORE_HPP

void set_highscore(QString name, int score)
{
    char *str;
    QByteArray ba;
    ba=name.toLatin1();
    str=ba.data();

    FILE *fptr;
    fptr = fopen("Highscores.txt", "a+");

    if (fptr == nullptr)
    {
        return;
    }

    fprintf(fptr, "%s: %i \n", str, score);

    fclose(fptr);
}



#endif // HIGHSCORE_HPP
