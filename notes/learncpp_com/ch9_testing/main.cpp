#include <iostream>

// returns true if std::cin has unextracted input on the current line, false otherwise
bool hasUnextractedInput()
{
    return !std::cin.eof() && std::cin.peek() != '\n';
}

// clear extraneous input from the cin buffer
void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// returns true if extraction failed, otherwise false
bool clearFailedExtraction()
{
    if (!std::cin) // previous extraction failed
    {
        if (std::cin.eof())
        {
            std::exit(0);
        }

        std::cin.clear(); // put back into normal operation mode
        ignoreLine(); // remove bad input
        return true;
    }
    return false;
}

double getDouble()
{
    while (true)
    {
        std::cout << "Enter a decimal number: ";
        double x {};
        std::cin >> x;

        if (clearFailedExtraction())
        {
            std::cout << "Oops, that input is invalid. Please try again.\n";
            continue;
        }

        ignoreLine();
        return x;
    }
}

char getOperator()
{
    while (true)
    {
        std::cout << "Enter one of the following: +, -, *, or /: ";
        char operation {};
        std::cin >> operation;

        if (!clearFailedExtraction()) ignoreLine();

        switch (operation)
        {
        case '+':
        case '-':
        case '*':
        case '/':
            return operation;
        default:
            std::cout << "Oops, that input is invalid. Please try again.\n";
        }
    }
}

void printResult(const double x, const char operation, const double y)
{
    std::cout << x << ' ' << operation << ' ' << y << " is ";
    switch (operation)
    {
    case '+':
        std::cout << x + y << '\n';
        return;
    case '-':
        std::cout << x - y << '\n';
        return;
    case '*':
        std::cout << x * y << '\n';
        return;
    case '/':
        if (y == 0.0) break;
        std::cout << x / y << '\n';
        return;
    }
    std::cout << "???"; // redundant case for robustness
}

int main()
{
    double x { getDouble() };
    char operation { getOperator() };
    double y { getDouble() };

    while (operation == '/' && y == 0.0)
    {
        std::cout << "The denominator can't be zero. Try again.\n";
        y = getDouble();
    }

    printResult(x, operation, y);

    return 0;
}