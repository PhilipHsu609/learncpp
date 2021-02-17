#include <cassert>
#include <iostream>

int main() {
    // used for debug, not in production
    // evalute at run time
    assert(10 > 5 && "will be true, otherwise abort and show this message");

    // evalute at compile time
    static_assert(10 > 5, "error message");

    return 0;
}