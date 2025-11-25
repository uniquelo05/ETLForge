#include "utils.hpp"
#include <sstream>
#include <algorithm>

namespace etlforge {

std::vector<std::string> Utils::splitString(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;

    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

std::string Utils::trimString(const std::string& str) {
    size_t start = str.find_first_not_of(" ");
    size_t end = str.find_last_not_of(" ");

    if (start == std::string::npos || end == std::string::npos) {
        return "";
    }

    return str.substr(start, end - start + 1);
}

} // namespace etlforge