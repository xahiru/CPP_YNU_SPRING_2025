#include "../include/gradebook.h"

void Gradebook::addGrade(const std::string& studentId, const std::string& courseCode, const std::string& grade) {
    grades.emplace(std::make_pair(studentId, courseCode), Grade(studentId, courseCode, grade));
}

void Gradebook::updateGrade(const std::string& studentId, const std::string& courseCode, const std::string& grade) {
    auto key = std::make_pair(studentId, courseCode);
    if (grades.find(key) != grades.end()) {
        grades[key] = Grade(studentId, courseCode, grade);
    }
}

void Gradebook::deleteGrade(const std::string& studentId, const std::string& courseCode) {
    grades.erase({studentId, courseCode});
}

std::vector<Grade> Gradebook::getGradesForStudent(const std::string& studentId) const {
    std::vector<Grade> studentGrades;
    for (const auto& pair : grades) {
        if (pair.first.first == studentId) {
            studentGrades.push_back(pair.second);
        }
    }
    return studentGrades;
}

std::vector<Grade> Gradebook::getGradesForCourse(const std::string& courseCode) const {
    std::vector<Grade> courseGrades;
    for (const auto& pair : grades) {
        if (pair.first.second == courseCode) {
            courseGrades.push_back(pair.second);
        }
    }
    return courseGrades;
}