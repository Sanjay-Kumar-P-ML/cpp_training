#include <iostream>
#include <vector>
#include <map>

// Template function to print the contents of a vector
template <typename T>
void printVector(const std::vector<T>& vec) {
    std::cout << "Vector contents: ";
    for (const T& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}
template <typename K, typename V>
void printMap(const std::map<K, V>& mp) {
    std::cout << "Map contents: " << std::endl;
    for (const auto& pair : mp) {
        std::cout << pair.first << " -> " << pair.second << std::endl;
    }
}
int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    printVector(numbers);
    std::map<std::string, int> nameToAge;
    nameToAge["sanjay"] = 30;
    nameToAge["sambath"] = 25;
    nameToAge["mathi"] = 28;
    printMap(nameToAge);

    return 0;
}

