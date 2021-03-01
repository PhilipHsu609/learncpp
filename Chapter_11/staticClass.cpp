#include <array>
#include <iostream>

class Something {
   public:
    static int s_value;                                    // declares the static member variable
    static const int s_const_value{10};                    // static const can be declared and initialized directly
    static constexpr double s_double_value{2.3};           // ok
    static constexpr std::array<int, 3> s_array{1, 2, 3};  // ok
};
int Something::s_value{10};  // defines the static member variable (this is fine even though it's private)

/* ----------------------------------------------------------------------------------------------------------------------*/

class IDGenerator {
   private:
    static int s_nextID;  // declaration

   public:
    static int getNextID();  // declaration
};
int IDGenerator::s_nextID{1};   // definition
int IDGenerator::getNextID() {  // definition
    return s_nextID++;
}

/* ----------------------------------------------------------------------------------------------------------------------*/

int main() {
    Something::s_value = 5;
    std::cout << Something::s_value << std::endl;

    return 0;
}