#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <fstream>
#include <iomanip>
#include <memory>
#include <limits>  // Added for numeric_limits

using namespace std;

// Base Person class
class Person {
protected:
    string name;
    string id;
    int age;

public:
    Person(const string& name, const string& id, int age) 
        : name(name), id(id), age(age) {}

    virtual ~Person() {}

    // Getters
    string getName() const { return name; }
    string getId() const { return id; }
    int getAge() const { return age; }

    // Setters
    void setName(const string& newName) { name = newName; }
    void setAge(int newAge) { age = newAge; }

    // Virtual function for displaying person info
    virtual void displayInfo() const {
        cout << "Name: " << name << "\nID: " << id << "\nAge: " << age << endl;
    }

    // Operator overloading for comparison
    bool operator==(const Person& other) const {
        return id == other.id;
    }

    bool operator<(const Person& other) const {
        return id < other.id;
    }
};

// Derived Student class
class Student : public Person {
private:
    double gpa;
    vector<string> enrolledCourses;

public:
    Student(const string& name, const string& id, int age) 
        : Person(name, id, age), gpa(0.0) {}

    // GPA management
    double getGpa() const { return gpa; }
    void updateGpa(double newGpa) { 
        if (newGpa < 0.0 || newGpa > 4.0) {
            throw invalid_argument("GPA must be between 0.0 and 4.0");
        }
        gpa = newGpa; 
    }

    // Course management
    const vector<string>& getEnrolledCourses() const { return enrolledCourses; }
    void enrollCourse(const string& courseCode) {
        if (find(enrolledCourses.begin(), enrolledCourses.end(), courseCode) != enrolledCourses.end()) {
            throw runtime_error("Student is already enrolled in this course");
        }
        enrolledCourses.push_back(courseCode);
    }

    void dropCourse(const string& courseCode) {
        auto it = find(enrolledCourses.begin(), enrolledCourses.end(), courseCode);
        if (it == enrolledCourses.end()) {
            throw runtime_error("Student is not enrolled in this course");
        }
        enrolledCourses.erase(it);
    }

    // Override displayInfo
    void displayInfo() const override {
        Person::displayInfo();
        cout << "GPA: " << fixed << setprecision(2) << gpa << endl;
        cout << "Enrolled Courses (" << enrolledCourses.size() << "): ";
        for (const auto& course : enrolledCourses) {
            cout << course << " ";
        }
        cout << endl;
    }
};

// Derived Faculty class
class Faculty : public Person {
private:
    string specialization;
    vector<string> coursesTeaching;

public:
    Faculty(const string& name, const string& id, int age, const string& specialization) 
        : Person(name, id, age), specialization(specialization) {}

    // Specialization management
    string getSpecialization() const { return specialization; }
    void setSpecialization(const string& newSpecialization) { specialization = newSpecialization; }

    // Course management
    const vector<string>& getCoursesTeaching() const { return coursesTeaching; }
    void assignCourse(const string& courseCode) {
        if (find(coursesTeaching.begin(), coursesTeaching.end(), courseCode) != coursesTeaching.end()) {
            throw runtime_error("Faculty is already teaching this course");
        }
        coursesTeaching.push_back(courseCode);
    }

    void removeCourse(const string& courseCode) {
        auto it = find(coursesTeaching.begin(), coursesTeaching.end(), courseCode);
        if (it == coursesTeaching.end()) {
            throw runtime_error("Faculty is not teaching this course");
        }
        coursesTeaching.erase(it);
    }

    // Override displayInfo
    void displayInfo() const override {
        Person::displayInfo();
        cout << "Specialization: " << specialization << endl;
        cout << "Teaching Courses (" << coursesTeaching.size() << "): ";
        for (const auto& course : coursesTeaching) {
            cout << course << " ";
        }
        cout << endl;
    }
};

// Course class
class Course {
private:
    string code;
    string title;
    string facultyId;
    vector<string> enrolledStudents;

public:
    Course(const string& code, const string& title, const string& facultyId)
        : code(code), title(title), facultyId(facultyId) {}

    // Getters
    string getCode() const { return code; }
    string getTitle() const { return title; }
    string getFacultyId() const { return facultyId; }
    const vector<string>& getEnrolledStudents() const { return enrolledStudents; }

    // Setters
    void setTitle(const string& newTitle) { title = newTitle; }
    void setFacultyId(const string& newFacultyId) { facultyId = newFacultyId; }

    // Student management
    void enrollStudent(const string& studentId) {
        if (find(enrolledStudents.begin(), enrolledStudents.end(), studentId) != enrolledStudents.end()) {
            throw runtime_error("Student is already enrolled in this course");
        }
        enrolledStudents.push_back(studentId);
    }

    void dropStudent(const string& studentId) {
        auto it = find(enrolledStudents.begin(), enrolledStudents.end(), studentId);
        if (it == enrolledStudents.end()) {
            throw runtime_error("Student is not enrolled in this course");
        }
        enrolledStudents.erase(it);
    }

    void displayInfo() const {
        cout << "Course Code: " << code << "\nTitle: " << title 
             << "\nFaculty In Charge: " << facultyId << endl;
        cout << "Enrolled Students (" << enrolledStudents.size() << "): ";
        for (const auto& student : enrolledStudents) {
            cout << student << " ";
        }
        cout << endl;
    }
};

// Gradebook class
class Gradebook {
private:
    // Map of student ID to map of course code to grade
    map<string, map<string, char>> grades;

    // Helper function to convert grade to GPA points
    double gradeToPoints(char grade) const {
        switch (toupper(grade)) {
            case 'A': return 4.0;
            case 'B': return 3.0;
            case 'C': return 2.0;
            case 'D': return 1.0;
            case 'F': return 0.0;
            default: throw invalid_argument("Invalid grade");
        }
    }

public:
    // Grade management
    void addGrade(const string& studentId, const string& courseCode, char grade) {
        if (grades[studentId].count(courseCode)) {
            throw runtime_error("Grade already exists for this student in this course");
        }
        grades[studentId][courseCode] = toupper(grade);
    }

    void updateGrade(const string& studentId, const string& courseCode, char newGrade) {
        if (!grades.count(studentId) || !grades[studentId].count(courseCode)) {
            throw runtime_error("Grade entry not found");
        }
        grades[studentId][courseCode] = toupper(newGrade);
    }

    void removeGrade(const string& studentId, const string& courseCode) {
        if (!grades.count(studentId) || !grades[studentId].count(courseCode)) {
            throw runtime_error("Grade entry not found");
        }
        grades[studentId].erase(courseCode);
        if (grades[studentId].empty()) {
            grades.erase(studentId);
        }
    }

    char getGrade(const string& studentId, const string& courseCode) const {
        if (!grades.count(studentId) || !grades.at(studentId).count(courseCode)) {
            throw runtime_error("Grade entry not found");
        }
        return grades.at(studentId).at(courseCode);
    }

    // Calculate GPA for a student
    double calculateGpa(const string& studentId) const {
        if (!grades.count(studentId) || grades.at(studentId).empty()) {
            return 0.0;
        }

        double totalPoints = 0.0;
        int count = 0;

        for (const auto& entry : grades.at(studentId)) {
            totalPoints += gradeToPoints(entry.second);
            count++;
        }

        return totalPoints / count;
    }

    // Get all grades for a student
    const map<string, char>& getStudentGrades(const string& studentId) const {
        if (!grades.count(studentId)) {
            throw runtime_error("No grades found for this student");
        }
        return grades.at(studentId);
    }

    // Get all grade data
    const map<string, map<string, char>>& getGradeData() const {
        return grades;
    }
};

// University Student Management System class
class USMS {
private:
    map<string, shared_ptr<Student>> students;
    map<string, shared_ptr<Faculty>> faculty;
    map<string, shared_ptr<Course>> courses;
    Gradebook gradebook;

    // Helper template function for searching
    template<typename T>
    bool exists(const map<string, shared_ptr<T>>& container, const string& id) const {
        return container.find(id) != container.end();
    }

    // File handling
    const string STUDENTS_FILE = "students.dat";
    const string FACULTY_FILE = "faculty.dat";
    const string COURSES_FILE = "courses.dat";
    const string GRADES_FILE = "grades.dat";

public:
    USMS() {
        loadData();
    }

    ~USMS() {
        saveData();
    }

    // Student management
    void addStudent(const string& name, const string& id, int age) {
        if (exists(students, id)) {
            throw runtime_error("Student with this ID already exists");
        }
        students[id] = make_shared<Student>(name, id, age);
    }

    void removeStudent(const string& id) {
        if (!exists(students, id)) {
            throw runtime_error("Student not found");
        }

        // Remove student from all courses
        for (auto& coursePair : courses) {
            try {
                coursePair.second->dropStudent(id);
            } catch (...) {
                // Student wasn't enrolled, ignore
            }
        }

        // Remove student's grades
        for (auto& gradePair : gradebook.getStudentGrades(id)) {
            gradebook.removeGrade(id, gradePair.first);
        }

        students.erase(id);
    }

    shared_ptr<Student> getStudent(const string& id) const {
        if (!exists(students, id)) {
            throw runtime_error("Student not found");
        }
        return students.at(id);
    }

    // Faculty management
    void addFaculty(const string& name, const string& id, int age, const string& specialization) {
        if (exists(faculty, id)) {
            throw runtime_error("Faculty with this ID already exists");
        }
        faculty[id] = make_shared<Faculty>(name, id, age, specialization);
    }

    void removeFaculty(const string& id) {
        if (!exists(faculty, id)) {
            throw runtime_error("Faculty not found");
        }

        // Remove faculty from all courses they teach
        for (auto& coursePair : courses) {
            if (coursePair.second->getFacultyId() == id) {
                coursePair.second->setFacultyId("");
            }
        }

        faculty.erase(id);
    }

    shared_ptr<Faculty> getFaculty(const string& id) const {
        if (!exists(faculty, id)) {
            throw runtime_error("Faculty not found");
        }
        return faculty.at(id);
    }

    // Course management
    void addCourse(const string& code, const string& title, const string& facultyId = "") {
        if (exists(courses, code)) {
            throw runtime_error("Course with this code already exists");
        }
        if (!facultyId.empty() && !exists(faculty, facultyId)) {
            throw runtime_error("Faculty not found");
        }
        courses[code] = make_shared<Course>(code, title, facultyId);
    }

    void removeCourse(const string& code) {
        if (!exists(courses, code)) {
            throw runtime_error("Course not found");
        }

        // Remove course from all students' enrolled courses
        for (auto& studentPair : students) {
            try {
                studentPair.second->dropCourse(code);
            } catch (...) {
                // Student wasn't enrolled, ignore
            }
        }

        // Remove course from faculty's teaching list
        string facultyId = courses[code]->getFacultyId();
        if (!facultyId.empty() && exists(faculty, facultyId)) {
            try {
                faculty[facultyId]->removeCourse(code);
            } catch (...) {
                // Faculty wasn't teaching, ignore
            }
        }

        // Remove all grades for this course
        for (auto& studentPair : students) {
            try {
                gradebook.removeGrade(studentPair.first, code);
            } catch (...) {
                // No grade for this student, ignore
            }
        }

        courses.erase(code);
    }

    shared_ptr<Course> getCourse(const string& code) const {
        if (!exists(courses, code)) {
            throw runtime_error("Course not found");
        }
        return courses.at(code);
    }

    // Enrollment management
    void enrollStudentInCourse(const string& studentId, const string& courseCode) {
        if (!exists(students, studentId)) {
            throw runtime_error("Student not found");
        }
        if (!exists(courses, courseCode)) {
            throw runtime_error("Course not found");
        }

        students[studentId]->enrollCourse(courseCode);
        courses[courseCode]->enrollStudent(studentId);
    }

    void dropStudentFromCourse(const string& studentId, const string& courseCode) {
        if (!exists(students, studentId)) {
            throw runtime_error("Student not found");
        }
        if (!exists(courses, courseCode)) {
            throw runtime_error("Course not found");
        }

        students[studentId]->dropCourse(courseCode);
        courses[courseCode]->dropStudent(studentId);

        // Remove grade if exists
        try {
            gradebook.removeGrade(studentId, courseCode);
        } catch (...) {
            // No grade to remove
        }
    }

    // Grade management
    void addStudentGrade(const string& studentId, const string& courseCode, char grade) {
        if (!exists(students, studentId)) {
            throw runtime_error("Student not found");
        }
        if (!exists(courses, courseCode)) {
            throw runtime_error("Course not found");
        }

        gradebook.addGrade(studentId, courseCode, grade);
        students[studentId]->updateGpa(gradebook.calculateGpa(studentId));
    }

    void updateStudentGrade(const string& studentId, const string& courseCode, char newGrade) {
        if (!exists(students, studentId)) {
            throw runtime_error("Student not found");
        }
        if (!exists(courses, courseCode)) {
            throw runtime_error("Course not found");
        }

        gradebook.updateGrade(studentId, courseCode, newGrade);
        students[studentId]->updateGpa(gradebook.calculateGpa(studentId));
    }

    void removeStudentGrade(const string& studentId, const string& courseCode) {
        if (!exists(students, studentId)) {
            throw runtime_error("Student not found");
        }
        if (!exists(courses, courseCode)) {
            throw runtime_error("Course not found");
        }

        gradebook.removeGrade(studentId, courseCode);
        students[studentId]->updateGpa(gradebook.calculateGpa(studentId));
    }

    // Reporting
    void displayStudentReport(const string& studentId) const {
        auto student = getStudent(studentId);
        student->displayInfo();

        cout << "\nGrades:\n";
        try {
            auto grades = gradebook.getStudentGrades(studentId);
            for (const auto& entry : grades) {
                cout << entry.first << ": " << entry.second << endl;
            }
        } catch (const exception& e) {
            cout << "No grades recorded yet\n";
        }
    }

    void displayCourseReport(const string& courseCode) const {
        auto course = getCourse(courseCode);
        course->displayInfo();

        cout << "\nGrades:\n";
        for (const auto& studentId : course->getEnrolledStudents()) {
            try {
                char grade = gradebook.getGrade(studentId, courseCode);
                cout << studentId << ": " << grade << endl;
            } catch (...) {
                // No grade for this student
            }
        }
    }

    void displayAllStudents() const {
        cout << "All Students (" << students.size() << "):\n";
        for (const auto& studentPair : students) {
            studentPair.second->displayInfo();
            cout << "-----------------\n";
        }
    }

    void displayAllCourses() const {
        cout << "All Courses (" << courses.size() << "):\n";
        for (const auto& coursePair : courses) {
            coursePair.second->displayInfo();
            cout << "-----------------\n";
        }
    }

    void displayAllFaculty() const {
        cout << "All Faculty (" << faculty.size() << "):\n";
        for (const auto& facultyPair : faculty) {
            facultyPair.second->displayInfo();
            cout << "-----------------\n";
        }
    }

    // File handling
    void saveData() const {
        // Save students
        ofstream studentFile(STUDENTS_FILE);
        for (const auto& studentPair : students) {
            auto student = studentPair.second;
            studentFile << student->getName() << "\n"
                       << student->getId() << "\n"
                       << student->getAge() << "\n"
                       << student->getGpa() << "\n";
            
            // Save enrolled courses
            const auto& courses = student->getEnrolledCourses();
            studentFile << courses.size() << "\n";
            for (const auto& course : courses) {
                studentFile << course << "\n";
            }
        }
        studentFile.close();

        // Save faculty
        ofstream facultyFile(FACULTY_FILE);
        for (const auto& facultyPair : faculty) {
            auto facultyMember = facultyPair.second;
            facultyFile << facultyMember->getName() << "\n"
                       << facultyMember->getId() << "\n"
                       << facultyMember->getAge() << "\n"
                       << facultyMember->getSpecialization() << "\n";
            
            // Save teaching courses
            const auto& courses = facultyMember->getCoursesTeaching();
            facultyFile << courses.size() << "\n";
            for (const auto& course : courses) {
                facultyFile << course << "\n";
            }
        }
        facultyFile.close();

        // Save courses
        ofstream courseFile(COURSES_FILE);
        for (const auto& coursePair : courses) {
            auto course = coursePair.second;
            courseFile << course->getCode() << "\n"
                      << course->getTitle() << "\n"
                      << course->getFacultyId() << "\n";
            
            // Save enrolled students
            const auto& students = course->getEnrolledStudents();
            courseFile << students.size() << "\n";
            for (const auto& student : students) {
                courseFile << student << "\n";
            }
        }
        courseFile.close();

        // Save grades
        ofstream gradeFile(GRADES_FILE);
        for (const auto& studentGrades : gradebook.getGradeData()) {
            gradeFile << studentGrades.first << "\n"
                     << studentGrades.second.size() << "\n";
            for (const auto& courseGrade : studentGrades.second) {
                gradeFile << courseGrade.first << "\n"
                         << courseGrade.second << "\n";
            }
        }
        gradeFile.close();
    }

    void loadData() {
        // Load students
        ifstream studentFile(STUDENTS_FILE);
        if (studentFile) {
            string name, id;
            int age;
            double gpa;
            while (getline(studentFile, name) && getline(studentFile, id) 
                   && studentFile >> age >> gpa) {
                studentFile.ignore(); // Skip newline
                
                students[id] = make_shared<Student>(name, id, age);
                students[id]->updateGpa(gpa);
                
                // Load enrolled courses
                int numCourses;
                studentFile >> numCourses;
                studentFile.ignore();
                for (int i = 0; i < numCourses; ++i) {
                    string courseCode;
                    getline(studentFile, courseCode);
                    students[id]->enrollCourse(courseCode);
                }
            }
            studentFile.close();
        }

        // Load faculty
        ifstream facultyFile(FACULTY_FILE);
        if (facultyFile) {
            string name, id, specialization;
            int age;
            while (getline(facultyFile, name) && getline(facultyFile, id) 
                   && facultyFile >> age && facultyFile.ignore() 
                   && getline(facultyFile, specialization)) {
                
                faculty[id] = make_shared<Faculty>(name, id, age, specialization);
                
                // Load teaching courses
                int numCourses;
                facultyFile >> numCourses;
                facultyFile.ignore();
                for (int i = 0; i < numCourses; ++i) {
                    string courseCode;
                    getline(facultyFile, courseCode);
                    faculty[id]->assignCourse(courseCode);
                }
            }
            facultyFile.close();
        }

        // Load courses
        ifstream courseFile(COURSES_FILE);
        if (courseFile) {
            string code, title, facultyId;
            while (getline(courseFile, code) && getline(courseFile, title) 
                   && getline(courseFile, facultyId)) {
                
                courses[code] = make_shared<Course>(code, title, facultyId);
                
                // Load enrolled students
                int numStudents;
                courseFile >> numStudents;
                courseFile.ignore();
                for (int i = 0; i < numStudents; ++i) {
                    string studentId;
                    getline(courseFile, studentId);
                    courses[code]->enrollStudent(studentId);
                }
            }
            courseFile.close();
        }

        // Load grades
        ifstream gradeFile(GRADES_FILE);
        if (gradeFile) {
            string studentId;
            while (getline(gradeFile, studentId)) {
                int numGrades;
                gradeFile >> numGrades;
                gradeFile.ignore();
                for (int i = 0; i < numGrades; ++i) {
                    string courseCode;
                    char grade;
                    getline(gradeFile, courseCode);
                    gradeFile >> grade;
                    gradeFile.ignore();
                    gradebook.addGrade(studentId, courseCode, grade);
                }
            }
            gradeFile.close();
        }
    }
};

// Menu system
void displayMainMenu() {
    cout << "\nUniversity Student Management System\n";
    cout << "1. Student Management\n";
    cout << "2. Faculty Management\n";
    cout << "3. Course Management\n";
    cout << "4. Enrollment Management\n";
    cout << "5. Grade Management\n";
    cout << "6. Reports\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
}

void displayStudentMenu() {
    cout << "\nStudent Management\n";
    cout << "1. Add Student\n";
    cout << "2. Remove Student\n";
    cout << "3. View Student\n";
    cout << "4. List All Students\n";
    cout << "5. Back to Main Menu\n";
    cout << "Enter your choice: ";
}

void displayFacultyMenu() {
    cout << "\nFaculty Management\n";
    cout << "1. Add Faculty\n";
    cout << "2. Remove Faculty\n";
    cout << "3. View Faculty\n";
    cout << "4. List All Faculty\n";
    cout << "5. Back to Main Menu\n";
    cout << "Enter your choice: ";
}

void displayCourseMenu() {
    cout << "\nCourse Management\n";
    cout << "1. Add Course\n";
    cout << "2. Remove Course\n";
    cout << "3. View Course\n";
    cout << "4. List All Courses\n";
    cout << "5. Back to Main Menu\n";
    cout << "Enter your choice: ";
}

void displayEnrollmentMenu() {
    cout << "\nEnrollment Management\n";
    cout << "1. Enroll Student in Course\n";
    cout << "2. Drop Student from Course\n";
    cout << "3. Back to Main Menu\n";
    cout << "Enter your choice: ";
}

void displayGradeMenu() {
    cout << "\nGrade Management\n";
    cout << "1. Add Grade\n";
    cout << "2. Update Grade\n";
    cout << "3. Remove Grade\n";
    cout << "4. Back to Main Menu\n";
    cout << "Enter your choice: ";
}

void displayReportMenu() {
    cout << "\nReports\n";
    cout << "1. Student Report\n";
    cout << "2. Course Report\n";
    cout << "3. Back to Main Menu\n";
    cout << "Enter your choice: ";
}

// Helper function to get input with validation
template<typename T>
T getInput(const string& prompt) {
    T value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please try again.\n";
        } else {
            cin.ignore();
            break;
        }
    }
    return value;
}

int main() {
    USMS system;
    int choice;

    do {
        displayMainMenu();
        choice = getInput<int>("");

        try {
            switch (choice) {
                case 1: { // Student Management
                    int studentChoice;
                    do {
                        displayStudentMenu();
                        studentChoice = getInput<int>("");

                        switch (studentChoice) {
                            case 1: { // Add Student
                                string name = getInput<string>("Enter student name: ");
                                string id = getInput<string>("Enter student ID: ");
                                int age = getInput<int>("Enter student age: ");
                                system.addStudent(name, id, age);
                                cout << "Student added successfully.\n";
                                break;
                            }
                            case 2: { // Remove Student
                                string id = getInput<string>("Enter student ID to remove: ");
                                system.removeStudent(id);
                                cout << "Student removed successfully.\n";
                                break;
                            }
                            case 3: { // View Student
                                string id = getInput<string>("Enter student ID to view: ");
                                system.displayStudentReport(id);
                                break;
                            }
                            case 4: // List All Students
                                system.displayAllStudents();
                                break;
                            case 5: // Back to Main Menu
                                break;
                            default:
                                cout << "Invalid choice. Please try again.\n";
                        }
                    } while (studentChoice != 5);
                    break;
                }
                case 2: { // Faculty Management
                    int facultyChoice;
                    do {
                        displayFacultyMenu();
                        facultyChoice = getInput<int>("");

                        switch (facultyChoice) {
                            case 1: { // Add Faculty
                                string name = getInput<string>("Enter faculty name: ");
                                string id = getInput<string>("Enter faculty ID: ");
                                int age = getInput<int>("Enter faculty age: ");
                                string specialization = getInput<string>("Enter specialization: ");
                                system.addFaculty(name, id, age, specialization);
                                cout << "Faculty added successfully.\n";
                                break;
                            }
                            case 2: { // Remove Faculty
                                string id = getInput<string>("Enter faculty ID to remove: ");
                                system.removeFaculty(id);
                                cout << "Faculty removed successfully.\n";
                                break;
                            }
                            case 3: { // View Faculty
                                string id = getInput<string>("Enter faculty ID to view: ");
                                system.getFaculty(id)->displayInfo();
                                break;
                            }
                            case 4: // List All Faculty
                                system.displayAllFaculty();
                                break;
                            case 5: // Back to Main Menu
                                break;
                            default:
                                cout << "Invalid choice. Please try again.\n";
                        }
                    } while (facultyChoice != 5);
                    break;
                }
                case 3: { // Course Management
                    int courseChoice;
                    do {
                        displayCourseMenu();
                        courseChoice = getInput<int>("");

                        switch (courseChoice) {
                            case 1: { // Add Course
                                string code = getInput<string>("Enter course code: ");
                                string title = getInput<string>("Enter course title: ");
                                string facultyId = getInput<string>("Enter faculty ID (leave empty if none): ");
                                system.addCourse(code, title, facultyId);
                                cout << "Course added successfully.\n";
                                break;
                            }
                            case 2: { // Remove Course
                                string code = getInput<string>("Enter course code to remove: ");
                                system.removeCourse(code);
                                cout << "Course removed successfully.\n";
                                break;
                            }
                            case 3: { // View Course
                                string code = getInput<string>("Enter course code to view: ");
                                system.displayCourseReport(code);
                                break;
                            }
                            case 4: // List All Courses
                                system.displayAllCourses();
                                break;
                            case 5: // Back to Main Menu
                                break;
                            default:
                                cout << "Invalid choice. Please try again.\n";
                        }
                    } while (courseChoice != 5);
                    break;
                }
                case 4: { // Enrollment Management
                    int enrollChoice;
                    do {
                        displayEnrollmentMenu();
                        enrollChoice = getInput<int>("");

                        switch (enrollChoice) {
                            case 1: { // Enroll Student
                                string studentId = getInput<string>("Enter student ID: ");
                                string courseCode = getInput<string>("Enter course code: ");
                                system.enrollStudentInCourse(studentId, courseCode);
                                cout << "Student enrolled successfully.\n";
                                break;
                            }
                            case 2: { // Drop Student
                                string studentId = getInput<string>("Enter student ID: ");
                                string courseCode = getInput<string>("Enter course code: ");
                                system.dropStudentFromCourse(studentId, courseCode);
                                cout << "Student dropped successfully.\n";
                                break;
                            }
                            case 3: // Back to Main Menu
                                break;
                            default:
                                cout << "Invalid choice. Please try again.\n";
                        }
                    } while (enrollChoice != 3);
                    break;
                }
                case 5: { // Grade Management
                    int gradeChoice;
                    do {
                        displayGradeMenu();
                        gradeChoice = getInput<int>("");

                        switch (gradeChoice) {
                            case 1: { // Add Grade
                                string studentId = getInput<string>("Enter student ID: ");
                                string courseCode = getInput<string>("Enter course code: ");
                                char grade = getInput<char>("Enter grade (A-F): ");
                                system.addStudentGrade(studentId, courseCode, grade);
                                cout << "Grade added successfully.\n";
                                break;
                            }
                            case 2: { // Update Grade
                                string studentId = getInput<string>("Enter student ID: ");
                                string courseCode = getInput<string>("Enter course code: ");
                                char newGrade = getInput<char>("Enter new grade (A-F): ");
                                system.updateStudentGrade(studentId, courseCode, newGrade);
                                cout << "Grade updated successfully.\n";
                                break;
                            }
                            case 3: { // Remove Grade
                                string studentId = getInput<string>("Enter student ID: ");
                                string courseCode = getInput<string>("Enter course code: ");
                                system.removeStudentGrade(studentId, courseCode);
                                cout << "Grade removed successfully.\n";
                                break;
                            }
                            case 4: // Back to Main Menu
                                break;
                            default:
                                cout << "Invalid choice. Please try again.\n";
                        }
                    } while (gradeChoice != 4);
                    break;
                }
                case 6: { // Reports
                    int reportChoice;
                    do {
                        displayReportMenu();
                        reportChoice = getInput<int>("");

                        switch (reportChoice) {
                            case 1: { // Student Report
                                string studentId = getInput<string>("Enter student ID: ");
                                system.displayStudentReport(studentId);
                                break;
                            }
                            case 2: { // Course Report
                                string courseCode = getInput<string>("Enter course code: ");
                                system.displayCourseReport(courseCode);
                                break;
                            }
                            case 3: // Back to Main Menu
                                break;
                            default:
                                cout << "Invalid choice. Please try again.\n";
                        }
                    } while (reportChoice != 3);
                    break;
                }
                case 7: // Exit
                    cout << "Saving data and exiting...\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    } while (choice != 7);

    return 0;
}