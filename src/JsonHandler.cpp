#include "JsonHandler.h"
#include <fstream>
#include <iostream>

using json = nlohmann::json;

bool JsonHandler::load(std::string filename) {
    filepath_ = filename;

    std::ifstream in(filename);
    if (!in.is_open()) {
        std::cerr << "Failed to open JSON file\n";
        return false;
    }

    json j;
    in >> j;

    table.clear();

    if (!j.contains("data") || !j["data"].is_array()) {
        std::cerr << "Invalid JSON format\n";
        return false;
    }

    std::vector<std::string> column;
    for (const auto& item : j["data"]) {
        column.push_back(item.dump());
    }

    table.push_back(column);
    return true;
}

std::vector<std::string> JsonHandler::getColumn(std::string selector) {
    int index = std::stoi(selector);
    if (index < 0 || index >= (int)table.size()) {
        return {};
    }
    return table[index];
}

void JsonHandler::appendColumn(std::string newHeader,
                               const std::vector<std::string>& values) {
    table.push_back(values);
}

void JsonHandler::save(std::string filename) {
    json j;
    j["data"] = json::array();

    if (!table.empty()) {
        for (const auto& v : table.back()) {
            try {
                j["data"].push_back(std::stod(v));
            } catch (...) {
                j["data"].push_back(nullptr);
            }
        }
    }

    std::ofstream out(filename);
    out << j.dump(2);
}
