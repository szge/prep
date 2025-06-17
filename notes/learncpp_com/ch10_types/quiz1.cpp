#include <iostream>

using Degrees = double;
using Radians = double;

namespace constants
{
    constexpr double pi { 3.14159 };
}

Radians convertToRadians(const Degrees degrees)
{
    return degrees * constants::pi / 180;
}

int main()
{
    std::cout << "Enter a number of degrees: ";
    Degrees degrees{};
    std::cin >> degrees;

    const Radians radians { convertToRadians(degrees) };
    std::cout << degrees << " degrees is " << radians << " radians.\n";

    return 0;
}