#include "Validation.h"
#include <cctype>

namespace Validation {

    bool isNotEmpty(const std::string& value) {
        return !value.empty();
    }

    bool isNotNegative(std::initializer_list<double> values) {
        for (double value : values) {
            if (value < 0) {
                return false;
            }
        }
        return true;
    }

    bool isAlphanumeric(const std::string& value) {
        if (!isNotEmpty(value)) return false;

        for (char t : value) {
            if (!std::isalnum(t) && t != ' ') {
                return false;
            }
        }
        return true;
    }

    bool isAlpha(const std::string& value) {
        if (!isNotEmpty(value)) return false;

        for (char t : value) {
            if (!std::isalpha(t)) {
                return false;
            }
        }
        return true;
    }

    bool validMark(double value){
        return (value >= 2 && value <= 6);
    }

}