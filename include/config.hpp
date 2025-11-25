#ifndef ETLFORGE_CONFIG_HPP
#define ETLFORGE_CONFIG_HPP

#include <string>
#include <unordered_map>

namespace etlforge {

class Config {
public:
    Config();
    ~Config();

    bool loadFromFile(const std::string& filePath);
    std::string getValue(const std::string& key) const;

private:
    std::unordered_map<std::string, std::string> configData;
};

} // namespace etlforge

#endif // ETLFORGE_CONFIG_HPP