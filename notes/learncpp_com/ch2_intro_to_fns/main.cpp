#include <iostream>
#include "add.h"

int getValueFromUser() {
    std::cout << "Enter an integer: ";
    int num{};
    std::cin >> num;
    return num;
}

// int add(int x, int y); // forward declaration
// int add (int, int); // forward declarations don't need to specify param names. but this is bad practice

int main() {
    // int num {getValueFromUser()};
    // std::cout << num << " doubled is " << num * 2 << std::endl;
    std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n';
    return 0;
}

// int add(int x, int y) {
//     return x + y;
// }