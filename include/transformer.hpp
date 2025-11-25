#ifndef ETLFORGE_TRANSFORMER_HPP
#define ETLFORGE_TRANSFORMER_HPP

#include <string>
#include <vector>

namespace etlforge {

class Transformer {
public:
    // Constructor
    Transformer();

    // Destructor
    ~Transformer();

    // Method to transform data
    std::vector<std::string> transformData(const std::vector<std::string>& data);
};

} // namespace etlforge

#endif // ETLFORGE_TRANSFORMER_HPP