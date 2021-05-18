#include <iostream>
#include <memory>

template <typename T>
class Resource {
   public:
    Resource() {
        m_data = new T{};
        std::cout << "Resource acquired" << std::endl;
    }
    Resource(const T &r) {
        m_data = new T{r};
        std::cout << "Resource acquired" << std::endl;
    }
    ~Resource() {
        delete m_data;
        std::cout << "Resource destroyed" << std::endl;
    }

    T &operator*() { return m_data; }
    T *operator->() { return *m_data; }

    friend std::ostream &operator<<(std::ostream &os, const Resource<T> &r) {
        os << "Resource: " << *r.m_data;
        return os;
    }

   private:
    T *m_data;
};

template <typename T>
void getResource(Resource<T> *r) {
    std::cout << *r << std::endl;
}

int main() {
    std::unique_ptr<Resource<int>> uniquePtr{std::make_unique<Resource<int>>(10)};
    std::unique_ptr<Resource<int>> p1{new Resource<int>(10)};  // using move semantic,
    std::unique_ptr<Resource<int>> p2{};                       // init to nullptr;
    // create an array of Resource with length 5
    std::unique_ptr<Resource<int>[]> arr { std::make_unique<Resource<int>[]>(5) };

    std::shared_ptr<Resource<int>> sharedPtr{std::make_shared<Resource<int>>(10)};
    std::shared_ptr<Resource<int>> shared2{sharedPtr};

    // how many shared pointer pointing to the same object
    std::cout << shared2.use_count() << std::endl;

    std::weak_ptr<Resource<int>> weakPtr{sharedPtr};         // weak pointer can only initiate with shared pointer or weak pointer
    std::shared_ptr<Resource<int>> shared3{weakPtr.lock()};  // lock() return a shared pointer

    std::cout << "p1 is: " << (static_cast<bool>(p1) ? "Not Null" : "Null") << std::endl;
    std::cout << "p2 is: " << (static_cast<bool>(p2) ? "Not Null" : "Null") << std::endl;

    // p2 = p1; unique_ptr has disabled copy semantic
    p2 = std::move(p1);  // move assignment
    getResource(p2.get());

    std::cout << "p1 is: " << (static_cast<bool>(p1) ? "Not Null" : "Null") << std::endl;
    std::cout << "p2 is: " << (static_cast<bool>(p2) ? "Not Null" : "Null") << std::endl;

    return 0;
}