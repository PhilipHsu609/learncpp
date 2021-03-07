#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

#include "Creature.h"

class Player : public Creature {
   public:
    Player(const std::string &name) : Creature{name, '@', 10, 1, 0} {}

    void printStatus() {
        std::cout << "You have " << m_health
                  << " health and are carrying " << m_gold << " gold.\n";
    }

    void levelUp() {
        m_level++;
        m_damage++;
    }
    bool hasWon() {
        return m_level == 20;
    }

    int getLevel() { return m_level; }

   private:
    int m_level{1};
};

#endif