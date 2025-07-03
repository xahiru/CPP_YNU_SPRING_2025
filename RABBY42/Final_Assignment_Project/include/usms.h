#ifndef USMS_H
#define USMS_H
#include "student.h"
#include "faculty.h"
#include "course.h"
#include "gradebook.h"
#include <vector>
#include <string>
#include <fstream>

template <typename T>
T* findByID(const std::vector<T*>& vec, const std::string& id) {
    for (auto* obj : vec) {
        if (obj->getID() == id) {
            return obj;
        }
    }
    return nullptr;
}

class USMS {
private:
    std::vector<Student*> students;
    std::vector<Faculty*> faculty;
    std::vector<Course*> courses;
    Gradebook gradebook;

    void saveToFile();
    void loadFromFile();
    void updateStudentGPAs();

public:
    USMS();
    ~USMS();
    void addStudent(const std::string& name, const std::string& id, int age);
    void addFaculty(const std::string& name, const std::string& id, int age, const std::string& specialization);
    void addCourse(const std::string& code, const std::string& title, const std::string& facultyId);
    void enrollStudentInCourse(const std::string& studentId, const std::string& courseCode);
    void addGrade(const std::string& studentId, const std::string& courseCode, const std::string& grade);
    void updateGrade(const std::string& studentId, const std::string& courseCode, const std::string& grade);
    void deleteGrade(const std::string& studentId, const std::string& courseCode);
    void displayStudentsInCourse(const std::string& courseCode) const;
    void displayCoursesForStudent(const std::string& studentId) const;
    void displayGPAReport(const std::string& studentId) const;
    void run();
};

#endif