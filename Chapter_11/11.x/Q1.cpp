#include <cmath>
#include <iostream>

class Point2d {
   public:
    Point2d() = default;
    Point2d(double x, double y) : m_x{x}, m_y{y} {}
    void print() const {
        std::cout << "Point2d(" << m_x << ", " << m_y << ")\n";
    }
    double distanceTo(const Point2d &dest) {
        return std::sqrt(std::pow(m_x - dest.m_x, 2) + std::pow(m_y - dest.m_y, 2));
    }
    friend double distanceFrom(const Point2d &src, const Point2d &dest);

   private:
    double m_x{0.0}, m_y{0.0};
};

double distanceFrom(const Point2d &src, const Point2d &dest) {
    return std::sqrt(std::pow(src.m_x - dest.m_x, 2) + std::pow(src.m_y - dest.m_y, 2));
}

int main() {
    Point2d first{};
    Point2d second{3.0, 4.0};
    first.print();
    second.print();
    std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';
    std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';

    return 0;
}