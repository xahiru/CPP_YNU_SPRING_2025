#include "course.h"
#include <iostream>
Course::Course(const std::string& c, const std::string& t, Faculty* f)
    : code(c), title(t), facultyInCharge(f) {}

void Course::enrollStudent(Student* s) {
    if (std::find(students.begin(), students.end(), s) == students.end())
        students.push_back(s);
}

void Course::display() const {
    std::cout << "Course: " << code << ", Title: " << title << ", Faculty: "
        << (facultyInCharge ? facultyInCharge->getID() : "None") << std::endl;
}

void Course::listStudents() const {
    std::cout << "Students enrolled in " << code << ":\n";
    for (const auto& s : students)
        s->display();
}

std::string Course::getCode() const { return code; }
