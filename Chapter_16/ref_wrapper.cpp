#include <functional>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string tom{"Tom"};
    std::string berta{"Berta"};

    // std::vector<std::reference_wrapper<const std::string>> names{tom, berta};
    std::vector<std::reference_wrapper<std::string>> names{tom, berta};

    std::string jim{"Jim"};

    names.push_back(jim);

    for (auto name : names) {
        // Use the get() member function to get the referenced string.
        name.get() += " Beam";
    }

    std::cout << jim << '\n';  // Jim Beam

    return 0;
}