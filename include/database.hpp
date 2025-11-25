#ifndef ETLFORGE_DATABASE_HPP
#define ETLFORGE_DATABASE_HPP

#include <string>

namespace etlforge {

class Database {
public:
    Database();
    ~Database();

    bool connect(const std::string& connectionString);
    void disconnect();

private:
    bool isConnected;
};

} // namespace etlforge

#endif // ETLFORGE_DATABASE_HPP