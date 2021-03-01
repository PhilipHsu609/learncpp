#ifndef MONSTER_H
#define MONSTER_H

#include <array>
#include <string>

class Monster {
   public:
    enum class Type {
        Dragon,
        Goblin,
        Ogre,
        Orc,
        Skeleton,
        Troll,
        Vampire,
        Zombin,

        Max_monster_types
    };
    Monster(Type type, const std::string &name, const std::string &roar, int points)
        : m_type{type}, m_name{name}, m_roar{roar}, m_hitPoints{points} {}
    static std::string getTypeString(Type type);
    void print() const;

   private:
    Type m_type{};
    std::string m_name{};
    std::string m_roar{};
    int m_hitPoints{};
};

class MonsterGenerator {
   public:
    static Monster generateMonster();
    static int getRand(int min, int max);
};

constexpr int max_monster_types = static_cast<std::size_t>(Monster::Type::Max_monster_types);
using array_type = std::array<std::string, max_monster_types>;

#endif