#include <iostream>
#include <limits>

int main() {
    int x{}, y{};

    do {
        std::cout << "Enter an integer: ";
        if (std::cin >> x)
            break;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (true);

    do {
        std::cout << "Enter another integer: ";
        if (std::cin >> y)
            break;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (true);

    std::cout << x << " + " << y << " is " << x + y << "." << std::endl;
    std::cout << x << " - " << y << " is " << x - y << "." << std::endl;

    return 0;
}