#ifndef STUDENT_H
#define STUDENT_H
#include "person.h"
#include <vector>
#include <string>

class Student : public Person {
private:
    double gpa;
    std::vector<std::string> enrolledCourses;

public:
    Student(const std::string& name, const std::string& id, int age);
    void enrollCourse(const std::string& courseCode);
    void setGPA(double newGPA);
    void displayInfo() const override;
    const std::vector<std::string>& getEnrolledCourses() const { return enrolledCourses; }
    double getGPA() const { return gpa; }
};

#endif