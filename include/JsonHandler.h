#ifndef JSON_HANDLER_H
#define JSON_HANDLER_H

#include "FileHandler.h"
#include "external/json.hpp"

#include <string>
#include <vector>

class JsonHandler : public FileHandler {
private:
    std::string filepath_;
    std::vector<std::vector<std::string>> table;

public:
    bool load(std::string filename) override;

    std::vector<std::string> getColumn(std::string selector) override;

    void appendColumn(std::string newHeader,
                      const std::vector<std::string>& values) override;

    void save(std::string filename) override;
};

#endif
