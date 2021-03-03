#include <functional>
#include <iostream>
#include <string>
#include <vector>

class Teacher {
   public:
    Teacher(const std::string &name) : m_name{name} {}
    const std::string &getName() const { return m_name; }

   private:
    std::string m_name{};
};

class Department {
   public:
    Department() = default;
    void add(const Teacher &t) {
        m_teacher.push_back(t);
    }
    friend std::ostream &operator<<(std::ostream &os, const Department &d) {
        os << "Department: ";
        for (const auto &teacher : d.m_teacher) {
            os << teacher.get().getName() << ' ';
        }
        os << std::endl;
        return os;
    }

   private:
    std::vector<std::reference_wrapper<const Teacher>> m_teacher{};
};

int main() {
    // Create a teacher outside the scope of the Department
    Teacher t1{"Bob"};
    Teacher t2{"Frank"};
    Teacher t3{"Beth"};

    {
        // Create a department and add some Teachers to it
        Department department{};  // create an empty Department

        department.add(t1);
        department.add(t2);
        department.add(t3);

        std::cout << department;

    }  // department goes out of scope here and is destroyed

    std::cout << t1.getName() << " still exists!\n";
    std::cout << t2.getName() << " still exists!\n";
    std::cout << t3.getName() << " still exists!\n";

    return 0;
}