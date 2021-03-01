#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Monster.h"

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    Monster m{MonsterGenerator::generateMonster()};
    m.print();

    return 0;
}