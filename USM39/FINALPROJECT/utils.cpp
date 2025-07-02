#include "utils.h"

Student* findStudent(std::vector<Student>& students, const std::string& id) {
    return findByID(students, id);
}

Faculty* findFaculty(std::vector<Faculty>& faculties, const std::string& id) {
    return findByID(faculties, id);
}

Course* findCourse(std::vector<Course>& courses, const std::string& code) {
    for (auto& c : courses) {
        if (c.getCode() == code)
            return &c;
    }
    return nullptr;
}

void clearInputBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
