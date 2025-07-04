#include "student.h"
#include <iostream>
Student::Student(const std::string& n, const std::string& i, int a)
    : Person(n, i, a) {}

void Student::addCourse(const std::string& code) {
    if (std::find(enrolledCourses.begin(), enrolledCourses.end(), code) == enrolledCourses.end())
        enrolledCourses.push_back(code);
}

void Student::listCourses() const {
    std::cout << "Courses for Student " << name << " (" << id << "):\n";
    for (const auto& c : enrolledCourses)
        std::cout << "  " << c << "\n";
}

void Student::display() const {
    std::cout << "Student: " << name << ", ID: " << id << ", Age: " << age << std::endl;
}
