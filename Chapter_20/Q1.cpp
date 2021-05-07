#include <iostream>
#include <stdexcept>

class Fraction {
   public:
    Fraction(const int numerator = 0, const int denominator = 1) : m_numerator{numerator}, m_denomiator{denominator} {
        if (denominator == 0) throw std::runtime_error("Invalid denominator");
    }
    friend std::ostream &operator<<(std::ostream &os, const Fraction &f) {
        os << f.m_numerator << '/' << f.m_denomiator;
        return os;
    }

   private:
    int m_numerator{}, m_denomiator{};
};

int main() {
    int numerator, denominator;
    std::cout << "Enter the numerator: ";
    std::cin >> numerator;
    std::cout << "Enter the denominator: ";
    std::cin >> denominator;

    try {
        Fraction f{numerator, denominator};
        std::cout << f << std::endl;
    } catch (std::exception &exception) {
        std::cout << exception.what() << std::endl;
    }

    return 0;
}