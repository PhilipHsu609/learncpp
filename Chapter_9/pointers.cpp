#include <iostream>

int main() {
    int *ptr{new int{10}};
    std::cout << "*ptr = " << *ptr << std::endl;
    delete ptr;
    ptr = nullptr;  // delete and set to nullptr

    int *ptr2{new (std::nothrow) int{}};  // will set to nullptr if allocation fails
    if (!ptr2)
        std::cout << "Allocate memory fail" << std::endl;
    else
        std::cout << "Allocate successful" << std::endl;

    return 0;
}