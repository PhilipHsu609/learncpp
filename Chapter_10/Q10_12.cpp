#include <iostream>

int factorial(int n) {
    if (n <= 2) return n;
    return n * factorial(n - 1);
}

int sumOfDigits(int n) {
    if (n / 10 == 0) return n;
    return (n % 10) + sumOfDigits(n / 10);
}

// notice: use unsigned int to handle negative signed int
void dec2bin(unsigned int n) {
    if (n > 1) dec2bin(n >> 1);
    std::cout << n % 2;
}

int main() {
    int x{};
    std::cin >> x;

    int (*f)(int){factorial};
    f = sumOfDigits;
    std::cout << f(x) << std::endl;

    dec2bin(static_cast<unsigned int>(x));
    std::cout << std::endl;

    return 0;
}