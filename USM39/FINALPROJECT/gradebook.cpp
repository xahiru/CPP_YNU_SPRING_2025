#include "gradebook.h"
#include <map>
#include <stdexcept>

static std::map<char, double> gradeMap = {
    {'A', 4.0}, {'B', 3.0}, {'C', 2.0}, {'D', 1.0}, {'F', 0.0}
};

void Gradebook::addOrUpdateGrade(const std::string& studentID, const std::string& courseCode, char grade) {
    if (gradeMap.find(grade) == gradeMap.end())
        throw std::invalid_argument("Invalid grade!");
    grades[studentID][courseCode] = grade;
}

double Gradebook::calculateGPA(const std::string& studentID) const {
    auto it = grades.find(studentID);
    if (it == grades.end() || it->second.empty())
        return 0.0;
    double total = 0.0;
    int count = 0;
    for (const auto& pair : it->second) {
        total += gradeMap.at(pair.second);
        ++count;
    }
    return count ? total / count : 0.0;
}
