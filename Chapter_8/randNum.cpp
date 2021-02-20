#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

// get random number in [min, max]
// std::rand() 15-bit integers
int getRandomNumber(int min, int max) {
    // use static constexpr for efficient, cause only calculate once
    static constexpr double fraction{1.0 / (RAND_MAX + 1.0)};

    return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

// Mersenne Twister Algorithm 32-bit integers
// std::mt19937_64 for 64-bit integer
int MersenneTwister(int min, int max) {
    // initialize mersenne twister
    std::mt19937 mersenne{static_cast<std::mt19937::result_type>(std::time(nullptr))};

    std::uniform_int_distribution<> die{min, max};

    return die(mersenne);
}

int main() {
    // set initial seed
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int num1 = getRandomNumber(1, 10); // better way
    int num2 = std::rand() % 10 + 1; // modulus tends to be biased in favor of low numbers

    return 0;
}