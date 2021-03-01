#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>

#include "Timer.h"

constexpr int g_arrayElements = 1e9;

int main() {
    std::array<int, g_arrayElements> *array{new std::array<int, g_arrayElements>{}};
    std::iota(array->rbegin(), array->rend(), 1);

    Timer t;
    std::sort(array->begin(), array->end());
    std::cout << "Time taken: " << t.elapsed() << " seconds\n";

    return 0;
}