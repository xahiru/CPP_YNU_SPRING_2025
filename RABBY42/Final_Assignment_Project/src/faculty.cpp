#include "../include/faculty.h"
#include <iostream>

Faculty::Faculty(const std::string& name, const std::string& id, int age, const std::string& specialization)
    : Person(name, id, age), subjectSpecialization(specialization) {}

void Faculty::displayInfo() const {
    Person::displayInfo();
    std::cout << "Specialization: " << subjectSpecialization << std::endl;
}