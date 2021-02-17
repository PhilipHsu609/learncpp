#include <iostream>

bool passOrFail() {
    static int cnt{0};
    return cnt++ < 3;
}

int main() {
    std::cout << "User #1: " << (passOrFail() ? "Pass" : "Fail") << '\n';
    std::cout << "User #2: " << (passOrFail() ? "Pass" : "Fail") << '\n';
    std::cout << "User #3: " << (passOrFail() ? "Pass" : "Fail") << '\n';
    std::cout << "User #4: " << (passOrFail() ? "Pass" : "Fail") << '\n';
    std::cout << "User #5: " << (passOrFail() ? "Pass" : "Fail") << '\n';
    return 0;
}