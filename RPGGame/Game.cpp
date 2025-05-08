#include "Game.h"
#include "Goblin.h"
#include "Dragon.h"
#include "Skeleton.h"
#include <iostream>
#include <sstream>

Game::Game() : logger("game_log.txt") {}

void Game::start() {
    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;
    player = Character(name);
    player.displayInfo();
}

void Game::battle(std::unique_ptr<Monster> monster) {
    try {
        std::ostringstream oss;
        oss << "Battle started with " << monster->getName();
        logger.log(oss.str());

        while (player.isAlive() && monster->isAlive()) {
            player.attackEnemy(*monster);
            if (!monster->isAlive()) break;
            monster->attackEnemy(player);
        }

        if (player.isAlive()) {
            std::cout << "You won the battle!\n";
            player.gainExperience(50);
            player.addItemToInventory("Potion");
        }
        else {
            std::cout << "You were defeated...\n";
            throw std::runtime_error("Player died");
        }

    }
    catch (const std::exception& e) {
        std::cerr << "Error during battle: " << e.what() << std::endl;
    }
}

void Game::saveGame() {
    std::ofstream out("save.dat", std::ios::binary);
    if (!out) {
        std::cerr << "Failed to open save file.\n";
        return;
    }
    out.write(reinterpret_cast<const char*>(&player), sizeof(player));
    out.close();
    std::cout << "Game saved.\n";
}

void Game::loadGame() {
    std::ifstream in("save.dat", std::ios::binary);
    if (!in) {
        std::cerr << "No save file found.\n";
        return;
    }
    in.read(reinterpret_cast<char*>(&player), sizeof(player));
    in.close();
    std::cout << "Game loaded.\n";
    player.displayInfo();
}

void Game::run() {
    start();
    battle(std::make_unique<Goblin>());
    battle(std::make_unique<Skeleton>());
    battle(std::make_unique<Dragon>());
    saveGame();
}