#pragma once
#include <QMutex>
#include "Node.hpp"

#define xlength 10
#define ylength 26

class Field
{
private:
    QMutex qmutex;
    Node field[xlength][ylength];

public:

    Field& operator = (const Field& obj) {
        return *this;
    }

    Node get_copy(int pos_x, int pos_y) {
        Node tmp;
        qmutex.lock();
        tmp = field[pos_x][pos_y];
        qmutex.unlock();
        return tmp;
    }

    void set(Node node, int pos_x, int pos_y) {
        qmutex.lock();
        field[pos_x][pos_y] = node;
        qmutex.unlock();
    }
};
