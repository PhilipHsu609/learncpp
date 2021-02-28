#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>
#include <random>
#include <vector>

template <class T>
void printVec(std::vector<T> vec) {
    for (int i{0}; i < vec.size(); i++) {
        std::cout << vec.at(i) << ' ';
    }
    std::cout << std::endl;
}

int mersenneTwister(int min, int max) {
    std::mt19937 mersenne{static_cast<std::mt19937::result_type>(std::time(nullptr))};
    return std::uniform_int_distribution<>{min, max}(mersenne);
}

std::vector<int> generateList(int start, int num) {
    std::vector<int> list(num, 0);
    for (int i{0}; i < num; i++) {
        list.at(i) = start * start;
        start++;
    }
    return list;
}

int main() {
    int start{}, numToGen{};

    std::cout << "Start where? ";
    std::cin >> start;
    std::cout << "How many? ";
    std::cin >> numToGen;

    std::vector<int> list{generateList(start, numToGen)};
    // printVec<int>(list);

    int rand{mersenneTwister(2, 4)};
    std::cout << "I generated " << numToGen << " square numbers. Do you know what each number is after multiplying it by " << rand << "?\n";

    std::transform(list.begin(), list.end(), list.begin(), [rand](int n) {
        return n * rand;
    });
    // printVec<int>(list);

    while (true) {
        if (numToGen == 0) {
            std::cout << "Nice! You found all numbers, good job!\n";
            break;
        }

        int input{};
        std::cout << "> ";
        std::cin >> input;

        auto it{std::find(list.begin(), list.end(), input)};
        if (it != list.end()) {
            std::cout << "Nice! " << --numToGen << " number(s) left.\n";
            list.erase(it);
        } else {
            auto closest{std::min_element(list.begin(), list.end(), [input](int a, int b) -> bool {
                return std::abs(a - input) < std::abs(b - input);
            })};
            std::cout << input << " is wrong! Try " << *closest << " next time.\n";
            break;
        }
    }

    return 0;
}