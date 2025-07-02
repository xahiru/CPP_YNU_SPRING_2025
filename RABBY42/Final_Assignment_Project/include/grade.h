#ifndef GRADE_H
#define GRADE_H
#include <string>

class Grade {
private:
    std::string studentId;
    std::string courseCode;
    std::string letterGrade;

public:
    Grade() : studentId(""), courseCode(""), letterGrade("") {} // Added default constructor
    Grade(const std::string& studentId, const std::string& courseCode, const std::string& grade);
    std::string getStudentId() const { return studentId; }
    std::string getCourseCode() const { return courseCode; }
    std::string getLetterGrade() const { return letterGrade; }
    double getGradePoint() const;
};

#endif