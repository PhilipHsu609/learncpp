#include <iomanip>
#include <iostream>
#include <utility>

template <class T>
class Auto_ptr {
   public:
    Auto_ptr(T *ptr = nullptr) : m_ptr{ptr} {}

    // Move Semantics: transfer/move the ownership from one object to another rather than making a copy
    // copy ctor with deep copy
    Auto_ptr(const Auto_ptr &ptr) {
        m_ptr = new T;
        *m_ptr = *ptr.m_ptr;
    }
    // Move ctor
    Auto_ptr(Auto_ptr &&ptr) noexcept : m_ptr{ptr.m_ptr} {
        ptr.m_ptr = nullptr;
    }

    // copy assignment with deep copy
    Auto_ptr &operator=(const Auto_ptr &ptr) {
        if (&ptr == this) return *this;

        delete m_ptr;
        m_ptr = new T;
        *m_ptr = *ptr;

        return *this;
    }
    // Move assignment
    Auto_ptr &operator=(Auto_ptr &&ptr) {
        if (&ptr == this) return *this;

        delete m_ptr;
        m_ptr = ptr.m_ptr;
        ptr.m_ptr = nullptr;
        return *this;
    }

    T &operator*() { return m_ptr; }
    T *operator->() { return *m_ptr; }

    bool isNull() { return m_ptr == nullptr; }

   private:
    T *m_ptr;
};

template <class T>
void copySwap(T &a, T &b) {
    T tmp{a};  // invokes copy ctor
    a = b;     // invokes copy assignment
    b = tmp;   // invokes copy assignment
}

template <class T>
void moveSwap(T &a, T &b) {
    // std::move(x) will cast l-value 'x' to r-value
    T tmp{std::move(a)};  // invokes move ctor
    a = std::move(b);     // invokes move assignment
    b = std::move(tmp);   // invokes move assignment
}

template <class T>
void swapNoExcept(T &a, T &b) {
    /*
        std::move_if_noexcept()
        move_if_noexcept will return movable r-value if the object has a noexcept move ctor, otherwise work as l-value.
        Using move semantic when a 'strong exception guarantee' exists.
    */
    T tmp{std::move_if_noexcept(a)};
    a = std::move_if_noexcept(b);
    b = std::move_if_noexcept(tmp);
}

int main() {
    int *ptr = new int;
    *ptr = 5;
    Auto_ptr<int> p1{ptr};
    Auto_ptr<int> p2{p1};  // move ctor, transfer p1 to p2

    std::cout << std::boolalpha;
    std::cout << "p1 move to p2" << std::endl;
    std::cout << "Is p1 a nullptr? " << p1.isNull() << std::endl;
    std::cout << "Is p2 a nullptr? " << p2.isNull() << std::endl;

    Auto_ptr<int> p3 = p2;  // asign p2 to p3
    std::cout << "p2 move to p3" << std::endl;
    std::cout << "Is p2 a nullptr? " << p2.isNull() << std::endl;
    std::cout << "Is p3 a nullptr? " << p3.isNull() << std::endl;

    int x{1};
    const int &lref{x + 1};  // const l-value reference, can be initialized with r-value or l-value
    int &&rref{5};           // r-value reference, can only be initialized with r-value
    std::cout << rref << std::endl;

    return 0;
}