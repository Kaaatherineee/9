#include "Inventory.h"
#include <iostream>

void Inventory::addItem(const std::string& item) {
    items.push_back(item);
    std::cout << "Added " << item << " to inventory." << std::endl;
}

void Inventory::removeItem(const std::string& item) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (*it == item) {
            items.erase(it);
            return;
        }
    }
}

void Inventory::display() const {
    std::cout << "Inventory:" << std::endl;
    for (const auto& item : items) {
        std::cout << "- " << item << std::endl;
    }
}