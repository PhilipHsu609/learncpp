#include <iostream>

template <class T>
const T &max(const T &a, const T &b) {
    return std::max(a, b);
}

// Template with non-type parameter
template <class T, int size>
class StaticArray {
   public:
    StaticArray() {
        for (size_t i{0}; i < size; i++) m_array[i] = 0;
    }

    T *getArray();

    T &operator[](int index) {
        return m_array[index];
    }

   private:
    T m_array[size];
};

// Member function defined outside the class need specify the template
template <class T, int size>
T *StaticArray<T, size>::getArray() {
    return m_array;
}

int main() {
    int x = max(3, 10);
    double y = max(1.0, 0.5);

    StaticArray<int, 5> array{};

    std::cout << x << std::endl;
    std::cout << y << std::endl;

    return 0;
}