#ifndef VALIDATION_H
#define VALIDATION_H
#include <string>
#include <initializer_list>

namespace Validation{
    bool isNotEmpty(const std::string& value);
    bool isNotNegative(const std::initializer_list<double> values);
    bool isAlphanumeric(const std::string& value);
    bool isAlpha(const std::string& value);
    bool validMark(double value);
};


#endif