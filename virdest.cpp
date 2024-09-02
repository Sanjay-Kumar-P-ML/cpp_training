#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Base Constructor" << endl;
    }

    // Virtual Destructor
    virtual ~Base() {
        cout << "Base Destructor" << endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        cout << "Derived Constructor" << endl;
    }

    ~Derived() override {
        cout << "Derived Destructor" << endl;
    }
};

int main() {
    Base* obj = new Derived();
    delete obj;  // Calls Derived's destructor, then Base's destructor

    return 0;
}

