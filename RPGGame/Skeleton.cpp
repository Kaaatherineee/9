#include "Skeleton.h"
#include "Character.h"
#include <iostream>

Skeleton::Skeleton() {
    name = "Skeleton";
    health = 30;
    attack = 8;
    defense = 3;
}

void Skeleton::attackEnemy(Character& enemy) {
    int damage = attack - enemy.getDefense();
    if (damage > 0) {
        enemy.heal(-damage);
        std::cout << name << " attacks " << enemy.getName() << " for " << damage << " damage!" << std::endl;
    }
    else {
        std::cout << name << " attacks " << enemy.getName() << ", but it has no effect!" << std::endl;
    }
}