#include <iostream>
#include <string>

class Ball {
   public:
    // Ball() : m_color{"black"}, m_radius{10.0} {}
    // Ball(const std::string &color) : m_color{color}, m_radius{10.0} {}
    Ball(const double radius) : m_color{"black"}, m_radius{radius} {}
    Ball(const std::string &color = "black", const double radius = 10.0)
        : m_color{color}, m_radius{radius} {}
    void print() {
        std::cout << "color: " << m_color << ", radius: " << m_radius << std::endl;
    }

   private:
    std::string m_color{};
    double m_radius{};
};

int main() {
    Ball def{};
    def.print();

    Ball blue{"blue"};
    blue.print();

    Ball twenty{20.0};
    twenty.print();

    Ball blueTwenty{"blue", 20.0};
    blueTwenty.print();

    return 0;
}