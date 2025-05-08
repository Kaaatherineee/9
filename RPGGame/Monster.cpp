#include "Monster.h"
#include "Character.h"
#include <iostream>

void Monster::takeDamage(int damage) {
    health -= damage;
    if (health <= 0) {
        std::cout << name << " has been defeated!" << std::endl;
    }
}

void Monster::displayInfo() const {
    std::cout << "Monster: " << name << ", HP: " << health
        << ", Attack: " << attack << ", Defense: " << defense << std::endl;
}