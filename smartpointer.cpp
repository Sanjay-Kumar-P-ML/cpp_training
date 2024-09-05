#include <iostream>
#include <memory> // For std::shared_ptr
using namespace std;
class MyClass {
public:
    MyClass() { cout << "MyClass created" <<endl; }
    ~MyClass() { cout << "MyClass destroyed" << endl; }
    void greet() { cout << "Hello, world!" << endl; }
};

int main() {
    shared_ptr<MyClass> ptr1 =make_shared<MyClass>(); // Create and manage a MyClass object
    ptr1->greet();
    
    shared_ptr<MyClass> ptr2 = ptr1; // ptr2 shares ownership of the object
    cout << "Reference count: " << ptr1.use_count() <<endl; // Shows 2
    
    ptr2->greet();
    // When ptr1 and ptr2 go out of scope, the object is destroyed
    return 0;
}
