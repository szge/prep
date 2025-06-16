#include <iostream>
#include <cassert>
#include <cmath>
#include "random.h"

namespace Config
{
    constexpr int pick_range_min { 1 };
    constexpr int pick_range_max { 100 };
    const int num_allowed_guesses { static_cast<int>(ceil(log2(pick_range_max - pick_range_min))) };
}

// clear extraneous input from the cin buffer
void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// returns true if extraction failed, otherwise false
bool clearFailedExtraction()
{
    if (!std::cin) // previous extraction failed
    {
        if (std::cin.eof())
        {
            std::exit(0);
        }

        std::cin.clear(); // put back into normal operation mode
        ignoreLine(); // remove bad input
        return true;
    }
    return false;
}

int getUserGuess(const int num_guesses)
{
    while (true)
    {
        std::cout << "Guess #" << num_guesses << ": ";
        int guess {};
        std::cin >> guess;

        if (clearFailedExtraction() || guess < Config::pick_range_min || guess > Config::pick_range_max)
        {
            std::cout << "Oops, that input is invalid. Please try again.\n";
            continue;
        }

        ignoreLine();
        return guess;
    }
}

void playGame()
{
    const int picked_num { Random::get(Config::pick_range_min, Config::pick_range_max) };
    assert(Config::pick_range_min <= Config::pick_range_max);
    std::cout << "Let's play a game. I'm thinking of a number between " << Config::pick_range_min << " and " << Config::pick_range_max << ". You have " << Config::num_allowed_guesses << " tries to guess what it is.\n";
    for (int num_guesses = 1; num_guesses <= Config::num_allowed_guesses; ++num_guesses)
    {
        const int guess = getUserGuess(num_guesses);
        if (guess < picked_num) std::cout << "Your guess is too low.\n";
        if (guess > picked_num) std::cout << "Your guess is too high.\n";
        if (guess == picked_num)
        {
            std::cout << "Correct! You win!\n";
            return;
        }
    }
    std::cout << "Sorry, you lose. The correct number was " << picked_num << ".\n";
}

bool playAgain()
{
    char response {};
    while (true)
    {
        std::cout << "Would you like to play again (y/n)? ";
        std::cin >> response;
        ignoreLine();
        switch (response)
        {
        case 'y': return true;
        case 'n': return false;
        default: ;
        }
    }
}

int main()
{
    do
    {
        playGame();
    } while (playAgain());
    std::cout << "Thank you for playing.";
    return 0;
}

