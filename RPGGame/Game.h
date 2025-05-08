#pragma once

#include "Character.h"
#include "Monster.h"
#include <memory>
#include "Logger.h"

class Game {
private:
    Character player;
    Logger<std::string> logger;

public:
    Game();
    void start();
    void battle(std::unique_ptr<Monster> monster);
    void saveGame();
    void loadGame();

    void run();
};