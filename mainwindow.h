#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "mainwindow2.h"
#include "mainwindow3.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_btnplay1_clicked();

    void on_btnplay2_clicked();

    void on_btnscores_clicked();

    void on_btnexit_clicked();

private:
    Ui::MainWindow *ui;
    MainWindow2 *window2;
    MainWindow3 *window3;
};

#endif // MAINWINDOW_H
