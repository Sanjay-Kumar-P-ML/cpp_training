#include <iostream>
#include <cstdlib>  // for system()

int main() {

    std::string command = "sudo date 090518142023.00";
    int result = system(command.c_str());
    if (result == 0) {
        std::cout << "Date and time updated successfully" << std::endl;
    } else {
        std::cerr << "Failed to update date and time." << std::endl;
    }

    return 0;
}
