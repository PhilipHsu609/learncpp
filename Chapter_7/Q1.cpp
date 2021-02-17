#include <iostream>

#include "constants.h"

double calculateHeight(double initialHeight, int seconds) {
    double distanceFallen = myConstants::gravity * seconds * seconds / 2;
    double heightNow = initialHeight - distanceFallen;

    // Check whether we've gone under the ground
    // If so, set the height to ground-level
    if (heightNow < 0.0)
        return 0.0;
    else
        return heightNow;
}

bool calculateAndPrintHeight(double initialHeight, int time) {
    double currentHeight = calculateHeight(initialHeight, time);
    std::cout << "At " << time << " seconds, the ball is at height: " << currentHeight << "\n";
    return currentHeight > 0;
}

int main() {
    using namespace std;
    cout << "Enter the initial height of the tower in meters: ";
    double initialHeight;
    cin >> initialHeight;

    int sec{0};
    while (calculateAndPrintHeight(initialHeight, sec++))
        ;

    return 0;
}