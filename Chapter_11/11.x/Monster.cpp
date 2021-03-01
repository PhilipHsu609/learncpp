#include "Monster.h"

#include <iostream>

std::string Monster::getTypeString(Type type) {
    static array_type types{"dragon", "goblin", "ogre", "orc", "skeleton", "troll", "vampire", "zombie"};
    return types.at(static_cast<int>(type));
}
void Monster::print() const {
    std::cout << m_name << " the " << getTypeString(m_type)
              << " has " << m_hitPoints << " hit points and says " << m_roar << std::endl;
}

int MonsterGenerator::getRand(int min, int max) {
    static constexpr double fraction{1.0 / (RAND_MAX + 1.0)};
    return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

Monster MonsterGenerator::generateMonster() {
    static constexpr std::array<const char *, 6>
        s_names{"Blarg", "Moog", "Pksh", "Tyrn", "Mort", "Hans"};
    static constexpr std::array<const char *, 6>
        s_roars{"*ROAR*", "*peep*", "*squeal*", "*whine*", "*hum*", "*burp*"};

    int randMonsterType{getRand(0, max_monster_types - 1)};
    int randMonsterName{getRand(0, s_names.size() - 1)};
    int randMonsterRoar{getRand(0, s_roars.size() - 1)};
    int randHitPoints{getRand(1, 100)};

    return Monster{static_cast<Monster::Type>(randMonsterType),
                   s_names[static_cast<std::size_t>(randMonsterName)],
                   s_roars[static_cast<std::size_t>(randMonsterRoar)],
                   randHitPoints};
}