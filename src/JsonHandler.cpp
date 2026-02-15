#include "JsonHandler.h"
#include <fstream>

using json = nlohmann::json;

JsonHandler::JsonHandler(const std::string& filepath)
    : filepath_(filepath) {}

std::vector<double> JsonHandler::readColumn(size_t index) {
    std::ifstream in(filepath_);
    json j;
    in >> j;

    std::vector<double> result;
    for (const auto& item : j) {
        result.push_back(item.at(index).get<double>());
    }
    return result;
}

void JsonHandler::writeColumn(const std::vector<double>& data) {
    json j = json::array();
    for (double v : data) {
        j.push_back(v);
    }

    std::ofstream out(filepath_);
    out << j.dump(2);
}
