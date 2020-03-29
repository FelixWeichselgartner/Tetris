#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

#include <QMainWindow>
#include <QKeyEvent>

namespace Ui {
class MainWindow2;
}

class MainWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow2(QWidget *parent = nullptr);
    ~MainWindow2();

protected:
    void keyPressEvent(QKeyEvent *event) override
         {
             if(event->key() == Qt::Key_R)
             {
                 close();
             }
         }

private slots:

	void on_pshExit_clicked();


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow2 *ui;
};

#endif // MAINWINDOW2_H
