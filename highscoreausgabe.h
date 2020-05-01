#ifndef HIGHSCOREAUSGABE_H
#define HIGHSCOREAUSGABE_H

#include <QMainWindow>
#include <QTableWidget>

namespace Ui {
class Highscoreausgabe;
}

class Highscoreausgabe : public QMainWindow
{
    Q_OBJECT

public:
    explicit Highscoreausgabe(QWidget *parent = nullptr);
    ~Highscoreausgabe();

private slots:

    void on_btnexit_clicked();

private:
    Ui::Highscoreausgabe *ui;
    QTableWidget* m_pTableWidget;
    QStringList m_TableHeader;
    void get_highscore();
    void set_Table();
};

#endif // HIGHSCOREAUSGABE_H
