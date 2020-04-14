#ifndef NAMEEINGABE_H
#define NAMEEINGABE_H

#include <QWidget>

namespace Ui {
class Nameeingabe;
}

class Nameeingabe : public QWidget
{
    Q_OBJECT

public:
    explicit Nameeingabe(QWidget *parent = nullptr); //, int *scorepointer
    ~Nameeingabe();

private slots:
    void on_pshCancel_clicked();

    void on_pshOK_clicked();



private:
    Ui::Nameeingabe *ui;
    int *scorepointer;
};

#endif // NAMEEINGABE_H
