#include <array>
#include <iostream>
#include <iterator>
#include <numeric>

namespace Items {
    enum Items {
        HealthPotions,
        Torches,
        Arrows,
        MaxItems
    };
}

int countTotalItems(const std::array<int, 3> &player) {
    return std::accumulate(std::begin(player), std::end(player), 0);
}

int main() {
    std::array<int, Items::MaxItems> player{2, 5, 10};
    std::cout << "Player have " << countTotalItems(player) << " items.\n";
    std::cout << "Player have " << player[Items::Torches] << " torches.\n";
    return 0;
}