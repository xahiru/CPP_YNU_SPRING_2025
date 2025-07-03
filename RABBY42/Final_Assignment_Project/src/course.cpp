#include "../include/course.h"
#include <iostream>

Course::Course(const std::string& code, const std::string& title, const std::string& facultyId)
    : courseCode(code), title(title), facultyId(facultyId) {}

void Course::enrollStudent(const std::string& studentId) {
    enrolledStudents.push_back(studentId);
}

void Course::displayInfo() const {
    std::cout << "Course Code: " << courseCode << ", Title: " << title
              << ", Faculty ID: " << facultyId << ", Enrolled Students: ";
    for (const auto& student : enrolledStudents) {
        std::cout << student << " ";
    }
    std::cout << std::endl;
}