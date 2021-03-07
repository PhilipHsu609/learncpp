#include <cctype>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>
#include <string>

#include "Creature.h"
#include "Monster.h"
#include "Player.h"

bool attackMonster(Player &p, Monster &m) {
    m.reduceHealth(p.getDamage());
    std::cout << "You hit the " << m.getName()
              << " for " << p.getDamage() << " damage.\n";
    if (m.isDead()) {
        p.levelUp();
        p.addGold(m.getGold());
        std::cout << "You killed the " << m.getName() << ".\n";
        std::cout << "You found " << m.getGold() << " gold.\n";
        return true;
    }
    return false;
}

bool attackPlayer(Player &p, Monster &m) {
    p.reduceHealth(m.getDamage());
    std::cout << "The " << m.getName()
              << " hit you for " << m.getDamage() << " damage.\n";
    if (p.isDead()) {
        std::cout << "You died at level " << p.getLevel()
                  << " and with " << p.getGold() << " gold.\n";
        std::cout << "Too bad you can't take it with you!\n";
        return true;
    }
    return false;
}

void fightMonster(Player &p, Monster &m) {
    char choose;
    while (!p.isDead() && !m.isDead()) {
        do {
            std::cout << "(R)un or (F)ight: ";
            std::cin >> choose;
            choose = tolower(choose);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } while (choose != 'r' && choose != 'f');

        if (choose == 'r') {
            int chance{Creature::getRandomNumber(1, 2)};
            if (chance == 1) {
                std::cout << "You successfully fled\n";
                return;
            } else {
                std::cout << "You failed to flee\n";
                if (attackPlayer(p, m)) break;
                continue;
            }
        } else {
            if (attackMonster(p, m)) break;
            if (attackPlayer(p, m)) break;
        }
    }
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));  // set initial seed value to system clock
    std::rand();                                                // get rid of first result

    std::string playerName;
    std::cout << "Enter your name: ";
    std::getline(std::cin, playerName);
    Player p{playerName};

    while (!p.hasWon() && !p.isDead()) {
        Monster m{Monster::getRandomMonster()};
        std::cout << "You have encountered a " << m.getName() << " (" << m.getSymbol() << ").\n";
        fightMonster(p, m);
    }

    if (p.hasWon()) {
        std::cout << "You have reached level 20!\nYou win!\n";
    }

    return 0;
}