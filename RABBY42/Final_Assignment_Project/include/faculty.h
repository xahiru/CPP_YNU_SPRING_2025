#ifndef FACULTY_H
#define FACULTY_H
#include "person.h"
#include <string>

class Faculty : public Person {
private:
    std::string subjectSpecialization;

public:
    Faculty(const std::string& name, const std::string& id, int age, const std::string& specialization);
    void displayInfo() const override;
    std::string getSubjectSpecialization() const { return subjectSpecialization; }
};

#endif