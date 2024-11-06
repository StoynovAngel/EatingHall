#ifndef GRADE_H
#define GRADE_H

#include <string>
#include <ostream>

class Grade{
    private:
        std::string subject;
        double mark;
    public:
        Grade(std::string subject, double mark);
        std::string getSubject() const;
        double getMark() const;
        friend std::ostream& operator<<(std::ostream& os, const Grade& grade);
};

#endif