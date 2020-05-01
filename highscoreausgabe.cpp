#include "highscoreausgabe.h"
#include "ui_highscoreausgabe.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QCoreApplication>
#include <QHeaderView>
#include <QMessageBox>
#include <QDebug>

#include <QFile>
#include <QTextStream>
#include <QStyleFactory>

Highscoreausgabe::Highscoreausgabe(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Highscoreausgabe)
{
    ui->setupUi(this);
    set_Table();
    get_highscore();

}

Highscoreausgabe::~Highscoreausgabe()
{
    delete ui;
}

void Highscoreausgabe::set_Table(){
    int i=0;
    m_TableHeader<<"Name"<<"Score";

    QFile file("Highscores.txt");
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(nullptr, "error", file.errorString());
    }
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        i++;
    }

    ui->tableWidget->setRowCount(i);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(m_TableHeader);
    ui->tableWidget->setColumnWidth(0, 150);
    ui->tableWidget->setColumnWidth(1, 150);
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section { background-color:black }");
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section { background-color:black }");


}

void Highscoreausgabe::get_highscore() {                        //Highscoreausgabe
    int x=0;
    QFile file("Highscores.txt");
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(nullptr, "error", file.errorString());
    }
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();

        QString name, score;
        bool before_seperation = true;

        for (int j = 0; j < line.length(); j++) {
            QChar c = line.at(j);

            if (before_seperation) {
                if (c == ':') {
                    before_seperation = false;
                    continue;
                }
                if (c != ' ') {
                    name.append(c);
                }
            } else {
                if (c != ' ' && c != ':') {
                    score.append(c);
                }
            }
        }

        ui->tableWidget->setItem(x, 0, new QTableWidgetItem(name));
        ui->tableWidget->setItem(x, 1, new QTableWidgetItem(score));
        x++;
    }
}

void Highscoreausgabe::on_btnexit_clicked()
{
    close();
}
