#include <iostream>

class Something {
   public:
    Something() : m_value{0} {}
    void resetValue() { m_value = 0; }
    void setValue(int value) { m_value = value; }
    int getValue() { return m_value; }
    int getValueConst() const { return m_value; }  // const member function: can't change member variables

    // Overloading member function
    const int overloadConstFunc() const { return m_value; }  // for const object
    int overloadConstFunc() { return m_value; }              // for non-const object

    int m_value;
};

int main() {
    const Something something{};  // const class object

    something.setValue(5);   // compiler error: disallowed modify the member variable
    something.m_value = 10;  // compiler error: disallowed modify the member variable

    std::cout << something.getValue() << std::endl;       // also get compiler error
    std::cout << something.getValueConst() << std::endl;  // const class object can only call const member function

    return 0;
}