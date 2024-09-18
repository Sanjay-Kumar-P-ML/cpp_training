#include <iostream>
#include <memory> // For std::unique_ptr
using namespace std;
class MyClass {
public:
    MyClass() { cout << "MyClass created" <<endl; }
    ~MyClass() { cout << "MyClass destroyed" << endl; }
    void greet() { cout << "Hello, world!" << endl; }
};

int main() {
    unique_ptr<MyClass> ptr1 =make_unique<MyClass>(); // Create and manage a MyClass object
    ptr1->greet();
    
    unique_ptr<MyClass> ptr2 =move(ptr1); // Transfer ownership
    if (!ptr1) {
        cout << "ptr1 is now null" <<endl;
    }
    ptr2->greet();
    
    return 0;
}

