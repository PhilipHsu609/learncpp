#include <iostream>

class Base {
   public:
    int m_val;
    int getVal() { return m_val; }

   protected:
    int m_protect;
};

class Derived : public Base {
   public:
    Derived(int val) {
        m_val = val;
    }
    // m_protect was inherited as protected
    // but we change it to public
    using Base::m_protect;

    // mark this function as inaccessible
    int getVal() = delete;

   private:
    using Base::m_val;  // make public member private
};

int main() {
    Derived d{10};

    // d.getVal() we can't use it
    std::cout << static_cast<Base>(d).getVal();  // need cast to Base class

    return 0;
}