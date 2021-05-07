#include <iostream>
#include <string>
#include <utility>

template <class T1, class T2>
class Pair {
   public:
    Pair(const T1 &first, const T2 &second) : m_first{first}, m_second{second} {}
    explicit constexpr Pair(const T1 &&first, const T2 &&second) : m_first{first}, m_second{second} {}
    const T1 &first() { return m_first; }
    const T2 &second() { return m_second; }
    const T1 &first() const { return m_first; }
    const T2 &second() const { return m_second; }

   private:
    T1 m_first;
    T2 m_second;
};

template <class T>
class StringValuePair : public Pair<std::string, T> {
   public:
    StringValuePair(const std::string &str, const T &value) : Pair<std::string, T>(str, value) {}
};

int main() {
    Pair<int, double> mypair{3, 4.6};
    StringValuePair<int> p{"Hello", 5};
    // constexpr std::pair<int, int> p{3, 4};
    std::cout << p.first() << " " << p.second() << std::endl;
    return 0;
}