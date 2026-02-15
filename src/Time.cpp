#include "Time.h"
#include <stdexcept>

double Time::convert(double value,
                     const std::string& from,
                     const std::string& to) {
    // convert input to seconds
    double inSeconds;

    if (from == "ms") {
        inSeconds = value / 1000.0;
    } else if (from == "s") {
        inSeconds = value;
    } else if (from == "min") {
        inSeconds = value * 60.0;
    } else if (from == "hour") {
        inSeconds = value * 3600.0;
    } else {
        throw std::invalid_argument("Unknown time unit");
    }

    // convert seconds to target unit
    if (to == "ms") {
        return inSeconds * 1000.0;
    } else if (to == "s") {
        return inSeconds;
    } else if (to == "min") {
        return inSeconds / 60.0;
    } else if (to == "hour") {
        return inSeconds / 3600.0;
    } else {
        throw std::invalid_argument("Unknown time unit");
    }
}
