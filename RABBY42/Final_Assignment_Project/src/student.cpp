#include "../include/student.h"
#include <iostream>

Student::Student(const std::string& name, const std::string& id, int age)
    : Person(name, id, age), gpa(0.0) {}

void Student::enrollCourse(const std::string& courseCode) {
    enrolledCourses.push_back(courseCode);
}

void Student::setGPA(double newGPA) {
    gpa = newGPA;
}

void Student::displayInfo() const {
    Person::displayInfo();
    std::cout << "GPA: " << gpa << ", Enrolled Courses: ";
    for (const auto& course : enrolledCourses) {
        std::cout << course << " ";
    }
    std::cout << std::endl;
}