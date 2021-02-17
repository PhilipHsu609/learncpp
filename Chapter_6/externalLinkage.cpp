#include <iostream>

// functions have external linkage by default
void foo() {}

// external linkage by default
// use forward decalration to access this variable
// extern int a;
int a{10};

// external linkage global variables
extern int x{5};
extern const int y{100};
extern constexpr int z{1};

int main() {
    return 0;
}