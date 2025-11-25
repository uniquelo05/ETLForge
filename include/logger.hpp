#ifndef ETLFORGE_LOGGER_HPP
#define ETLFORGE_LOGGER_HPP

#include <string>

namespace etlforge {

class Logger {
public:
    static void logInfo(const std::string& message);
    static void logError(const std::string& message);
};

} // namespace etlforge

#endif // ETLFORGE_LOGGER_HPP