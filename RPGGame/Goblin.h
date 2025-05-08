#pragma once
#include "Monster.h"

class Character; 

class Goblin : public Monster {
public:
    Goblin();
    void attackEnemy(Character& enemy) override;
};