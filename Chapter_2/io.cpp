#include <iostream>
#include <limits>

int readNumber() {
    int num{};
    do {
        std::cout << "Enter an integer: ";
        if (std::cin >> num)
            break;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (true);
    return num;
}

void writeNumber(int num) {
    std::cout << "Result: " << num << std::endl;
}