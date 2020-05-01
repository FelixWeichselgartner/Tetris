#include "mainwindow3.h"
#include "ui_mainwindow3.h"
#include "output_playing_field.h"
#include <QDebug>
#include <QThread>
#include "Highscore.hpp"


MainWindow3::MainWindow3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow3)
{
    tetris1 = Tetris(1);
    t1 = QThread::create([this](){ tetris1.run();});
    tetris2 = Tetris(2);
    t2 = QThread::create([this](){ tetris2.run();});
    t1->start();
    t2->start();
    ui->setupUi(this);
    ui->groupBox->hide();
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
    QPainter painter(this);
    OutputModeSelection(&painter, this->tetris1.spawn_number.get(), &this->tetris1.field, 'l');
    OutputModeSelection(&painter, this->tetris2.spawn_number.get(), &this->tetris2.field, 'r');
    this->update();

    int competive_score = 6;

    if ((tetris1.score.get() != 0) && (tetris1.score.get() % competive_score) == 0) {
        tetris1.score.set(tetris1.score.get() + 5);
        tetris2.insert_competitive_line();
    }
    score1 = tetris1.score.get();
    ui->lblscore1->setNum(score1);

    if ((tetris2.score.get() != 0) && (tetris2.score.get() % competive_score) == 0) {
        tetris2.score.set(tetris2.score.get() + competive_score);
        tetris1.insert_competitive_line();
    }
    score2 = tetris2.score.get();
    ui->lblscore2->setNum(score2);

    if(tetris1.quit.is_set()&&tetris2.quit.is_set()){
        ui->groupBox->show();
        if(score1>=score2){
            ui->lblname->setText("Player 1");
        } else{
            score1=score2;
            ui->lblname->setText("Player 2");
        }
    }
}

void MainWindow3::on_pshExit_clicked()
{
    close();
}

void MainWindow3::on_pshPause_clicked()
{
    if(pause == 0){
        tetris1.pause.set();
        tetris2.pause.set();
        pause = 1;
        ui->pshPause->setText("Play");
    }
    else if(pause == 1){
        tetris1.pause.clear();
        tetris2.pause.clear();
        pause = 0;
        ui->pshPause->setText("Pause");
    }
}

void MainWindow3::on_pshOK_clicked()
{
    QString name = ui->lineEdit->text();
    set_highscore(name, score1);
    close();
}

void MainWindow3::on_pshCancel_clicked()
{
    close();
}
