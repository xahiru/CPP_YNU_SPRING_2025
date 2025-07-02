#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <vector>

class Course {
private:
    std::string courseCode;
    std::string title;
    std::string facultyId;
    std::vector<std::string> enrolledStudents;

public:
    Course(const std::string& code, const std::string& title, const std::string& facultyId);
    void enrollStudent(const std::string& studentId);
    std::string getCourseCode() const { return courseCode; }
    std::string getTitle() const { return title; }
    std::string getFacultyId() const { return facultyId; }
    std::string getID() const { return courseCode; } // Added for findByID compatibility
    const std::vector<std::string>& getEnrolledStudents() const { return enrolledStudents; }
    void displayInfo() const;
};

#endif