#ifndef TIME_H
#define TIME_H

#include "Converter.h"
#include <string>

class Time : public Converter {
public:
    double convert(double value,
                   const std::string& from,
                   const std::string& to) override;
};

#endif
