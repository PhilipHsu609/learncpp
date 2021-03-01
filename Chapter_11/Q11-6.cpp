#include <cstdint>
#include <iostream>

class RGBA {
   private:
    using component_type = std::uint_fast8_t;
    component_type m_red{};
    component_type m_green{};
    component_type m_blue{};
    component_type m_alpha{};

   public:
    RGBA(component_type red = 0, component_type green = 0, component_type blue = 0, component_type alpha = 255)
        : m_red{red}, m_green{green}, m_blue{blue}, m_alpha{alpha} {}
    void print() {
        std::cout << " r=" << static_cast<int>(m_red)
                  << " g=" << static_cast<int>(m_green)
                  << " b=" << static_cast<int>(m_blue)
                  << " a=" << static_cast<int>(m_alpha) << std::endl;
    }
};

int main() {
    RGBA teal{0, 127, 127};
    teal.print();

    return 0;
}