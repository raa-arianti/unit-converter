#ifndef JSON_HANDLER_H
#define JSON_HANDLER_H

#include "FileHandler.h"
#include "external/json.hpp"
#include <string>
#include <vector>

class JsonHandler : public FileHandler {
public:
    explicit JsonHandler(const std::string& filepath);

    std::vector<double> readColumn(size_t index) override;
    void writeColumn(const std::vector<double>& data) override;

private:
    std::string filepath_;
};

#endif
