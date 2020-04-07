#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include "output_playing_field.h"
#include <QDebug>
#include <QThread>


MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    tetris = Tetris();
    QThread *t1 = QThread::create([this](){ tetris.run();});
    t1->start();
    ui->setupUi(this);
}

MainWindow2::~MainWindow2()
{
    delete ui;
}

void MainWindow2::on_pshExit_clicked()
{
    close();
}

void MainWindow2::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    draw_field(&painter, &this->tetris.field);
    this->update();
}

void MainWindow2::on_pushButton_clicked()
{
    showMaximized();
}

void MainWindow2::on_pushButton_2_clicked()
{
    showNormal();
}
