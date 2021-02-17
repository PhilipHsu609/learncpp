#include <cstdint>
#include <iostream>

constexpr int legalAge{16};

int main() {
    std::cout << "How old are you?\n";

    // uint8_t will act like char
    // std::uint8_t age{};
    int age{};
    std::cin >> age;

    std::cout << "Allowed to drive a car in Texas [";

    if (age >= legalAge)
        std::cout << 'x';  // character should use single quotation marks
    else
        std::cout << ' ';

    std::cout << "]\n";

    return 0;
}