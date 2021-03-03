#include <cassert>
#include <iostream>

class IntArray {
   public:
    IntArray(int len) {
        assert(len > 0);
        m_len = len;
        m_data = new int[m_len]{};
    }
    IntArray(const IntArray &arr) { deepCopy(arr); }
    ~IntArray() { delete[] m_data; }
    void deepCopy(const IntArray &arr) {
        delete[] m_data;

        m_len = arr.m_len;

        if (arr.m_data) {
            m_data = new int[m_len];
            for (int i = 0; i < m_len; i++) {
                m_data[i] = arr.m_data[i];
            }
        } else
            m_data = nullptr;
    }

    int &operator[](int idx) {
        assert(idx >= 0 && idx < m_len);
        return m_data[idx];
    }
    IntArray &operator=(const IntArray &arr) {
        if (this == &arr)
            return *this;
        deepCopy(arr);
        return *this;
    }
    friend std::ostream &operator<<(std::ostream &os, const IntArray &arr) {
        for (int i = 0; i < arr.m_len; i++) {
            os << arr.m_data[i] << ' ';
        }
        return os;
    }

   private:
    int *m_data{};
    int m_len{};
};

IntArray fillArray() {
    IntArray a(5);

    a[0] = 5;
    a[1] = 8;
    a[2] = 2;
    a[3] = 3;
    a[4] = 6;

    return a;
}

int main() {
    IntArray a{fillArray()};
    std::cout << a << '\n';

    auto &ref{a};  // we're using this reference to avoid compiler self-assignment errors
    a = ref;

    IntArray b(1);
    b = a;

    std::cout << b << '\n';

    return 0;
}