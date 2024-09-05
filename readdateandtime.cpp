#include <iostream>
#include <cstdlib>  // for system()
using namespace std;
int main() {
    string command = "sudo date";
    cout << "This is the date and time" <<endl;
    system(command.c_str());
    return 0;
}
