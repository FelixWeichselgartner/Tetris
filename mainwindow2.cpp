#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include "output_playing_field.h"
#include <QThread>



MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    tetris = Tetris(1);
    t1 = QThread::create([this](){ tetris.run();});
    t1->start();
    ui->setupUi(this);
    ui->groupBox->hide();
}

MainWindow2::~MainWindow2()
{
    tetris.quit.set();
    t1->quit();
    t1->wait();
    delete ui;
    delete eingabe;
}

void MainWindow2::on_pshExit_clicked()
{
    close();
}

void MainWindow2::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    OutputModeSelection(&painter, this->tetris.spawn_number.get(), &this->tetris.field, 'm');
    this->update();

    score=tetris.score.get();
    ui->lblscore->setNum(score);

    if(tetris.quit.is_set()){
        //eingabe = new Nameeingabe(&score, this); //, &score
        //eingabe -> showFullScreen();
        ui->groupBox->show();
    }
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
        ui->pshPause->setText("Play");
    }
    else if(pause==1){
        tetris.pause.clear();
        pause=0;
        ui->pshPause->setText("Pause");
    }
}

void highscore(QString name, int score)
{
    char *str;
    QByteArray ba;
    ba=name.toLatin1();
    str=ba.data();

    FILE *fptr;
    fptr = fopen("Highscores.txt", "a+");

    if (fptr == nullptr)
    {
        return;
    }

    fprintf(fptr, "%s; %i;", str, score);
    fprintf(fptr, "\n");

    fclose(fptr);
}

void MainWindow2::on_pshOK_clicked()
{
    QString name = ui->lineEdit->text();
    highscore(name, score);
    close();
}
