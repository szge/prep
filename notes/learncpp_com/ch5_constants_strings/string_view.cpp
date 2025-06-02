#include <iostream>
#include <string>
#include <string_view>

int main()
{
    using namespace std::string_literals;
    std::string_view name { "Alex"s }; // "Alex"s creates a temporary std::string
    std::cout << name << '\n'; // undefined behavior

    std::string s { "Hello, world!" };
    std::string_view sv { s }; // sv is now viewing s

    s = "Hello, universe!";    // modifies s, which invalidates sv (s is still valid)
    std::cout << sv << '\n';   // undefined behavior

    sv = s;                    // revalidate sv: sv is now viewing s again
    std::cout << sv << '\n';   // prints "Hello, universe!"

    return 0;
}