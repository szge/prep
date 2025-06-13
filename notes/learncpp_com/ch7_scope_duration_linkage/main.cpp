#include <iostream>

void print()
{
    std::cout << " there\n";
}

namespace Foo
{
    int g_x {}; // g_x is in the Foo namespace but is still a global variable; can be used anywhere in the file

    int doSomething(int x, int y)
    {
        return x + y;
    }

    void print()
    {
        std::cout << "Hello";
    }

    void printHelloThere()
    {
        print();
        ::print(); // calls print() in the global namespace
    }
}

// you can declare nested namespaces this way since C++17
namespace Foo::Roo
{
    int add(int x, int y)
    {
        return x + y;
    }
}

namespace Goo
{
    int doSomething(int x, int y)
    {
        return x - y;
    }
}

int main()
{
    std::cout << Foo::doSomething(4, 3) << '\n';
    Foo::printHelloThere();

    int x {1};
    {
        int x{6};
    }

    std::cout << "Enter an integer: ";
    int smaller{};
    std::cin >> smaller;
    std::cout << "Enter a larger integer: ";
    int larger{};
    std::cin >> larger;
    if (larger < smaller)
    {
        std::cout << "Swapping the values\n";
        const int temp {larger};
        larger = smaller;
        smaller = temp;
    } // temp is destroyed here

    std::cout << "The smaller value is " << smaller << '\n';
    std::cout << "The larger value is " << larger << '\n';
    // std::swap(larger, smaller); // swap for future reference

    return 0;
}