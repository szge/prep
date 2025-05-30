#include <iostream>

double getDouble()
{
    double num;
    std::cout << "Enter a double value: ";
    std::cin >> num;
    return num;
}

char getOperation()
{
    char op;
    std::cout << "Enter +, -, *, or /: ";
    std::cin >> op;
    return op;
}

double result(double num1, double num2, char operation)
{
    if (operation == '+') return num1 + num2;
    if (operation == '-') return num1 - num2;
    if (operation == '*') return num1 * num2;
    if (operation == '/') return num1 / num2;
    return 0;
}

int main ()
{
    const double num1 { getDouble() };
    const double num2 { getDouble() };
    const char operation { getOperation() };
    std::cout << num1 << " " << operation << " " << num2 << " is " << result(num1, num2, operation);
    return 0;
}