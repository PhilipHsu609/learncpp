#include <iostream>

namespace StudentNames {
    // note: not enum class
    enum StudentNames {
        Kenny,       // 0
        Kyle,        // 1
        Stan,        // 2
        Butters,     // 3
        Cartman,     // 4
        MaxStudents  // 5
    };
}

int main() {
    int testScores[StudentNames::MaxStudents]{};  // allocate 5 int

    testScores[StudentNames::Cartman] = 50;  // Cartman get 50 in the test
    return 0;
}