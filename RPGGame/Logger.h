
#pragma once
#include <fstream>
#include <string>

template<typename T>
class Logger {
private:
    std::ofstream file;

public:
    Logger(const std::string& filename) {
        file.open(filename, std::ios::app);
    }

    void log(const T& message) {
        if (file.is_open()) {
            file << message << std::endl;
        }
    }

    ~Logger() {
        if (file.is_open()) {
            file.close();
        }
    }
};