#include <iostream>

consteval auto CONSTEVAL(auto value)
{
    return value;
}

// returns the greater number if executing in a constant context and the lesser otherwise
constexpr int compare(int x, int y) // function is constexpr
{
    if (std::is_constant_evaluated())
        return (x > y ? x : y);
    else
        return (x < y ? x : y);
}

int main()
{
    std::cout << CONSTEVAL(compare(5, 6)) << '\n';       // will execute at compile-time

    return 0;
}