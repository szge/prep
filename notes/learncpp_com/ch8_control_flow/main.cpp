#include <iostream>

void printCharCodes()
{
    char l {'a'};

    while (l <= 'z')
    {
        std::cout << "letter: '" << l << "', char code: " << static_cast<int>(l) << "\n";
        ++l;
    }
}

void invertedNestedLoops()
{
    for (int outer { 5 }; outer >= 1; --outer)
    {
        for (int inner { outer }; inner >= 1; --inner)
        {
            std::cout << inner << " ";
        }
        std::cout << "\n";
    }
}

void rightAlignedLoops()
{
    for (int outer { 1 }; outer <= 5; ++outer)
    {
        for (int inner { 5 }; inner >= 1; --inner)
        {
            if (inner <= outer) std::cout << inner << " ";
            else std::cout << "  ";
        }
        std::cout << "\n";
    }
}

void fizzbuzz(const int num)
{
    for (int i {0}; i <= num; ++i)
    {
        if ((i % 3 == 0) && (i % 5 == 0))
        {
            std::cout << "fizzbuzz\n";
        } else if (i % 3 == 0)
        {
            std::cout << "fizz\n";
        } else if (i % 5 == 0)
        {
            std::cout << "buzz\n";
        } else
        {
            std::cout << i << "\n";
        }
    }
}

void fizzbuzzpop(const int num)
{
    for (int i {0}; i <= num; ++i)
    {
        if (i % 3 == 0) std::cout << "fizz";
        if (i % 5 == 0) std::cout << "buzz";
        if (i % 7 == 0) std::cout << "pop";
        if (!((i % 3 == 0) || (i % 5 == 0) || (i % 7 == 0))) std::cout << i;
        std::cout << "\n";
    }
}

int main ()
{
    printCharCodes();
    invertedNestedLoops();
    rightAlignedLoops();
    fizzbuzz(15);
    fizzbuzzpop(150);

    return 0;
}