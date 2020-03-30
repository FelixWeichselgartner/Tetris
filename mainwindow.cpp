#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QThread"
#include "Tetris.hpp"

Tetris t;

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
}



void MainWindow::on_btnplay1_clicked()
{
    window2 = new MainWindow2(this);
    t = Tetris();
    QThread *t1 = QThread::create([]() {t.run();});
    t1->start();
    window2 -> show();
}

void MainWindow::on_btnplay2_clicked()
{
    window3 = new MainWindow3(this);
    window3 -> show();
}

void MainWindow::on_btnscores_clicked()
{

}

void MainWindow::on_btnexit_clicked()
{
    close();
}
