#include <iostream>
#include <cstdlib>

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

void cleanup() // must have no params or return value
{
    std::cout << "cleanup\n";
}

unsigned int LCG16() // rng
{
    static unsigned int s_state { 0 };
    s_state = 8253729 * s_state + 2396403;
    return s_state % 32768;
}

int main ()
{
    printCharCodes();
    invertedNestedLoops();
    rightAlignedLoops();
    fizzbuzz(15);
    fizzbuzzpop(150);

    // generate 100 "random" nums
    for (int count{ 1 }; count <= 100; ++count)
    {
        std::cout << LCG16() << '\t';

        // If we've printed 10 numbers, start a new row
        if (count % 10 == 0)
            std::cout << '\n';
    }

    std::atexit(cleanup);
    std::exit(0); // early termination with status code 0
    // anything after never gets executed

    return 0;
}