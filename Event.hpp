#pragma once
#include <QMutex>

class Event {

private:
    QMutex qmutex;
    bool flag = false;

public:

    Event() {

    }

    Event& operator = (const Event& obj) {
        return *this;
    }

    void set() {
        qmutex.lock();
        flag = true;
        qmutex.unlock();
    }

    void clear() {
        qmutex.lock();
        flag = false;
        qmutex.unlock();
    }

    bool is_set() {
        bool tmp;
        qmutex.lock();
        tmp = this->flag;
        qmutex.unlock();
        return tmp;
    }
};
