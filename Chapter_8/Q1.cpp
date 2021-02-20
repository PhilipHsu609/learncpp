#include <string>
#include <iostream>

enum class Monster_t {
    Ogre,
    Dragon,
    Orc,
    Giant_spider,
    Slime
};

struct Monster {
    Monster_t type{};
    std::string name{};
    int health{};
};

std::string getMonsterType(const Monster &m) {
    switch(m.type) {
        case Monster_t::Ogre: return "Ogre";
        case Monster_t::Dragon: return "Dragon";
        case Monster_t::Orc: return "Orc";
        case Monster_t::Giant_spider: return "Giant Spider";
        case Monster_t::Slime: return "Slime";
        default: return "Unknown";
    }
}

void printMonster(const Monster &m) {
    std::string mType{getMonsterType(m)};

    std::cout << "This " << mType << " is named " << m.name << " and has " << m.health << " health." << std::endl;
}

int main() {
    Monster ogre{Monster_t::Ogre, "Torg", 145};
    Monster slime{Monster_t::Slime, "Blurp", 23};

    printMonster(ogre);
    printMonster(slime);

    return 0;
}