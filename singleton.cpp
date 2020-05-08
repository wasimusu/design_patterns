/**
 * A class demonstrating the concept of singleton class
 * */

#include <iostream>
#include <mutex>
#include <thread>
#include <bits/stdc++.h>

using namespace std;

class Singleton {
    static Singleton *instance;
    static mutex mutex_;
    int data_;

    // Private constructor so that no objects are created
    Singleton() : data_(0) {}

public:
    // Not copyable
    Singleton(const Singleton &other) = delete;

    // Not copy assignable
    Singleton operator=(Singleton &other) = delete;

    static Singleton *getInstance() {
        lock_guard<std::mutex> lock(mutex_);
        if (!instance) {
            instance = new Singleton;
        }
        return instance;
    }

    void setData(int data) {
        Singleton::data_ = data;
    }

    int getData() const {
        return data_;
    }

};

Singleton *Singleton::instance = nullptr;

int main() {
    Singleton *s = s->getInstance();
    s->setData(1);
    cout << s->getData() << endl;
    return 0;
}

