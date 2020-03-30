#pragma once
#include <mutex>

class Event {

private:
    std::mutex l;
    bool flag = false;

public:

    void set() {
        std::lock_guard<std::mutex> lock(l);
        flag = true;
    }

    void clear() {
        std::lock_guard<std::mutex> lock(l);
        flag = false;
    }

    bool is_set() {
        std::lock_guard<std::mutex> lock(l);
        return this->flag;
    }
};
