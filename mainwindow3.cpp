#include "mainwindow3.h"
#include "ui_mainwindow3.h"
#include "output_playing_field.h"
#include <QDebug>
#include <QThread>


MainWindow3::MainWindow3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow3)
{
    tetris1 = Tetris();
    t1 = QThread::create([this](){ tetris1.run();});
    tetris2 = Tetris();
    t2 = QThread::create([this](){ tetris2.run();});
    t1->start();
    t2->start();
    ui->setupUi(this);
}

MainWindow3::~MainWindow3()
{
    tetris1.quit.set();
    tetris2.quit.set();
    t1->quit();
    t2->quit();
    t1->wait();
    t2->wait();
    delete ui;
}

void MainWindow3::paintEvent(QPaintEvent *event) {
    qDebug() << "HelloWorld!" << endl;
    QPainter painter(this);
    draw_field(&painter, &this->tetris1.field);
    //draw_field(&painter, &this->tetris2.field);
    OutputNextWidget(&painter, 19);
    this->update();
}

void MainWindow3::on_pshExit_clicked()
{
    close();
}
