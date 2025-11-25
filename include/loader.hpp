#ifndef ETLFORGE_LOADER_HPP
#define ETLFORGE_LOADER_HPP

#include <string>
#include <vector>

namespace etlforge {

class Loader {
public:
    // Constructor
    Loader();

    // Destructor
    ~Loader();

    // Method to load data to a file
    void loadToFile(const std::vector<std::string>& data, const std::string& filePath);

    // Method to load data to a database
    void loadToDatabase(const std::vector<std::string>& data, const std::string& connectionString);
};

} // namespace etlforge

#endif // ETLFORGE_LOADER_HPP