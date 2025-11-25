#include "config.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>

namespace etlforge {

Config::Config() {
    // Constructor implementation
}

Config::~Config() {
    // Destructor implementation
}

bool Config::loadFromFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Failed to open config file: " << filePath << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        // Ignore comments and empty lines
        line = trim(line);
        if (line.empty() || line[0] == '#') {
            continue;
        }

        std::istringstream iss(line);
        std::string key, value;
        if (std::getline(iss, key, '=') && std::getline(iss, value)) {
            configData[trim(key)] = trim(value);
        }
    }

    file.close();
    return true;
}

std::string Config::getValue(const std::string& key) const {
    auto it = configData.find(key);
    if (it != configData.end()) {
        return it->second;
    }
    return "";
}

std::unordered_map<std::string, std::string> Config::getAllValues() const {
    return configData;
}

std::string Config::trim(const std::string& str) const {
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");

    if (start == std::string::npos || end == std::string::npos) {
        return "";
    }

    return str.substr(start, end - start + 1);
}

void Config::printConfig() const {
    for (const auto& [key, value] : configData) {
        std::cout << key << " = " << value << std::endl;
    }
}

bool Config::saveToFile(const std::string& filePath) const {
    std::ofstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Failed to open file for writing: " << filePath << std::endl;
        return false;
    }

    for (const auto& [key, value] : configData) {
        file << key << "=" << value << "\n";
    }

    file.close();
    return true;
}

} // namespace etlforge