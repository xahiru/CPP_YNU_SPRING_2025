#include "../include/usms.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <sstream>
#include <fstream>
#include <unistd.h>

USMS::USMS() {
    loadFromFile();
}

USMS::~USMS() {
    saveToFile();
    for (auto* student : students) delete student;
    for (auto* faculty : faculty) delete faculty;
    for (auto* course : courses) delete course;
}

void USMS::addStudent(const std::string& name, const std::string& id, int age) {
    if (findByID(students, id)) {
        throw std::runtime_error("Student ID already exists.");
    }
    if (age < 16 || age > 100) { // Validation: Reasonable age range
        throw std::runtime_error("Age must be between 16 and 100.");
    }
    students.push_back(new Student(name, id, age));
    saveToFile(); // Immediate save
    std::ofstream log("data/usms.log", std::ios::app);
    if (log.is_open()) {
        log << "Added student: " << id << " at " << __DATE__ << " " << __TIME__ << "\n";
        log.close();
    }
}

void USMS::addFaculty(const std::string& name, const std::string& id, int age, const std::string& specialization) {
    if (findByID(faculty, id)) {
        throw std::runtime_error("Faculty ID already exists.");
    }
    if (age < 25 || age > 100) { // Validation: Reasonable age range
        throw std::runtime_error("Age must be between 25 and 100.");
    }
    faculty.push_back(new Faculty(name, id, age, specialization));
    saveToFile(); // Immediate save
    std::ofstream log("data/usms.log", std::ios::app);
    if (log.is_open()) {
        log << "Added faculty: " << id << " at " << __DATE__ << " " << __TIME__ << "\n";
        log.close();
    }
}

void USMS::addCourse(const std::string& code, const std::string& title, const std::string& facultyId) {
    if (findByID(courses, code)) {
        throw std::runtime_error("Course code already exists.");
    }
    if (!findByID(faculty, facultyId)) {
        throw std::runtime_error("Faculty ID does not exist.");
    }
    courses.push_back(new Course(code, title, facultyId));
    saveToFile(); // Immediate save
    std::ofstream log("data/usms.log", std::ios::app);
    if (log.is_open()) {
        log << "Added course: " << code << " at " << __DATE__ << " " << __TIME__ << "\n";
        log.close();
    }
}

void USMS::enrollStudentInCourse(const std::string& studentId, const std::string& courseCode) {
    auto* student = findByID(students, studentId);
    auto* course = findByID(courses, courseCode);
    if (!student) {
        throw std::runtime_error("Student ID does not exist.");
    }
    if (!course) {
        throw std::runtime_error("Course code does not exist.");
    }
    student->enrollCourse(courseCode);
    course->enrollStudent(studentId);
    saveToFile(); // Immediate save
    std::ofstream log("data/usms.log", std::ios::app);
    if (log.is_open()) {
        log << "Enrolled student: " << studentId << " in " << courseCode << " at " << __DATE__ << " " << __TIME__ << "\n";
        log.close();
    }
}

void USMS::addGrade(const std::string& studentId, const std::string& courseCode, const std::string& grade) {
    if (!findByID(students, studentId)) {
        throw std::runtime_error("Student ID does not exist.");
    }
    if (!findByID(courses, courseCode)) {
        throw std::runtime_error("Course code does not exist.");
    }
    static const std::vector<std::string> validGrades = {"A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D+", "D", "F"};
    if (std::find(validGrades.begin(), validGrades.end(), grade) == validGrades.end()) {
        throw std::runtime_error("Invalid grade.");
    }
    gradebook.addGrade(studentId, courseCode, grade);
    updateStudentGPAs();
    saveToFile(); // Immediate save
    std::ofstream log("data/usms.log", std::ios::app);
    if (log.is_open()) {
        log << "Added grade: " << grade << " for " << studentId << " in " << courseCode << " at " << __DATE__ << " " << __TIME__ << "\n";
        log.close();
    }
}

void USMS::updateGrade(const std::string& studentId, const std::string& courseCode, const std::string& grade) {
    static const std::vector<std::string> validGrades = {"A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D+", "D", "F"};
    if (std::find(validGrades.begin(), validGrades.end(), grade) == validGrades.end()) {
        throw std::runtime_error("Invalid grade.");
    }
    gradebook.updateGrade(studentId, courseCode, grade);
    updateStudentGPAs();
    saveToFile(); // Immediate save
    std::ofstream log("data/usms.log", std::ios::app);
    if (log.is_open()) {
        log << "Updated grade: " << grade << " for " << studentId << " in " << courseCode << " at " << __DATE__ << " " << __TIME__ << "\n";
        log.close();
    }
}

void USMS::deleteGrade(const std::string& studentId, const std::string& courseCode) {
    gradebook.deleteGrade(studentId, courseCode);
    updateStudentGPAs();
    saveToFile(); // Immediate save
    std::ofstream log("data/usms.log", std::ios::app);
    if (log.is_open()) {
        log << "Deleted grade for " << studentId << " in " << courseCode << " at " << __DATE__ << " " << __TIME__ << "\n";
        log.close();
    }
}

void USMS::updateStudentGPAs() {
    for (auto* student : students) {
        auto grades = gradebook.getGradesForStudent(student->getID());
        double totalPoints = 0.0;
        int count = 0;
        for (const auto& grade : grades) {
            totalPoints += grade.getGradePoint();
            count++;
        }
        double gpa = (count > 0) ? totalPoints / count : 0.0;
        student->setGPA(gpa);
    }
}

void USMS::displayStudentsInCourse(const std::string& courseCode) const {
    auto* course = findByID(courses, courseCode);
    if (!course) {
        throw std::runtime_error("Course code does not exist.");
    }
    std::cout << "Students in " << course->getTitle() << " (" << courseCode << "):\n";
    for (const auto& studentId : course->getEnrolledStudents()) {
        auto* student = findByID(students, studentId);
        if (student) {
            student->displayInfo();
        }
    }
}

void USMS::displayCoursesForStudent(const std::string& studentId) const {
    auto* student = findByID(students, studentId);
    if (!student) {
        throw std::runtime_error("Student ID does not exist.");
    }
    std::cout << "Courses for " << student->getName() << " (" << studentId << "):\n";
    for (const auto& courseCode : student->getEnrolledCourses()) {
        auto* course = findByID(courses, courseCode);
        if (course) {
            course->displayInfo();
        }
    }
}

void USMS::displayGPAReport(const std::string& studentId) const {
    auto* student = findByID(students, studentId);
    if (!student) {
        throw std::runtime_error("Student ID does not exist.");
    }
    auto grades = gradebook.getGradesForStudent(studentId);
    double totalPoints = 0.0;
    int count = 0;
    std::cout << "GPA Report for " << student->getName() << " (" << studentId << "):\n";
    for (const auto& grade : grades) {
        std::cout << "Course: " << grade.getCourseCode() << ", Grade: " << grade.getLetterGrade()
                  << ", Points: " << grade.getGradePoint() << std::endl;
        totalPoints += grade.getGradePoint();
        count++;
    }
    double gpa = (count > 0) ? totalPoints / count : 0.0;
    std::cout << "GPA: " << gpa << std::endl;
}

void USMS::saveToFile() {
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) == nullptr) {
        std::cerr << "Error: Could not get current directory.\n";
        return;
    }
    std::string dataPath = std::string(cwd) + "/data/";

    std::ofstream outFile(dataPath + "students.txt");
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open " << dataPath << "students.txt for writing.\n";
        return;
    }
    for (const auto* student : students) {
        outFile << student->getID() << "," << student->getName() << "," << student->getAge() << "," << student->getGPA() << "\n";
    }
    outFile.flush();
    outFile.close();

    outFile.open(dataPath + "faculty.txt");
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open " << dataPath << "faculty.txt for writing.\n";
        return;
    }
    for (const auto* f : faculty) {
        outFile << f->getID() << "," << f->getName() << "," << f->getAge() << "," << f->getSubjectSpecialization() << "\n";
    }
    outFile.flush();
    outFile.close();

    outFile.open(dataPath + "courses.txt");
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open " << dataPath << "courses.txt for writing.\n";
        return;
    }
    for (const auto* course : courses) {
        outFile << course->getCourseCode() << "," << course->getTitle() << "," << course->getFacultyId() << "\n";
    }
    outFile.flush();
    outFile.close();

    outFile.open(dataPath + "enrollments.txt");
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open " << dataPath << "enrollments.txt for writing.\n";
        return;
    }
    for (const auto* course : courses) {
        for (const auto& studentId : course->getEnrolledStudents()) {
            outFile << course->getCourseCode() << "," << studentId << "\n";
        }
    }
    outFile.flush();
    outFile.close();

    outFile.open(dataPath + "grades.txt");
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open " << dataPath << "grades.txt for writing.\n";
        return;
    }
    for (const auto& pair : gradebook.getGrades()) {
        const auto& grade = pair.second;
        outFile << grade.getStudentId() << "," << grade.getCourseCode() << "," << grade.getLetterGrade() << "\n";
    }
    outFile.flush();
    outFile.close();
}

void USMS::loadFromFile() {
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) == nullptr) {
        std::cerr << "Error: Could not get current directory.\n";
        return;
    }
    std::string dataPath = std::string(cwd) + "/data/";

    std::ifstream inFile(dataPath + "students.txt");
    std::string line;
    while (std::getline(inFile, line)) {
        std::stringstream ss(line);
        std::string id, name, ageStr, gpaStr;
        std::getline(ss, id, ',');
        std::getline(ss, name, ',');
        std::getline(ss, ageStr, ',');
        std::getline(ss, gpaStr, ',');
        try {
            int age = std::stoi(ageStr);
            double gpa = std::stod(gpaStr);
            Student* student = new Student(name, id, age);
            student->setGPA(gpa);
            students.push_back(student);
        } catch (const std::exception& e) {
            std::cerr << "Error loading student data: " << e.what() << std::endl;
        }
    }
    inFile.close();

    inFile.open(dataPath + "faculty.txt");
    while (std::getline(inFile, line)) {
        std::stringstream ss(line);
        std::string id, name, ageStr, specialization;
        std::getline(ss, id, ',');
        std::getline(ss, name, ',');
        std::getline(ss, ageStr, ',');
        std::getline(ss, specialization, ',');
        try {
            int age = std::stoi(ageStr);
            faculty.push_back(new Faculty(name, id, age, specialization));
        } catch (const std::exception& e) {
            std::cerr << "Error loading faculty data: " << e.what() << std::endl;
        }
    }
    inFile.close();

    inFile.open(dataPath + "courses.txt");
    while (std::getline(inFile, line)) {
        std::stringstream ss(line);
        std::string code, title, facultyId;
        std::getline(ss, code, ',');
        std::getline(ss, title, ',');
        std::getline(ss, facultyId, ',');
        courses.push_back(new Course(code, title, facultyId));
    }
    inFile.close();

    inFile.open(dataPath + "enrollments.txt");
    while (std::getline(inFile, line)) {
        std::stringstream ss(line);
        std::string courseCode, studentId;
        std::getline(ss, courseCode, ',');
        std::getline(ss, studentId, ',');
        auto* student = findByID(students, studentId);
        auto* course = findByID(courses, courseCode);
        if (student && course) {
            student->enrollCourse(courseCode);
            course->enrollStudent(studentId);
        }
    }
    inFile.close();

    inFile.open(dataPath + "grades.txt");
    while (std::getline(inFile, line)) {
        std::stringstream ss(line);
        std::string studentId, courseCode, grade;
        std::getline(ss, studentId, ',');
        std::getline(ss, courseCode, ',');
        std::getline(ss, grade, ',');
        gradebook.addGrade(studentId, courseCode, grade);
    }
    inFile.close();

    updateStudentGPAs();
}

void USMS::run() {
    while (true) {
        std::cout << "\nUniversity Student Management System\n"
                  << "1. Add Student\n"
                  << "2. Add Faculty\n"
                  << "3. Add Course\n"
                  << "4. Enroll Student in Course\n"
                  << "5. Add Grade\n"
                  << "6. Update Grade\n"
                  << "7. Delete Grade\n"
                  << "8. View Students in Course\n"
                  << "9. View Courses for Student\n"
                  << "10. View GPA Report\n"
                  << "11. Exit\n"
                  << "Enter choice: ";
        int choice;
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        std::cin.ignore();
        try {
            switch (choice) {
                case 1: {
                    std::string name, id;
                    int age;
                    std::cout << "Enter name: ";
                    std::getline(std::cin, name);
                    std::cout << "Enter ID: ";
                    std::getline(std::cin, id);
                    std::cout << "Enter age: ";
                    if (!(std::cin >> age)) {
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                        throw std::runtime_error("Invalid age input.");
                    }
                    std::cin.ignore();
                    addStudent(name, id, age);
                    std::cout << "Student added successfully.\n";
                    break;
                }
                case 2: {
                    std::string name, id, specialization;
                    int age;
                    std::cout << "Enter name: ";
                    std::getline(std::cin, name);
                    std::cout << "Enter ID: ";
                    std::getline(std::cin, id);
                    std::cout << "Enter age: ";
                    if (!(std::cin >> age)) {
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                        throw std::runtime_error("Invalid age input.");
                    }
                    std::cin.ignore();
                    std::cout << "Enter specialization: ";
                    std::getline(std::cin, specialization);
                    addFaculty(name, id, age, specialization);
                    std::cout << "Faculty added successfully.\n";
                    break;
                }
                case 3: {
                    std::string code, title, facultyId;
                    std::cout << "Enter course code: ";
                    std::getline(std::cin, code);
                    std::cout << "Enter course title: ";
                    std::getline(std::cin, title);
                    std::cout << "Enter faculty ID: ";
                    std::getline(std::cin, facultyId);
                    addCourse(code, title, facultyId);
                    std::cout << "Course added successfully.\n";
                    break;
                }
                case 4: {
                    std::string studentId, courseCode;
                    std::cout << "Enter student ID: ";
                    std::getline(std::cin, studentId);
                    std::cout << "Enter course code: ";
                    std::getline(std::cin, courseCode);
                    enrollStudentInCourse(studentId, courseCode);
                    std::cout << "Student enrolled successfully.\n";
                    break;
                }
                case 5: {
                    std::string studentId, courseCode, grade;
                    std::cout << "Enter student ID: ";
                    std::getline(std::cin, studentId);
                    std::cout << "Enter course code: ";
                    std::getline(std::cin, courseCode);
                    std::cout << "Enter grade (e.g., A, B+, C): ";
                    std::getline(std::cin, grade);
                    addGrade(studentId, courseCode, grade);
                    std::cout << "Grade added successfully.\n";
                    break;
                }
                case 6: {
                    std::string studentId, courseCode, grade;
                    std::cout << "Enter student ID: ";
                    std::getline(std::cin, studentId);
                    std::cout << "Enter course code: ";
                    std::getline(std::cin, courseCode);
                    std::cout << "Enter new grade (e.g., A, B+, C): ";
                    std::getline(std::cin, grade);
                    updateGrade(studentId, courseCode, grade);
                    std::cout << "Grade updated successfully.\n";
                    break;
                }
                case 7: {
                    std::string studentId, courseCode;
                    std::cout << "Enter student ID: ";
                    std::getline(std::cin, studentId);
                    std::cout << "Enter course code: ";
                    std::getline(std::cin, courseCode);
                    deleteGrade(studentId, courseCode);
                    std::cout << "Grade deleted successfully.\n";
                    break;
                }
                case 8: {
                    std::string courseCode;
                    std::cout << "Enter course code: ";
                    std::getline(std::cin, courseCode);
                    displayStudentsInCourse(courseCode);
                    break;
                }
                case 9: {
                    std::string studentId;
                    std::cout << "Enter student ID: ";
                    std::getline(std::cin, studentId);
                    displayCoursesForStudent(studentId);
                    break;
                }
                case 10: {
                    std::string studentId;
                    std::cout << "Enter student ID: ";
                    std::getline(std::cin, studentId);
                    displayGPAReport(studentId);
                    break;
                }
                case 11: {
                    std::cout << "Saving data and exiting...\n";
                    saveToFile(); // Final save
                    return;
                }
                default:
                    std::cout << "Invalid choice. Please try again.\n";
            }
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
}