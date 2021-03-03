#include <cstdint>
#include <iostream>

class Average {
   public:
    Average() : m_sum{0}, m_seen{0} {}

    Average &operator+=(int val) {
        m_sum += val;
        m_seen++;
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const Average &avg) {
        os << static_cast<double>(avg.m_sum) / avg.m_seen;
        return os;
    }

   private:
    std::int_least32_t m_sum{0};
    std::int_least8_t m_seen{0};
};
int main() {
    Average avg{};

    avg += 4;
    std::cout << avg << '\n';  // 4 / 1 = 4

    avg += 8;
    std::cout << avg << '\n';  // (4 + 8) / 2 = 6

    avg += 24;
    std::cout << avg << '\n';  // (4 + 8 + 24) / 3 = 12

    avg += -10;
    std::cout << avg << '\n';  // (4 + 8 + 24 - 10) / 4 = 6.5

    (avg += 6) += 10;          // 2 calls chained together
    std::cout << avg << '\n';  // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

    Average copy{avg};
    std::cout << copy << '\n';

    return 0;
}