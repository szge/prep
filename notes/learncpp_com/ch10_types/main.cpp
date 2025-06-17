#include <iostream>
#include <cstring>
#include <typeinfo>
#include <cstdint>

// print int value 3 as if it's a float
void print_int_as_float()
{
    constexpr int n { 3 };
    float f {};
    std::memcpy(&f, &n, sizeof(float));
    std::cout << f << '\n';
}

void printInt(const int x)
{
    std::cout << x << '\n';
}

using PrintError = int;
PrintError printData();

auto test(auto x)
{
    return x;
}

int main()
{
    print_int_as_float();

    constexpr short s { 3 };
    printInt(s);
    printInt('a');
    printInt(true);

    // value-reserving (safe)
    constexpr int n = static_cast<int>(static_cast<long>(3)); // convert int 3 to long and back
    std::cout << n << '\n';                         // prints 3

    constexpr char c = static_cast<char>(static_cast<double>('c')); // convert 'c' to double and back
    std::cout << c << '\n';                               // prints 'c'

    // reinterpretive (unsafe)
    constexpr int u = static_cast<int>(static_cast<unsigned int>(-5)); // convert '-5' to unsigned and back
    std::cout << u << '\n'; // prints -5

    // lossy (unsafe)
    constexpr double d { static_cast<double>(static_cast<int>(3.5)) }; // convert double 3.5 to int and back
    std::cout << d << '\n'; // prints 3

    constexpr double d2 { static_cast<double>(static_cast<float>(1.23456789)) }; // convert double 1.23456789 to float and back
    std::cout << d2 << '\n'; // prints 1.23457

    // narrowing conversion, but the value is known to the compiler thru constexpr
    constexpr int n1 { 5 };
    unsigned int u1 { n1 };

    // arithmetic conversions
    int i { 2 };
    std::cout << typeid(i).name() << '\n'; // name of type for i

    double dd { 3.5 };
    std::cout << typeid(i).name() << '\n';

    std::cout << typeid(i + dd).name() << '\n';

    std::int8_t a {};

    std::cout << test("asdf") << '\n';

    return 0;
}