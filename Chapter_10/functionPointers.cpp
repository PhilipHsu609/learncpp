#include <iostream>

int foo() {
    return 5;
}

double goo(int x) {
    return static_cast<double>(x);
}

// sort function with three arguments
// int array and the size of array
// A function cmpfnc which takes two int as arguments and return bool
void sort(int *arr, int size, bool (*cmpfnc)(int, int));

// with 'using', we can simplifiy function pointer
using Cmp = bool (*)(int, int);
void sort(int *arr, int size, Cmp cmpfnc);

// Alternate method
#include <functional>
void sort(int *arr, int size, std::function<bool(int, int)> cmpfnc);

int main() {
    // function pointer (print 1)
    std::cout << foo << std::endl;
    // interpret foo to void pointer
    std::cout << reinterpret_cast<void *>(foo) << std::endl;

    // fncptr is a function pointer return int with no argument
    // pointing to function foo
    int (*fncptr)(){&foo};
    fncptr();     // call function foo() through fncptr
    (*fncptr)();  // same as above

    // fncptr2 is a function pointer return double with one int argument
    // pointing to function goo
    double (*fncptr2)(int){&goo};

    std::function<double(int)> fncptr3{&goo};

    return 0;
}