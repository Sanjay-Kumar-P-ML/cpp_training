#include <iostream>
using namespace std;

class Base {
public:
	Base(){cout<<"base"<<endl;}
    void show() 
    {
        cout << "Base class" << endl;
    }
};

class Derived1 :virtual public Base {
	public:Derived1(){cout<<"D1"<<endl;}
	       //void f(){cout<<"f1"<<endl;}
    // Derived1 inherits Base virtually
};

class Derived2 :virtual public Base {
	public: Derived2(){cout<<"d2"<<endl;}
	       //void f(){cout<<"f2"<<endl;}
    // Derived2 also inherits Base virtually
};

class Final : public Derived1, public Derived2 {
	public:    Final(){cout<<"final"<<endl;}// Final inherits from both Derived1 and Derived2
    // Only one instance of Base is present due to virtual inheritance
};

int main() {
    Final obj;
    obj.show(); // No ambiguity: Calls Base::show() from the single instance of Base
    return 0;
}

