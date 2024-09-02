#include <iostream>
using namespace std;

class Example {
private:
    static int count; // Static member variable

public:
    Example() {
        count++; // Increment the count for every object created
    }

    // Static member function
    static void showCount() {
        cout << "Number of objects created: " << count << endl;
    }
};
//int Example::count=0;
int main(){
	Example e;
	Example::showCount();
	Example e1;
	Example::showCount();
}
