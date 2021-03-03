#include <cassert>
#include <iostream>

class Fraction {
   public:
    Fraction() = default;
    Fraction(int n = 0, int d = 1) : m_numerator{n}, m_denominator{d} { reduce(); }
    void print() const {
        std::cout << m_numerator << "/" << m_denominator << std::endl;
    }
    static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    void reduce() {
        if (m_numerator != 0 && m_denominator != 0) {
            int gcd{Fraction::gcd(m_numerator, m_denominator)};
            m_numerator /= gcd;
            m_denominator /= gcd;
        }
    }

   public:  // Operator overloading
    // friend function: ONLY when you need to access private members
    friend Fraction operator*(const Fraction &f1, const Fraction &f2) {
        return {f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator};
    }

    // member function: Fraction must be left-hand operand
    // Fraction * 10 -> OK
    // 10 * Fraction -> NOT OK, need non-member function
    Fraction operator*(int val) {
        return {m_numerator * val, m_denominator};
    }

    // output/input stream should use (friend) non-member function
    // You don't want to do this "f.operator<<(std::cout);" or "f.operator>>(std::cin);"
    friend std::ostream &operator<<(std::ostream &os, const Fraction &f) {
        os << f.m_numerator << "/" << f.m_denominator << std::endl;
        return os;
    }
    friend std::istream &operator>>(std::istream &is, const Fraction &f);

    // prefix and postfix increment
    Fraction &operator++() {  // prefix
        this->m_numerator += this->m_denominator;
        return *this;
    }
    Fraction operator++(int) {  // postfix
        Fraction temp{*this};
        ++(*this);  // using prefix increment
        return temp;
    }

    // subscript operator
    int &operator[](int idx) {  // for non-const object. can be used for assignment
        assert((idx == 0 || idx == 1) && "index must be 0 or 1");
        return (idx == 0) ? m_numerator : m_denominator;
    }
    const int &operator[](int idx) const {  // for const object. can only be used for access
        assert((idx == 0 || idx == 1) && "index must be 0 or 1");
        return (idx == 0) ? m_numerator : m_denominator;
    }

    // User-defined conversion
    operator double() const {  // Convert Fraction object to double
        return m_numerator / static_cast<double>(m_denominator);
    }

    // Assignment operator
    Fraction &operator=(const Fraction &f) {
        // need self assignment check when haing dynamic allocated members
        if (*this == f) return *this;

        m_numerator = f.m_numerator;
        m_denominator = f.m_denominator;

        return *this;
    }

   public:  // Getter and Setter
    int getNumberator() const { return m_numerator; }
    int getDenominator() const { return m_denominator; }

   private:
    int m_numerator{};
    int m_denominator{};
};

// non-friend, non-member function
// It's ok for non Fraction object on left-hand operand
// 10 * Fraction -> OK
// Fraction * 10 -> 1. use member function "Fraction operator*(int val)"
//               -> 2. use non-member function "Fraction operator*(const Fraction &f, int val)"
Fraction operator*(const int val, const Fraction &f2) {
    return {f2.getNumberator() * val, f2.getDenominator()};
}

int main() {
    Fraction f1{2, 5};

    std::cout << f1++;
    std::cout << f1[0] << '\n';
    std::cout << f1[1] << '\n';
    std::cout << static_cast<double>(f1) << '\n';

    return 0;
}