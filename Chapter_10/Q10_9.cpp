#include <functional>
#include <iostream>
#include <limits>

// using ArithmeticFunction = int (*)(const int, const int);
using ArithmeticFunction = std::function<int(const int, const int)>;

int add(const int x, const int y) {
    return x + y;
}

int subtract(const int x, const int y) {
    return x - y;
}

int multiply(const int x, const int y) {
    return x * y;
}

int divide(const int x, const int y) {
    return x / y;
}

ArithmeticFunction getArithmeticFunction(const char op) {
    switch (op) {
        case '+':
            return add;
        case '-':
            return subtract;
        case '*':
            return multiply;
        case '/':
            return divide;
        default:
            return nullptr;
    }
}

int readInt() {
    int n{};
    do {
        std::cout << "Enter an integer: ";
        if (std::cin >> n)
            break;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (true);
    return n;
}

bool validOp(const char c) {
    switch (c) {
        case '+':
        case '-':
        case '*':
        case '/':
            return true;
        default:
            return false;
    }
}

char readOp() {
    char c{};
    do {
        std::cout << "Enter an operation: ";
        std::cin >> c;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (!validOp(c));
    return c;
}

int main() {
    int x{readInt()}, y{readInt()};
    char op{readOp()};

    ArithmeticFunction arith{getArithmeticFunction(op)};
    std::cout << x << op << y << std::endl;
    std::cout << "Result: " << arith(x, y) << std::endl;

    return 0;
}