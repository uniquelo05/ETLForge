#include "database.hpp"
#include <iostream>

namespace etlforge {

Database::Database() : isConnected(false) {
    // Constructor implementation
}

Database::~Database() {
    if (isConnected) {
        disconnect();
    }
}

bool Database::connect(const std::string& connectionString) {
    std::cout << "Connecting to database with connection string: " << connectionString << std::endl;
    isConnected = true; // Simulate successful connection
    return isConnected;
}

void Database::disconnect() {
    if (isConnected) {
        std::cout << "Disconnecting from database." << std::endl;
        isConnected = false;
    }
}

} // namespace etlforge