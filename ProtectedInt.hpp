#pragma once

#include <QMutex>

class ProtectedInt {
private:
    int score = 0;
    QMutex qmutex;

public:
    ProtectedInt& operator = (const ProtectedInt& obj) {
        return *this;
    }
    int get() {
        int s;
        qmutex.lock();
        s = this->score;
        qmutex.unlock();
        return s;
    }
    void set(int s) {
        qmutex.lock();
        this->score = s;
        qmutex.unlock();
    }
    void inc() { this->set(this->get() + 1); }
    void dec() { this->set(this->get() - 1); }
};
