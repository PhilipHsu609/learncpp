#include <cstdio>
#include <iostream>

int main() {
    // cin is tied together with cout by default.
    // It will guarantees that the cout buffer will flushed before cin invokes.
    std::cin.tie(&std::cout);

    // Enable/Disable the synchronization between C and C++ standard streams.
    // Enable: Allows you to mix C and C++ style I/O, and get expected result.
    // Disable: C++ streams will have it own independent buffers
    std::ios_base::sync_with_stdio(false);

    // Now, without the synchronization, we can't guarantee the order of the output.
    std::cout << "First ";
    printf("Second");
    std::cout << "Third \n";

    // std::endl will immediate flush the buffer, same as calling std::flush
    std::cout << "Cout tied to the standard output" << std::endl;
    std::cout << "Cin tied to the standard input" << std::endl;
    std::cerr << "Cerr tied to the standard error with unbuffered output" << std::endl;
    std::clog << "Clog tied to the stanard error with buffered output" << std::endl;

    std::cout << std::showpos << 20 << std::endl;  // cout with manipulators
    std::cout << std::noshowpos << 10 << std::endl;
    std::cout.setf(std::ios::boolalpha | std::ios::hex);    // cout set flags
    std::cout.unsetf(std::ios::boolalpha | std::ios::hex);  // cout unset flags

    // In my computer, printf buffer will flushed after C++ stream buffer flushed.
    // "Second" will output at the last line of the terminal.

    return 0;
}