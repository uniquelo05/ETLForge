#ifndef ETLFORGE_UTILS_HPP
#define ETLFORGE_UTILS_HPP

#include <string>
#include <vector>

namespace etlforge {

class Utils {
public:
    static std::vector<std::string> splitString(const std::string& str, char delimiter);
    static std::string trimString(const std::string& str);
};

} // namespace etlforge

#endif // ETLFORGE_UTILS_HPP