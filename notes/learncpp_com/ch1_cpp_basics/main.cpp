#include <iostream>

int main() {
    // int a, b; // you can define variables of the same type with comma separation
    int width {5}; // variable definition and initialization

    int a; // default-initialization (no initializer)
    // in many cases, this performs no initialization, and leaves the variable with an indeterminate ("garbage") value

    // traditional initialization:
    int b = 5; // copy-initialization; was less efficient for complex types until C++17.
    int c (5); // direct-initialization; introduced to initialize complex objects; also used in explicit type cast e.g. static_cast

    // modern initialization (preferred):
    int d {7}; // direct-list-initialization; unified syntax and consistent behavior; prevents narrowing conversions
    int e = {7}; // copy-list-initialization (rarely used)
    int f {}; // value-initialization

    // int g;
    // std::cout << g << std::endl; // this is undefined behavior
    //
    // int h, i;
    // std::cin >> h >> i;
    // std::cout << "You entered: " << h << " and " << i << std::endl;
    //
    // // if you enter "4 5" in the below example, it will assign 4 to `h` and 5 to `i`
    // std::cin >> h;
    // std::cin >> i;
    // std::cout << "You entered: " << h << " and " << i << std::endl;
    //
    // // if you enter a really large number: extraction will work but it will set the variable to the largest value it can hold
    // // a plus sign is value, just as a minus sign is. e.g. +5, -5
    //
    // int p, q, r;
    // std::cout << "Enter three numbers: ";
    // std::cin >> p >> q >> r;
    // std::cout << "You entered " << p << ", " << q << ", and " << r << "." << std::endl;

    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;
    std::cout << "Double your number: " << num * 2 << "\n";
    std::cout << "Triple your number: " << num * 3 << "\n";
    std::cout << "Enter another number: ";
    int num2 {};
    std::cin >> num2;
    std::cout << "The sum of your numbers is: " << num + num2 << std::endl;
    return 0;
}