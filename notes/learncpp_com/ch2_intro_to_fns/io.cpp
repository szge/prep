#include "io.h"
#include <iostream>

int readNumber() {
    std::cout << "Enter a number: ";
    int num;
    std::cin >> num;
    return num;
}

void writeAnswer(const int num) {
    std::cout << "The answer is: " << num << "\n";
}