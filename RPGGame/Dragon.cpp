#include "Dragon.h"
#include "Character.h"
#include <iostream>

Dragon::Dragon() {
    name = "Dragon";
    health = 30;
    attack = 8;
    defense = 3;
}

void Dragon::attackEnemy(Character& enemy) {
    int damage = attack - enemy.getDefense();
    if (damage > 0) {
        enemy.heal(-damage);
        std::cout << name << " attacks " << enemy.getName() << " for " << damage << " damage!" << std::endl;
    }
    else {
        std::cout << name << " attacks " << enemy.getName() << ", but it has no effect!" << std::endl;
    }
}