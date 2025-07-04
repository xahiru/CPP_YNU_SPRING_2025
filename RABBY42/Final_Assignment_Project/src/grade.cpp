#include "../include/grade.h"
#include <map>

Grade::Grade(const std::string& studentId, const std::string& courseCode, const std::string& grade)
    : studentId(studentId), courseCode(courseCode), letterGrade(grade) {}

double Grade::getGradePoint() const {
    static const std::map<std::string, double> gradeMap = {
        {"A", 4.0}, {"A-", 3.7}, {"B+", 3.3}, {"B", 3.0}, {"B-", 2.7},
        {"C+", 2.3}, {"C", 2.0}, {"C-", 1.7}, {"D+", 1.3}, {"D", 1.0}, {"F", 0.0}
    };
    auto it = gradeMap.find(letterGrade);
    return (it != gradeMap.end()) ? it->second : 0.0;
}