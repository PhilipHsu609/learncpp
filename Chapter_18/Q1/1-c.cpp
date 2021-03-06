#include <iostream>

class Base {
   protected:
    int m_value;

   public:
    Base(int value)
        : m_value{value} {
    }

    virtual const char* getName() { return "Base"; }
};

class Derived : public Base {
   public:
    Derived(int value)
        : Base{value} {
    }

    virtual const char* getName() override { return "Derived"; }
};

int main() {
    Derived d{5};
    // Base b{d}; assigned by value, cause object slicing
    Base& b{d};
    std::cout << b.getName() << '\n';

    return 0;
}