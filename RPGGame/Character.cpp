#include "Character.h"
#include "Monster.h"
#include <iostream>

Character::Character(const std::string& n, int h, int a, int d)
    : name(n), health(h), attack(a), defense(d), level(1), experience(0) {
}

void Character::attackEnemy(Monster& enemy) {
    int damage = attack - enemy.getDefense(); // Используем getter
    if (damage > 0) {
        enemy.takeDamage(damage);
        std::cout << name << " attacks " << enemy.getName() << " for " << damage << " damage!" << std::endl;
    }
    else {
        std::cout << name << " attacks " << enemy.getName() << ", but it has no effect!" << std::endl;
    }
}

void Character::heal(int amount) {
    health += amount;
    if (health > 100) health = 100;
    std::cout << name << " heals for " << amount << " HP!" << std::endl;
}

void Character::gainExperience(int exp) {
    experience += exp;
    while (experience >= 100 * level) {
        level++;
        experience -= 100 * level;
        std::cout << name << " leveled up to level " << level << "!" << std::endl;
        attack += 2;
        defense += 1;
        health += 10;
    }
}

void Character::displayInfo() const {
    std::cout << "Name: " << name << ", HP: " << health
        << ", Attack: " << attack << ", Defense: " << defense
        << ", Level: " << level << ", Experience: " << experience << std::endl;
}

void Character::addItemToInventory(const std::string& item) {
    inventory.addItem(item);
}

void Character::showInventory() const {
    inventory.display();
}