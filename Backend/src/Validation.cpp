#include "Validation.h"
#include <cctype>

namespace Validation {

    bool isNotEmpty(const std::string& value) {
        return !value.empty();
    }

    bool isNonNegative(double value) {
        return value >= 0;
    }

    bool isAlphanumeric(const std::string& value) {
        if (!isNotEmpty(value)) return false;

        for (char t : value) {
            if (!std::isalnum(t)) {
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

}