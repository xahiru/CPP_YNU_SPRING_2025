#ifndef GRADEBOOK_H
#define GRADEBOOK_H
#include "grade.h"
#include <map>
#include <string>
#include <vector>

class Gradebook {
private:
    std::map<std::pair<std::string, std::string>, Grade> grades;

public:
    void addGrade(const std::string& studentId, const std::string& courseCode, const std::string& grade);
    void updateGrade(const std::string& studentId, const std::string& courseCode, const std::string& grade);
    void deleteGrade(const std::string& studentId, const std::string& courseCode);
    std::vector<Grade> getGradesForStudent(const std::string& studentId) const;
    std::vector<Grade> getGradesForCourse(const std::string& courseCode) const;
    const std::map<std::pair<std::string, std::string>, Grade>& getGrades() const { return grades; }
};

#endif