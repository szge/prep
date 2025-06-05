#include <iostream>

int getValue()
{
    std::cout << "Enter an integer: ";

    int x{};
    std::cin >> x;
    return x;
}

void printCalculation(int x, int y, int z)
{
    std::cout << x + (y * z);
}

int getNumber()
{
    std::cout << "Enter an integer: ";
    int num {};
    std::cin >> num;
    return num;
}

constexpr bool isEven(const int num)
{
    return !(num % 2);
}

int main()
{
    // the following line will run left->right or right->left depending on the compiler
    // printCalculation(getValue(), getValue(), getValue()); // this line is ambiguous

    const int input { getNumber() };

    if (isEven(input))
    {
        std::cout << input << " is even\n";
    } else
    {
        std::cout << input << " is odd\n";
    }

    return 0;
}