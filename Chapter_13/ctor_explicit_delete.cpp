#include <cstring>
#include <iostream>

class Fraction {
   public:
    // delete keyword prevent this function from being used
    Fraction() = delete;
    // explicit keyword makes this constructor ineligible for implicit conversions
    explicit Fraction(double n) {
        std::cout << "1 arg ctor called\n";
    }
    Fraction(int n = 0, int d = 1) : m_numerator{n}, m_denominator{d} {
        std::cout << "2 args ctor called\n";
    }

    // copy constructor (compiler will generate one if you don't have it, and copy it memberwise)
    // called when pass by value, return by value...etc
    Fraction(const Fraction &f) : m_numerator{f.m_numerator}, m_denominator{f.m_denominator} {
        std::cout << "copy ctor called\n";
    }

   private:
    int m_numerator{0};
    int m_denominator{1};
};

class MyString {
   public:
    MyString(const char *source = "") {
        m_len = std::strlen(source) + 1;  // plus 1 for terminator
        m_data = new char[m_len];
        for (int i = 0; i < m_len; i++) {
            m_data[i] = source[i];
        }
        m_data[m_len - 1] = '\0';
    }
    ~MyString() { delete[] m_data; }

    // default copy ctor (shallow copy)
    // Problem: m_data from 2 objects are pointing to same memory space,
    //          if one of them has been deallocated, other will cause undefined behavior
    MyString(const MyString &s) : m_data{s.m_data}, m_len{s.m_len} {}

    // correct copy ctor
    MyString(const MyString &s) { deepCopy(s); }

    // Deep copy
    void deepCopy(const MyString &s) {
        // deallocate
        delete[] m_data;

        m_len = s.m_len;

        // deep copy if it isn't null
        if (s.m_data) {
            m_data = new char[m_len];
            for (int i = 0; i < m_len; i++) {
                m_data[i] = s.m_data[i];
            }
        } else
            m_data = nullptr;
    }

   private:
    char *m_data{};
    int m_len{};
};

int main() {
    Fraction f = static_cast<Fraction>(0.5);  // cuz Fraction(double n) is explicit
    Fraction g{5};                            // called 2 args ctor
    Fraction h{1, 2};                         // called 2 args ctor
    // Fraction k; compiler error , Fraction() is deleted
    return 0;
}