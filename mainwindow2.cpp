#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include "output_playing_field.h"
#include <QThread>

bool pause = 0;

MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    tetris = Tetris();
    t1 = QThread::create([this](){ tetris.run();});
    t1->start();
    ui->setupUi(this);
}

MainWindow2::~MainWindow2()
{
    tetris.quit.set();
    t1->quit();
    t1->wait();
    delete ui;
}

void MainWindow2::on_pshExit_clicked()
{
    close();
}

void MainWindow2::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    OutputModeSelection(&painter, this->tetris.spawn_number.get(), &this->tetris.field, 'm');
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

void MainWindow2::on_pshPause_clicked()
{
    if(pause==0){
        tetris.pause.set();
        pause=1;
    }
    else if(pause==1){
        tetris.pause.clear();
        pause=0;
    }
}
