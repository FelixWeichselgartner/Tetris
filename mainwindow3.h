#ifndef MAINWINDOW3_H
#define MAINWINDOW3_H

#include <QKeyEvent>
#include <QPainter>
#include <QMainWindow>
#include "Tetris.hpp"

namespace Ui {
class MainWindow3;
}

class MainWindow3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow3(QWidget *parent = nullptr);
    ~MainWindow3();

    virtual void paintEvent(QPaintEvent *event);

protected:
    void keyPressEvent(QKeyEvent *event) override
         {
             if (event->isAutoRepeat()) {
                return;
             }
             switch(event->key()) {
             case Qt::Key_A: tetris1.pressed_left.set(); break;
             case Qt::Key_D: tetris1.pressed_right.set(); break;
             case Qt::Key_S: tetris1.pressed_down.set(); break;
             case Qt::Key_Q: tetris1.pressed_rotate_left.set(); break;
             case Qt::Key_E: tetris1.pressed_rotate_right.set(); break;
             case Qt::Key_J: tetris2.pressed_left.set(); break;
             case Qt::Key_L: tetris2.pressed_right.set(); break;
             case Qt::Key_K: tetris2.pressed_down.set(); break;
             case Qt::Key_U: tetris2.pressed_rotate_left.set(); break;
             case Qt::Key_O: tetris2.pressed_rotate_right.set(); break;
             }
         }

    void keyReleaseEvent(QKeyEvent *event) override
    {
        if (event->isAutoRepeat()) {
           return;
        }
        switch(event->key()) {
        case Qt::Key_S: tetris1.pressed_down.clear(); break;
        case Qt::Key_K: tetris2.pressed_down.clear(); break;
        }
    }

private slots:
    void on_pshExit_clicked();

    void on_pshPause_clicked();

    void on_pshOK_clicked();

    void on_pshCancel_clicked();

private:
    Ui::MainWindow3 *ui;
    Tetris tetris1, tetris2;
    QThread *t1, *t2;

    int score1, score2;     //Variablen für den score der Spieler
    bool pause;             //Variable zur Abfrage der Pause
};

#endif // MAINWINDOW3_H
