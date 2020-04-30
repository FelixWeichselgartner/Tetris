#ifndef HIGHSCOREAUSGABE_H
#define HIGHSCOREAUSGABE_H

#include <QMainWindow>

namespace Ui {
class Highscoreausgabe;
}

class Highscoreausgabe : public QMainWindow
{
    Q_OBJECT

public:
    explicit Highscoreausgabe(QWidget *parent = nullptr);
    ~Highscoreausgabe();

private:
    Ui::Highscoreausgabe *ui;
};

#endif // HIGHSCOREAUSGABE_H
