#include<iostream>
using namespace std;
class MyClass {
private:
    int data;
public:
    MyClass(int d) : data(d) {}

    void setData(int d) { data = d; } // Non-const member function

    int getData() const { return data; } // Const member function
};

int main() {
	int l=10;
    const MyClass obj(10);
    cout << obj.getData() << endl; // OK: getData() is const

    // obj.setData(20); // Error: setData() is not const
    return 0;
}

