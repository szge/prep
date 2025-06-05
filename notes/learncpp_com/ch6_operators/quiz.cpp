#include <iostream>
#include <string_view>

std::string_view getQuantityPhrase(const int numApples)
{
    if (numApples < 0) return "negative";
    if (numApples == 0) return "no";
    if (numApples == 1) return "a single";
    if (numApples == 2) return "a couple of";
    if (numApples == 3) return "a few";
    return "many";
}

std::string_view getApplesPluralized(const int numApples)
{
    return (numApples == 1) ? "apple" : "apples";
}

int main()
{
    constexpr int maryApples {3};
    std::cout << "Mary has " << getQuantityPhrase(maryApples) << ' ' << getApplesPluralized(maryApples) << ".\n";

    std::cout << "How many apples do you have? ";
    int numApples{};
    std::cin >> numApples;
    std::cout << "You have " << getQuantityPhrase(numApples) << ' ' << getApplesPluralized(numApples) << ".\n";

    return 0;
}