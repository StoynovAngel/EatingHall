#include "Enum.h"
#include <string>
#include <stdexcept>

std::string getStatus(Status status){
    switch (status)
    {
        case Status::EXCELLENT: return "EXCELLENT";
        case Status::MARRIED: return "MARRIED";
        case Status::SOCIAL: return "SOCIAL";
        case Status::NORMAL: return "NORMAL";
        default: throw std::invalid_argument("No such status");
    }
}