#include <cstdlib>
#include <iostream>

void f1() {}

void f2() {}

int main() {
    // register function to execute after called std::exit
    std::atexit(f1);
    std::atexit(f2);  // the last one registered will be called first
    std::exit(0);

    // similar as above, but will not cleanup static objects
    // avoid cleanup other static objects accessed by other threads
    std::at_quick_exit(f1);
    std::quick_exit(0);

    // abnormal termination
    std::abort();
    std::terminate();
    return 0;
}