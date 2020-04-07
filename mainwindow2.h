#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QPainter>
#include "Tetris.hpp"

namespace Ui {
class MainWindow2;
}

class MainWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow2(QWidget *parent = nullptr);
    ~MainWindow2();

    virtual void paintEvent(QPaintEvent *event);

protected:
    void keyPressEvent(QKeyEvent *event) override
         {
             switch(event->key()) {
             case Qt::Key_A: tetris.pressed_left.set(); break;
             case Qt::Key_D: tetris.pressed_right.set(); break;
             case Qt::Key_S: tetris.pressed_down.set(); break;
             case Qt::Key_Q: tetris.pressed_rotate_left.set(); break;
             case Qt::Key_E: tetris.pressed_rotate_right.set(); break;
             }
         }

private slots:

	void on_pshExit_clicked();


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow2 *ui;
    Tetris tetris;
};

#endif // MAINWINDOW2_H
