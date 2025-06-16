#include <iostream>
#include <cstdlib>
#include <random>
#include "random.h"

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

void generate_lcg16(const int num = 10)
{
    // generate 100 "random" nums
    for (int count{ 1 }; count <= num; ++count)
    {
        std::cout << LCG16() << '\t';

        // If we've printed 10 numbers, start a new row
        if (count % 10 == 0) std::cout << '\n';
    }
}

void generate_mt19937(const int num = 40)
{
    std::mt19937 mt{};
    for (int count {1}; count <= num; ++count)
    {
        std::cout << mt() << '\t';
        if (count % 5 == 0) std::cout << '\n';
    }
}

void generate_die_rolls(const int num = 40)
{
    // generate a die roll from 1 to 6 using mt19937 and a uniform distribution
    std::random_device rd{};
    std::seed_seq ss { rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };
    std::mt19937 mt{ ss };
    std::uniform_int_distribution<> die6 { 1, 6 };
    std::cout << "random die rolls:\n";
    for (int count { 1 }; count <= num; ++count)
    {
        std::cout << die6(mt) << '\t';
        if (count % 10 == 0) std::cout << '\n';
    }
}

int main ()
{
    printCharCodes();
    invertedNestedLoops();
    rightAlignedLoops();
    fizzbuzz(15);
    fizzbuzzpop(150);

    generate_lcg16(10);
    // generate_mt19937(40);
    generate_die_rolls();

    // try our random header function with arguments with different return types
    std::cout << Random::get<std::size_t>(1, 6u) << '\n'; // returns std::size_t between 1 and 6

    // access Random::mt directly if we have our own distribution
    std::uniform_int_distribution<> die6 { 1, 6 };
    for (int count { 1 }; count <= 10; ++count)
    {
        std::cout << die6(Random::mt) << '\t';
    }
    std::cout << '\n';

    std::atexit(cleanup);
    std::exit(0); // early termination with status code 0
    // anything after never gets executed

    return 0;
}