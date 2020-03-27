#include "mainwindow.h"
#include "Tetris.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Tetris game;
    game.run();

    return a.exec();
}
