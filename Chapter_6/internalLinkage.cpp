#include <iostream>

// internal global variables
static int x{10};  // x only visible in this cpp file
const int y;
constexpr int z{5};

// internal function
static int foo() {}

int main() {
    return 0;
}