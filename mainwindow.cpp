#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int value = 100;
    QProgressBar progressBar;
    ui->progressBar->setValue(value);

}



MainWindow::~MainWindow()
{
    delete ui;
    delete window2;
    delete window3;
    delete ausgabe;
}



void MainWindow::on_btnplay1_clicked()
{
    window2 = new MainWindow2(this);
    window2 -> show();
}

void MainWindow::on_btnplay2_clicked()
{
    window3 = new MainWindow3(this);
    window3 -> show();
}

void MainWindow::on_btnscores_clicked()
{
    ausgabe = new Highscoreausgabe(this);
    ausgabe -> show();
}

void MainWindow::on_btnexit_clicked()
{
    close();
}
