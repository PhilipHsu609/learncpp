#include <array>
#include <cassert>
#include <iostream>

class Point3d {
   public:
    Point3d() = default;
    ~Point3d() = default;
    void setValues(int x, int y, int z) {
        m_x = x;
        m_y = y;
        m_z = z;
    }
    void print() {
        std::cout << "<" << m_x << ", " << m_y << ", " << m_z << ">\n";
    }
    bool isEqual(const Point3d &p) {
        return (m_x == p.m_x && m_y == p.m_y && m_z == p.m_z);
    }

   private:
    int m_x{}, m_y{}, m_z{};
};

class Stack {
   public:
    Stack() = default;
    ~Stack() = default;
    void reset() {
        size = 0;
    }
    bool push(int val) {
        if (size == s.size()) return false;
        s[size++] = val;
        return true;
    }
    int pop() {
        assert(size > 0 && "Stack is empty.");
        return s[--size];
    }
    void print() {
        std::cout << "( ";
        for (int i{0}; i < size; i++) {
            std::cout << s[i] << ' ';
        }
        std::cout << ")\n";
    }

   private:
    using container_type = std::array<int, 10>;
    using size_type = container_type::size_type;

   private:
    container_type s;
    size_type size{0};
};

int main() {
    Stack stack;
    stack.reset();

    stack.print();

    stack.push(5);
    stack.push(3);
    stack.push(8);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();

    stack.print();
    return 0;
}