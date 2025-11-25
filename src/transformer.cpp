#include "transformer.hpp"
#include <algorithm>
#include <iostream>
#include <sstream>

namespace etlforge {

Transformer::Transformer() {
    // Constructor implementation
}

Transformer::~Transformer() {
    // Destructor implementation
}

std::vector<std::string> Transformer::transformData(const std::vector<std::string>& data) {
    std::vector<std::string> transformedData;

    for (const auto& line : data) {
        std::string transformedLine = line;
        std::transform(transformedLine.begin(), transformedLine.end(), transformedLine.begin(), ::toupper);
        transformedData.push_back(transformedLine);
    }

    std::cout << "Data successfully transformed." << std::endl;
    return transformedData;
}

std::vector<std::string> Transformer::filterData(const std::vector<std::string>& data, const std::string& keyword) {
    std::vector<std::string> filteredData;

    for (const auto& line : data) {
        if (line.find(keyword) != std::string::npos) {
            filteredData.push_back(line);
        }
    }

    std::cout << "Data successfully filtered." << std::endl;
    return filteredData;
}

std::vector<std::string> Transformer::splitAndTransform(const std::vector<std::string>& data, char delimiter) {
    std::vector<std::string> transformedData;

    for (const auto& line : data) {
        std::istringstream ss(line);
        std::string token;
        while (std::getline(ss, token, delimiter)) {
            std::transform(token.begin(), token.end(), token.begin(), ::toupper);
            transformedData.push_back(token);
        }
    }

    std::cout << "Data successfully split and transformed." << std::endl;
    return transformedData;
}

void Transformer::printTransformedData(const std::vector<std::string>& data) const {
    std::cout << "Transformed Data:" << std::endl;
    for (const auto& line : data) {
        std::cout << line << std::endl;
    }
}

} // namespace etlforge