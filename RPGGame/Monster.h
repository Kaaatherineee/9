#pragma once

#include <string>

class Character; 

class Monster {
protected:
    std::string name;
    int health;
    int attack;
    int defense;

public:
    virtual ~Monster() = default;
    virtual void attackEnemy(Character& enemy) = 0;
    virtual void takeDamage(int damage);
    virtual void displayInfo() const;
    virtual std::string getName() const { return name; }
    virtual int getDefense() const { return defense; }
    virtual bool isAlive() const { return health > 0; }
};