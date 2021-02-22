#include <iostream>

void print(const char *str) {
    while (*str != '\0') {
        std::cout << *str;
        str++;
    }
    std::cout << std::endl;
}

int main() {
    print("Hello World");
    return 0;
}