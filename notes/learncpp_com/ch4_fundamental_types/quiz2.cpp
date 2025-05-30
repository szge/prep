#include <iostream>
#include <algorithm>

#define GRAV 9.81

double getTowerHeight()
{
    double tower_height;
    std::cout << "Enter the height of the tower in meters: ";
    std::cin >> tower_height;
    return tower_height;
}

double getCurrentHeight(const double starting_height, const double seconds)
{
    return std::max(starting_height - GRAV * seconds * seconds / 2, 0.0);
}

void printBallHeight(const int seconds, const double current_height)
{
    if (current_height > 0)
    {
        std::cout << "At " << seconds << " seconds, the ball is at height: " << current_height << " meters\n";
    } else
    {
        std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
    }
}

int main()
{
    const double tower_height { getTowerHeight() };
    int seconds = 0;
    while (true)
    {
        const double current_height = getCurrentHeight(tower_height, seconds);
        printBallHeight(seconds, current_height);
        if (current_height <= 0.0) break;
        seconds++;
    }

    return 0;
}