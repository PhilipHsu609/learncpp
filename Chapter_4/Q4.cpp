#include <iostream>
#include <limits>

#include "constants.h"

double getHeight() {
    double height{};
    do {
        std::cout << "Enter the height of the tower in meters: ";
        if (std::cin >> height)
            break;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (true);
    return height;
}

double drop(int second) {
    return constant::gravity * second * second / 2.0;
}

int main() {
    double height{getHeight()}, distanceFallen{drop(0)};
    int second{0};

    while (distanceFallen < height) {
        std::cout << "At " << second << " seconds, the ball is at height: "
                  << height - distanceFallen << " meters" << std::endl;
        distanceFallen = drop(++second);
    }

    std::cout << "At " << second << " seconds, the ball is on the ground." << std::endl;

    return 0;
}