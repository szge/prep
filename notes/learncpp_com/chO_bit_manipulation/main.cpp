#include <bitset>
#include <iostream>

// rotate left
std::bitset<4> rotl(const std::bitset<4> bits)
{
    return (bits << 1) | (bits >> 3);
}

int main()
{
    [[maybe_unused]] constexpr int  isHungry   { 0 };
    [[maybe_unused]] constexpr int  isSad      { 1 };
    [[maybe_unused]] constexpr int  isMad      { 2 };
    [[maybe_unused]] constexpr int  isHappy    { 3 };
    [[maybe_unused]] constexpr int  isLaughing { 4 };
    [[maybe_unused]] constexpr int  isAsleep   { 5 };
    [[maybe_unused]] constexpr int  isDead     { 6 };
    [[maybe_unused]] constexpr int  isCrying   { 7 };

    std::bitset<8> me { 0b0000'0101 };
    me.set(isHappy); // set position 3 to 1
    me.flip(isLaughing); // flip bit 4
    me.reset(isLaughing); // set bit 4 to 0

    std::cout << me.size() << " bits are in the bitset\n";
    std::cout << me.count() << " bits are set to true\n";
    std::cout << std::boolalpha;
    std::cout << "All bits are true: " << me.all() << '\n';
    std::cout << "Some bits are true: " << me.any() << '\n';
    std::cout << "No bits are true: " << me.none() << '\n';

    std::cout << "All the bits: " << me << '\n';
    std::cout << "I am happy: " << me.test(3) << '\n';
    std::cout << "I am laughing: " << me.test(4) << '\n';

    unsigned int x { 0b0100 };
    x = x << 1;
    std::cout << std::bitset<4>{x} << '\n';

    std::bitset<4> bits1{ 0b0001 };
    std::cout << rotl(bits1) << '\n';

    std::bitset<4> bits2{ 0b1001 };
    std::cout << rotl(bits2) << '\n';


    // bit masks

    [[maybe_unused]] constexpr std::uint8_t mask0{ 0b0000'0001 }; // represents bit 0
    [[maybe_unused]] constexpr std::uint8_t mask1{ 0b0000'0010 }; // represents bit 1
    [[maybe_unused]] constexpr std::uint8_t mask2{ 0b0000'0100 }; // represents bit 2
    [[maybe_unused]] constexpr std::uint8_t mask3{ 0b0000'1000 }; // represents bit 3
    [[maybe_unused]] constexpr std::uint8_t mask4{ 0b0001'0000 }; // represents bit 4
    [[maybe_unused]] constexpr std::uint8_t mask5{ 0b0010'0000 }; // represents bit 5
    [[maybe_unused]] constexpr std::uint8_t mask6{ 0b0100'0000 }; // represents bit 6
    [[maybe_unused]] constexpr std::uint8_t mask7{ 0b1000'0000 }; // represents bit 7

    std::uint8_t flags{ 0b0000'0101 }; // 8 bits in size means room for 8 flags

    std::cout << "bit 0 is " << (static_cast<bool>(flags & mask0) ? "on\n" : "off\n");
    std::cout << "bit 1 is " << (static_cast<bool>(flags & mask1) ? "on\n" : "off\n");
    flags |= (mask1 | mask4 | mask5); // turn on bits 1, 4, 5
    std::cout << "bit 1 is " << (static_cast<bool>(flags & mask1) ? "on\n" : "off\n");
    std::cout << "bit 5 is " << (static_cast<bool>(flags & mask1) ? "on\n" : "off\n");
    flags &= ~(mask1 | mask4 | mask5); // turn off bits 1, 4, 5
    std::cout << "bit 1 is " << (static_cast<bool>(flags & mask1) ? "on\n" : "off\n");
    std::cout << "bit 5 is " << (static_cast<bool>(flags & mask1) ? "on\n" : "off\n");
    flags ^= (mask1 | mask4 | mask5); // flip bits 1, 4, 5
    std::cout << "bit 1 is " << (static_cast<bool>(flags & mask1) ? "on\n" : "off\n");
    std::cout << "bit 5 is " << (static_cast<bool>(flags & mask1) ? "on\n" : "off\n");


    [[maybe_unused]] constexpr std::uint8_t option_viewed{ 0x01 };
    [[maybe_unused]] constexpr std::uint8_t option_edited{ 0x02 };
    [[maybe_unused]] constexpr std::uint8_t option_favorited{ 0x04 };
    [[maybe_unused]] constexpr std::uint8_t option_shared{ 0x08 };
    [[maybe_unused]] constexpr std::uint8_t option_deleted{ 0x10 };

    std::uint8_t myArticleFlags{ option_favorited };

    // Place all lines of code for the following quiz here
    myArticleFlags |= option_viewed; // set article as viewed
    std::cout << "article deleted: " << static_cast<bool>(myArticleFlags & option_deleted) << '\n';
    myArticleFlags &= static_cast<std::uint8_t>(~option_favorited); // clear article as favorite
    std::cout << std::bitset<8>{ myArticleFlags } << '\n';

    constexpr std::uint32_t redBits{ 0xFF000000 };
    constexpr std::uint32_t greenBits{ 0x00FF0000 };
    constexpr std::uint32_t blueBits{ 0x0000FF00 };
    constexpr std::uint32_t alphaBits{ 0x000000FF };

    std::cout << "Enter a 32-bit RGBA color value in hexadecimal (e.g. FF7F3300): ";
    std::uint32_t pixel{};
    std::cin >> std::hex >> pixel; // std::hex allows us to read in a hex value

    // use Bitwise AND to isolate the pixels for our given color,
    // then right shift the value into the lower 8 bits
    const std::uint8_t red{ static_cast<std::uint8_t>((pixel & redBits) >> 24) };
    const std::uint8_t green{ static_cast<std::uint8_t>((pixel & greenBits) >> 16) };
    const std::uint8_t blue{ static_cast<std::uint8_t>((pixel & blueBits) >> 8) };
    const std::uint8_t alpha{ static_cast<std::uint8_t>(pixel & alphaBits) };

    std::cout << "Your color contains:\n";
    std::cout << std::hex; // print the following values in hex

    // reminder: std::uint8_t will likely print as a char
    // we static_cast to int to ensure it prints as an integer
    std::cout << static_cast<int>(red)   << " red\n";
    std::cout << static_cast<int>(green) << " green\n";
    std::cout << static_cast<int>(blue)  << " blue\n";
    std::cout << static_cast<int>(alpha) << " alpha\n";
    return 0;
}