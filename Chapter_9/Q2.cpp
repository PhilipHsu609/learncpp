#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <string>
#include <vector>

struct Student {
    std::string firstName{};
    unsigned int score{};
};

int main() {
    int numOfStudents{};
    do {
        std::cin >> numOfStudents;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (numOfStudents <= 0);

    std::vector<Student> students(static_cast<std::vector<Student>::size_type>(numOfStudents));

    for (auto &student : students) {
        std::cin >> student.firstName >> student.score;
    }

    std::sort(std::begin(students), std::end(students), [](const Student &s1, const Student &s2) -> bool {
        return s1.score > s2.score;
    });

    for (const auto &student : students) {
        std::cout << student.firstName << " got a grade of " << student.score << std::endl;
    }

    return 0;
}