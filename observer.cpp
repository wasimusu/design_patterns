#include <bits/stdc++.h>

using namespace std;

class subscriber {
public:
    subscriber() = default;

    virtual void update() = 0;
};

class publisher {
private:
    set<subscriber *> subscribers;
    std::size_t size;

public:
    publisher() : size(0) {
    };

    void notify() {
        for (auto *ptr: subscribers) {
            ptr->update();
        }
    }

    void subscribe(subscriber *other) {
        if (!subscribers.count(other)) {
            subscribers.insert(other);
            size += 1;
        }

    }

    void unsubscribe(subscriber *other) {
        if (subscribers.count(other)) {
            subscribers.erase(other);
            size -= 1;
        }
    }

    size_t get_subscriber() const {
        return size;
    }
};

class subscriber_ : public subscriber {
public:
    subscriber_() = default;

    void subscribe_publisher(publisher &other) {
        other.subscribe(this);
    }

    void unsubscribe_publisher(publisher &other) {
        other.unsubscribe(this);
    };

    void update() {
        cout << "Content update from the publisher" << endl;
    }

    ~subscriber_() = default;
};


int main() {
    subscriber_ s1, s2;
    publisher p1, p2, p3;
    s1.subscribe_publisher(p1);
    s1.subscribe_publisher(p3);
    s2.subscribe_publisher(p2);
    s2.subscribe_publisher(p3);
    cout << p1.get_subscriber() << "\t" << p2.get_subscriber() << "\t" << p3.get_subscriber() << endl;
    p3.notify();
    s2.unsubscribe_publisher(p3);
    cout << p1.get_subscriber() << "\t" << p2.get_subscriber() << "\t" << p3.get_subscriber() << endl;
    return 0;
}