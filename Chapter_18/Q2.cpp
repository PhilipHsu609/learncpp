#include <iostream>
#include <vector>

class Point {
   private:
    int m_x{0};
    int m_y{0};
    int m_z{0};

   public:
    Point(int x, int y, int z)
        : m_x{x}, m_y{y}, m_z{z} {
    }

    friend std::ostream &operator<<(std::ostream &os, const Point &p) {
        os << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ')';
        return os;
    }
};

class Shape {
   public:
    virtual std::ostream &print(std::ostream &os) const = 0;
    friend std::ostream &operator<<(std::ostream &os, const Shape &shape) {
        return shape.print(os);
    }
    virtual ~Shape() = default;
};

class Triangle : public Shape {
   public:
    Triangle(Point p1, Point p2, Point p3) : m_p1{p1}, m_p2{p2}, m_p3{p3} {}
    virtual std::ostream &print(std::ostream &os) const override {
        os << "Triangle(" << m_p1 << ", " << m_p2 << ", " << m_p3 << ")";
        return os;
    }

   private:
    Point m_p1;
    Point m_p2;
    Point m_p3;
};

class Circle : public Shape {
   public:
    Circle(Point center, int radius) : m_center{center}, m_radius{radius} {}
    virtual std::ostream &print(std::ostream &os) const override {
        os << "Circle(" << m_center << ")";
        return os;
    }
    int getRadius() const {
        return m_radius;
    }

   private:
    Point m_center;
    int m_radius;
};

int getLargestRadius(std::vector<Shape *> v) {
    int radius{0};
    for (const auto *shape : v) {
        const Circle *c{dynamic_cast<const Circle *>(shape)};
        if (c)
            radius = std::max(radius, c->getRadius());
    }
    return radius;
}

int main() {
    std::vector<Shape *> v{
        new Circle{Point{1, 2, 3}, 7},
        new Triangle{Point{1, 2, 3}, Point{4, 5, 6}, Point{7, 8, 9}},
        new Circle{Point{4, 5, 6}, 3}};

    // print each shape in vector v on its own line here
    for (const auto &shape : v) {
        std::cout << *shape << std::endl;
    }

    std::cout << "The largest radius is: " << getLargestRadius(v) << '\n';  // write this function

    // delete each element in the vector here
    {
        int i{};
        const auto i2{&i};   // int* const (const pointer to non-const int)
        const auto *i3{&i};  // const int* (non-const pointer to const int)
    }
    for (const auto *shape : v) {
        delete shape;
    }

    return 0;
}