#include <iostream>
using namespace std;

class Singleton {
private:
    int member;

    static Singleton* instance;


    Singleton() {
        cout << "Singleton instance created." << endl;
    }
public:
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    void showval() {
        cout<<"Member: "<<member<<endl;
    }

    void setval(int z){
        member = z;
    }
};

Singleton* Singleton::instance = nullptr;

int main() {
    Singleton* s = Singleton::getInstance();
    s->setval(10);
    s->showval();

    Singleton* s2 = Singleton::getInstance();
    s2->setval(20);
    s2->showval();
    s->showval();

    return 0;
}
