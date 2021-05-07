#include <iomanip>
#include <iostream>

template <class T>
class Storage {
   public:
    Storage(T value) : m_value{value} {}

    void setValue(T value) {
        m_value = value;
    }

    T getValue() {
        return m_value;
    }

   private:
    T m_value;
};

// Function template specilization
// A specilized function of Storage(T value)
template <>
Storage<char*>::Storage(char* value) {
    int length{0};

    while (value[length] != '\0')
        length++;
    length++;

    m_value = new char[length];
    for (int i = 0; i < length; i++)
        m_value[i] = value[i];
}

// Class template specilization
// Specilized class Storage<bool>
template <>
class Storage<bool> {
   public:
    Storage() = default;
    Storage(bool value) : m_value{value} {}

    void set(bool value) { m_value = value ? true : false; }
    bool get() { return m_value; }

   private:
    bool m_value{};
};

int main() {
    char* str = new char[10];

    for (int i = 0; i < 9; i++) str[i] = i + '0';
    str[9] = '\0';

    Storage<char*> charPtrStorage{str};
    delete[] str;

    std::cout << charPtrStorage.getValue() << std::endl;

    Storage<bool> boolStorage{};
    boolStorage.set(false);
    std::cout << std::boolalpha << boolStorage.get() << std::endl;

    return 0;
}