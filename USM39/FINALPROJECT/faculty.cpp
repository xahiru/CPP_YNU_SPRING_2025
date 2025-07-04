#include "faculty.h"
#include <iostream>
Faculty::Faculty(const std::string& n, const std::string& i, int a, const std::string& spec)
    : Person(n, i, a), specialization(spec) {}

void Faculty::addCourse(const std::string& code) {
    if (std::find(coursesTeaching.begin(), coursesTeaching.end(), code) == coursesTeaching.end())
        coursesTeaching.push_back(code);
}

void Faculty::display() const {
    std::cout << "Faculty: " << name << ", ID: " << id << ", Age: " << age
        << ", Specialization: " << specialization << std::endl;
}
