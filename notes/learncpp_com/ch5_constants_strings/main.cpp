#include <iostream>
#include <string>
#include <string_view>

#define MY_NAME "Jonathan"

constexpr int cmax(const int x, const int y)
{
    return (x > y) ? x : y;
}

void printSV(std::string_view sv)
{
    std::cout << sv << '\n';
}

int main()
{
    // named consts
    const double gravity { 9.81 }; // preferred usage of const
    int const sidesInSquare {4}; // "east const" style
    // gravity = 3;

    // const with object-like macros
    std::cout << "My name is " << MY_NAME << ".\n";

    // literals
    bool myNameIsJonathan {true}; // true is a boolean literal
    double d {3.5}; // 3.5 is a double literal
    "Hello world"; // this is a C-style string literal
    // by default, literals are integers, booleans, floats, chars, and C-style strings.
    // add u for unsigned int, l for long, ul for unsigned long, ll for long long, ull for unsigned long long, z, uz, f, l, s, sv
    unsigned int val = 5u;
    std::cout << 5 << '\n'; // int (default)
    std::cout << 5l << '\n'; // long
    std::cout << 5u << '\n'; // unsigned int
    std::cout << 5.0 << '\n'; // double (default)
    std::cout << 5.0f << '\n'; // float
    float f {5.0f}; // need the f to avoid warning
    double negative_pi {-3.14159};
    double proton_charge {1.6e-19};
    int x { 012 }; // prefix 0 for octal; 12 octal = 10 decimal
    int y {0xF}; // prefix 0x for hex
    int bin {0b1}; // from C++14, prefix 0b for binary literals

    constexpr int num { cmax(5, 6) };
    constexpr int num2 { cmax(4, 3) };

    std::string name { "Jonathan" };
    name = "John";

    // if we used the extraction >> operator, it would split on the whitespace between the first and last parts of the name
    // so, use std::getline from <string>
    std::cout << "Enter your full name: ";
    std::getline(std::cin >> std::ws, name);
    std::cout << "Enter your age: ";
    int age{};
    std::cin >> age;
    std::cout << "Your age + length of name is: " << age + std::ssize(name) << '\n';

    const std::string some_string { "some string" };
    int some_string_len {static_cast<int>(some_string.length())}; // use static_cast to bypass warning of conversion from size_t to int
    // you can use static_cast, or std::size() in C++20.

    using namespace std::string_literals; // get access to the 's' suffix; this using import is fine because it's unlikely to collide
    std::cout << "some string\n"s; // this makes it a std::string type literal, instead of a C-style string

    std::string_view sv {"Hello world"};
    printSV(sv);

    return 0;
}