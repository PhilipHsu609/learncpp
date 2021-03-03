#include <cmath>
#include <iomanip>
#include <iostream>

class FixedPoint2 {
   public:
    using decimal_t = std::int16_t;
    using fraction_t = std::int8_t;

   public:
    FixedPoint2(double n) {
        m_decimal = static_cast<int>(n);
        m_fraction = static_cast<int>(std::round((n - m_decimal) * 100));
        alignSign();
    }
    FixedPoint2(decimal_t d, fraction_t f) : m_decimal{d}, m_fraction{f} {
        alignSign();
    }
    void alignSign() {
        if (m_decimal > 0 && m_fraction < 0) m_decimal = -m_decimal;
        if (m_decimal < 0 && m_fraction > 0) m_fraction = -m_fraction;
    }

    operator double() const {
        return static_cast<double>(m_decimal) + m_fraction / 100.0;
    }
    bool operator==(const FixedPoint2 &p) const {
        return m_decimal == p.m_decimal && m_fraction == p.m_fraction;
    }

    friend FixedPoint2 operator+(const FixedPoint2 &x, const FixedPoint2 &y) {
        double sum{static_cast<double>(x) + static_cast<double>(y)};
        return FixedPoint2{sum};
    }
    friend FixedPoint2 &operator-(FixedPoint2 &p) {
        p.m_decimal = -p.m_decimal;
        p.m_fraction = -p.m_fraction;
        return p;
    }
    friend std::ostream &operator<<(std::ostream &os, const FixedPoint2 &p) {
        os << static_cast<double>(p);
        return os;
    }
    friend std::istream &operator>>(std::istream &is, FixedPoint2 &p) {
        double tmp{};
        is >> tmp;

        p = FixedPoint2{tmp};

        return is;
    }

   private:
    decimal_t m_decimal{0};
    fraction_t m_fraction{0};
};

void testAddition() {
    // h/t to reader Sharjeel Safdar for this function
    std::cout << std::boolalpha;
    std::cout << (FixedPoint2{0.75} + FixedPoint2{1.23} == FixedPoint2{1.98}) << '\n';     // both positive, no decimal overflow
    std::cout << (FixedPoint2{0.75} + FixedPoint2{1.50} == FixedPoint2{2.25}) << '\n';     // both positive, with decimal overflow
    std::cout << (FixedPoint2{-0.75} + FixedPoint2{-1.23} == FixedPoint2{-1.98}) << '\n';  // both negative, no decimal overflow
    std::cout << (FixedPoint2{-0.75} + FixedPoint2{-1.50} == FixedPoint2{-2.25}) << '\n';  // both negative, with decimal overflow
    std::cout << (FixedPoint2{0.75} + FixedPoint2{-1.23} == FixedPoint2{-0.48}) << '\n';   // second negative, no decimal overflow
    std::cout << (FixedPoint2{0.75} + FixedPoint2{-1.50} == FixedPoint2{-0.75}) << '\n';   // second negative, possible decimal overflow
    std::cout << (FixedPoint2{-0.75} + FixedPoint2{1.23} == FixedPoint2{0.48}) << '\n';    // first negative, no decimal overflow
    std::cout << (FixedPoint2{-0.75} + FixedPoint2{1.50} == FixedPoint2{0.75}) << '\n';    // first negative, possible decimal overflow
}

int main() {
    testAddition();

    FixedPoint2 a{-0.48};
    std::cout << a << '\n';

    std::cout << -a << '\n';

    std::cout << "Enter a number: ";  // enter 5.678
    std::cin >> a;

    std::cout << "You entered: " << a << '\n';

    return 0;
}