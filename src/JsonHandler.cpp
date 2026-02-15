#include "JsonHandler.h"
#include <fstream>

bool JsonHandler::load(std::string filename) {
    filename_ = filename;
    std::ifstream in(filename);
    if (!in.is_open()) return false;
    in >> data_;
    return true;
}

std::vector<std::string> JsonHandler::getColumn(std::string selector) {
    std::vector<std::string> result;
    for (const auto& val : data_[selector]) {
        result.push_back(val.get<std::string>());
    }
    return result;
}

void JsonHandler::appendColumn(std::string header,
                               std::vector<std::string> data) {
    data_[header] = data;
}

bool JsonHandler::save(std::string filename) {
    std::ofstream out(filename);
    if (!out.is_open()) return false;
    out << data_.dump(2);
    return true;
}
