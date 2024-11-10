#include <stdexcept>
#include <iostream>
#include "Grade.h"
#include "Validation.h"

Grade::Grade(std::string subject, double mark){
    if(!Validation::isNotNegative({mark}) || !Validation::isAlpha(subject)){
        throw std::invalid_argument("Invalid grade or subject");
    }
    this->subject = subject;
    this->mark = mark;
}

std::string Grade::getSubject() const{
    return subject;
}

double Grade::getMark() const{
    return mark;
}

void Grade::setMark(double mark){
    this->mark = mark;
}

void Grade::setSubject(std::string subject){
    this->subject = subject;
}

std::ostream& operator<<(std::ostream& os, const Grade& grade) {
    os << "    Subject: " << grade.getSubject() << ", Grade: " << grade.getMark();
    return os;
}