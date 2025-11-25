#ifndef ETLFORGE_EXTRACTOR_HPP
#define ETLFORGE_EXTRACTOR_HPP

#include <string>
#include <vector>

namespace etlforge {

class Extractor {
public:
    // Constructor
    Extractor();

    // Destructor
    ~Extractor();

    // Method to extract data from a file
    std::vector<std::string> extractFromFile(const std::string& filePath);

    // Method to extract data from a database
    std::vector<std::string> extractFromDatabase(const std::string& connectionString);
};

} // namespace etlforge

#endif // ETLFORGE_EXTRACTOR_HPP