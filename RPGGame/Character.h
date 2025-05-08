#pragma once

#include <string>
#include <vector>
#include "Inventory.h"

class Monster; 

class Character {
private:
    std::string name;
    int health;
    int attack;
    int defense;
    int level;
    int experience;
    Inventory inventory;

public:
    Character(const std::string& n = "Hero", int h = 100, int a = 10, int d = 5);

    void attackEnemy(Monster& enemy);
    void heal(int amount);
    void gainExperience(int exp);
    void displayInfo() const;
    void addItemToInventory(const std::string& item);
    void showInventory() const;

    std::string getName() const { return name; }
    int getHealth() const { return health; }
    int getDefense() const { return defense; }

    bool isAlive() const { return health > 0; }

    friend class Game;
};
