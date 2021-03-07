#include <iostream>

class Base {
   private:
    int m_id;

   public:
    Base() : m_id{0} {
        std::cout << "Base: 0 arg ctor\n";
    }

    Base(int id = 0) : m_id{id} {
        std::cout << "Base: 1 arg ctor\n";
    }

    int getId() const { return m_id; }
};

class Derived : public Base {
   private:
    double m_cost;

   public:
    // We can choose which ctor that Base class used
    Derived(double cost = 0.0, int id = 0) : Base{id}, m_cost{cost} {
        std::cout << "Derived ctor\n";
    }

    double getCost() const { return m_cost; }
};

int main() {
    Derived d{3.2, 0};
    return 0;
}