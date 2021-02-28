#include <functional>
#include <iostream>

// use std::function when we don't know what will f be
void caller(const std::function<void()> &f) {
    f();
}

void invoke(const std::function<void()> &fn) {
    fn();
}

int main() {
    // store lambda in a variable
    // better way, use auto to init a lambda with variable
    auto isEven{[](int n) -> bool {
        return n % 2 == 0;
    }};
    // use std::function when we can't init the variable with lambda
    std::function<bool(int)> isOdd{[](int n) -> bool {
        return n % 2 == 1;
    }};
    bool (*equalZero)(int){[](int n) -> bool {
        return n == 0;
    }};

    /* --------------------------------------------------------------------------------------------------------- */

    int var{10};
    int bar{5};

    // when f1 is definition executed, each variables that lambda captured
    // will clone a copy inside the lambda
    // (lambda is a object called functor, each captured variable will become a data member of the object)
    auto f1{
        // captured variable 'var', clone a copy in f1
        [var]() -> void {
            // by default, var is captured by const value
            std::cout << var << std::endl;
        }};

    auto f2{
        // mutable keyword will removes the const from all variables
        [var]() mutable -> void {
            var += 5;  // can be modified, but still a copy of var
            std::cout << var << std::endl;
        }};

    auto f3{
        // captured var by reference
        // captured bar by const value
        [&var, bar]() -> void {
            var += 10;  // will affect the original var
            std::cout << var << std::endl;
        }};

    auto f4{
        // default capture '=', capture all used variables by value
        [=]() -> void {
            std::cout << bar + var << std::endl;
        }};

    auto f5{
        // default capture '&', capture all used variable by reference
        [&]() -> void {
            std::cout << bar - var << std::endl;
        }};

    /* --------------------------------------------------------------------------------------------------------- */

    int i{0};
    auto count{[i]() mutable -> void {
        std::cout << ++i << std::endl;
    }};

    count();  // 1

    auto copyCount{count};  // copy i from count to invoke, i is 1

    count();      // 2
    copyCount();  // 2, different i

    invoke(count);  // create a std::function object from lambda count

    invoke(std::ref(count));  // use count as reference

    return 0;
}