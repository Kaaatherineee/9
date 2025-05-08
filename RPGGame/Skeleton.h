#pragma once
#include "Monster.h"

class Character;

class Skeleton : public Monster {
public:
    Skeleton();
    void attackEnemy(Character& enemy) override;
};