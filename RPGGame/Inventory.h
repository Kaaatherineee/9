
#pragma once
#include <vector>
#include <string>

class Inventory {
private:
    std::vector<std::string> items;

public:
    void addItem(const std::string& item);
    void removeItem(const std::string& item);
    void display() const;
};