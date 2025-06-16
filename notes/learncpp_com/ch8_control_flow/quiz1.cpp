#include <iostream>

namespace Constants
{
    constexpr double gravity { 9.8 };
}

// Gets tower height from user and returns it
double getTowerHeight()
{
    std::cout << "Enter the height of the tower in meters: ";
    double towerHeight{};
    std::cin >> towerHeight;
    return towerHeight;
}

// Returns the current ball height after "seconds" seconds
double calculateBallHeight(const double towerHeight, const int seconds)
{
    // Using formula: s = (u * t) + (a * t^2) / 2
    // here u (initial velocity) = 0, so (u * t) = 0
    const double fallDistance { Constants::gravity * (seconds * seconds) / 2.0 };
    const double ballHeight { towerHeight - fallDistance };
    // If the ball would be under the ground, place it on the ground
    return std::max(ballHeight, 0.0);
}

// Prints ball height above ground
void printBallHeight(const double ballHeight, const int seconds)
{
    if (ballHeight > 0.0)
        std::cout << "At " << seconds << " seconds, the ball is at height: " << ballHeight << " meters\n";
    else
        std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
}

// Calculates the current ball height and then prints it
// This is a helper function to make it easier to do this
// returns the ball height
double calculateAndPrintBallHeight(const double towerHeight, const int seconds)
{
    const double ballHeight{ calculateBallHeight(towerHeight, seconds) };
    printBallHeight(ballHeight, seconds);
    return ballHeight;
}

int main()
{
    const double towerHeight{ getTowerHeight() };
    for (int seconds {0}; calculateAndPrintBallHeight(towerHeight, seconds) > 0.0; ++seconds){;}
    return 0;
}