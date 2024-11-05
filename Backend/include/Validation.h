#ifndef VALIDATION_H
#define VALIDATION_H
#include <string>

namespace Validation{
    bool isNotEmpty(const std::string& value);
    bool isNotNegative(const double value);
    bool isAlphanumeric(const std::string& value);
    bool isAlpha(const std::string& value);
};


#endif