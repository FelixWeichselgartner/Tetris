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
    explicit Nameeingabe(QWidget *parent = nullptr);
    ~Nameeingabe();

private slots:
    void on_pshCancel_clicked();

private:
    Ui::Nameeingabe *ui;
};

#endif // NAMEEINGABE_H
