#ifndef CREATURE_H
#define CREATURE_H

#include <cstdlib>
#include <string>

class Creature {
   public:
    Creature(const std::string &name, char symbol, int health, int damage, int gold)
        : m_name{name}, m_symbol{symbol}, m_health{health}, m_damage{damage}, m_gold{gold} {}

    void reduceHealth(int val) {
        m_health -= val;
    }
    bool isDead() {
        return m_health <= 0;
    }
    void addGold(int amt) {
        m_gold += amt;
    }

    const std::string &getName() const { return m_name; }
    char getSymbol() const { return m_symbol; }
    int getHealth() const { return m_health; }
    int getDamage() const { return m_damage; }
    int getGold() const { return m_gold; }

    static int getRandomNumber(int min, int max) {
        static constexpr double fraction{1.0 / (RAND_MAX + 1.0)};
        return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
    }

   protected:
    std::string m_name{};
    char m_symbol{};
    int m_health{};
    int m_damage{};
    int m_gold{};
};

#endif