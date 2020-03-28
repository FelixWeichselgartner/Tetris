#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QThread"


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
    window2 -> show();
}

void MainWindow::on_btnscores_clicked()
{
    close();
}