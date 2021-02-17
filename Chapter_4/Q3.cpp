#include <iostream>
#include <limits>

double readDouble() {
    double x{};
    do {
        std::cout << "Enter a double value: ";
        if (std::cin >> x)
            break;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (true);
    return x;
}

int main() {
    double x{readDouble()}, y{readDouble()}, result{};
    char c{};

    std::cout << "Enter one of the following: +, -, *, /: ";
    std::cin >> c;

    switch (c) {
        case '+':
            result = x + y;
            break;
        case '-':
            result = x - y;
            break;
        case '*':
            result = x * y;
            break;
        case '/':
            result = x / y;
            break;
        default:
            std::cout << "Wrong operation" << std::endl;
            exit(EXIT_SUCCESS);
    }
    std::cout << x << " " << c << " " << y
              << " is " << result << std::endl;
    return 0;
}