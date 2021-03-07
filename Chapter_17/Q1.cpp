#include <iostream>
#include <string>

class Fruit {
   public:
    Fruit() = delete;
    Fruit(const std::string &name, const std::string &color) : m_name{name}, m_color{color} {}
    const std::string &getName() const { return m_name; }
    const std::string &getColor() const { return m_color; }

   private:
    std::string m_name{};
    std::string m_color{};
};

class Apple : public Fruit {
   public:
    Apple(const std::string &color) : Apple{"apple", color} {}
    Apple(const std::string &name, const std::string &color) : Fruit{name, color} {}
    friend std::ostream &operator<<(std::ostream &os, const Apple &a) {
        os << "Apple(" << a.getName() << ", " << a.getColor() << ")";
        return os;
    }
};

class Banana : public Fruit {
   public:
    Banana() : Banana{"banana", "yellow"} {}
    Banana(const std::string &name, const std::string &color)
        : Fruit{name, color} {}
    friend std::ostream &operator<<(std::ostream &os, const Banana &b) {
        os << "Apple(" << b.getName() << ", " << b.getColor() << ")";
        return os;
    }
};

class GrannySmith : public Apple {
   public:
    GrannySmith() : Apple{"granny smith apple", "green"} {}
};

int main() {
    Apple a{"red"};
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;
}