#pragma once
#include "Monster.h"

class Character;

class Dragon : public Monster {
public:
    Dragon();
    void attackEnemy(Character& enemy) override;
};