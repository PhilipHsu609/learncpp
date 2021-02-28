#include <iostream>
#include <tuple>

struct S {
    int m_x;
    double m_y;
};

// return multiple value using struct
S returnStruct() {
    S s{5, 2.3};
    return s;
}

// return multiple value using std::tuple(C++11) / std::pair
std::tuple<int, double> returnTuple() {
    return {5, 2.3};
}

// passing address by value
void setToNull(int *ptr) {
    ptr = nullptr;
}

// passing address by reference
void setToNullRef(int *&ptr) {
    ptr = nullptr;
}

void printValue(int x, int y = 10);    // forward declaration with default argument
void printValue(int x, int y) {        // default argument can only be declared in
    std::cout << x << y << std::endl;  // either the forward declaration or the function definition
}

int main() {
    int *ptr{new int{5}};

    setToNull(ptr);     // nothing change
    setToNullRef(ptr);  // set ptr to nullptr

    // using std::tie to get value from tuple
    int x;
    double y;
    std::tie(x, y) = returnTuple();

    // using std::get<index> to get value from tuple
    std::tuple<int, double> t{returnTuple()};
    x = std::get<0>(t);
    y = std::get<1>(t);

    return 0;
}