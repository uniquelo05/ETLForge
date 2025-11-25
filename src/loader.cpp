#include "loader.hpp"
#include <fstream>
#include <iostream>

namespace etlforge {

Loader::Loader() {
    // Constructor implementation
}

Loader::~Loader() {
    // Destructor implementation
}

void Loader::loadToFile(const std::vector<std::string>& data, const std::string& filePath) {
    std::ofstream file(filePath);

    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filePath << std::endl;
        return;
    }

    for (const auto& line : data) {
        file << line << "\n";
    }

    file.close();
    std::cout << "Data successfully written to file: " << filePath << std::endl;
}

void Loader::loadToDatabase(const std::vector<std::string>& data, const std::string& connectionString) {
    // Placeholder for database loading logic
    std::cout << "Connecting to database with connection string: " << connectionString << std::endl;
    for (const auto& line : data) {
        std::cout << "Inserting data: " << line << std::endl;
    }
}

} // namespace etlforge