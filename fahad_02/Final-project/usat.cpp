#include <iostream> // for displaying Person information
#include <vector> // for storing lists of courses and students
#include <map> // Added for map operations
#include <string> // Added for string manipulation
#include <algorithm> // Added for sorting and searching
#include <memory> // Added for smart pointers
#include <fstream> // Added for file operations
#include <iomanip> // Added for std::setprecision
#include <stdexcept> // Added for exception handling
#include <limits> // Added for numeric_limits
#include <climits>  // Added for INT_MIN and INT_MAX

// Exception classes
class InvalidInputException : public std::runtime_error {
public:
    InvalidInputException(const std::string& msg) : std::runtime_error(msg) {}  // Invalid input provided
};

class DuplicateIDException : public std::runtime_error {
public:
    DuplicateIDException(const std::string& msg) : std::runtime_error(msg) {}   // Duplicate ID found
};

class NotFoundException : public std::runtime_error {
public:
    NotFoundException(const std::string& msg) : std::runtime_error(msg) {}   // Requested item not found 
};

// Base Person class
class Person {
protected:
    std::string name;
    std::string id;
    int age;
    
public:
    Person(const std::string& name, const std::string& id, int age) //  Constructor to initialize Person attributes
        : name(name), id(id), age(age) {}
    
    virtual ~Person() {}    // Virtual destructor for proper cleanup of derived classes
    
    // Getters
    std::string getName() const { return name; }
    std::string getID() const { return id; }
    int getAge() const { return age; }
    
    // Setters
    void setName(const std::string& newName) { name = newName; }
    void setAge(int newAge) { age = newAge; }
    
    // Virtual function for polymorphism
    virtual void displayInfo() const {
        std::cout << "Name: " << name << "\nID: " << id << "\nAge: " << age << std::endl;
    }
    
    // Operator overloading for comparison
    bool operator==(const Person& other) const {
        return id == other.id;
    }
};

// Derived Student class
class Student : public Person {
private:
    double gpa;
    std::vector<std::string> enrolledCourses;
    
public:
    Student(const std::string& name, const std::string& id, int age)
        : Person(name, id, age), gpa(0.0) {}
    
    // Getters and setters
    double getGPA() const { return gpa; }
    void setGPA(double newGPA) { gpa = newGPA; }
    
    // Course management
    const std::vector<std::string>& getEnrolledCourses() const { return enrolledCourses; }  // Get enrolled courses
    void enrollCourse(const std::string& courseCode) {
        if (std::find(enrolledCourses.begin(), enrolledCourses.end(), courseCode) == enrolledCourses.end()) {   // Check if course is already enrolled
            enrolledCourses.push_back(courseCode);
        }
    }
    void dropCourse(const std::string& courseCode) {
        auto it = std::find(enrolledCourses.begin(), enrolledCourses.end(), courseCode);    // Find the course to drop
        if (it != enrolledCourses.end()) {
            enrolledCourses.erase(it);
        }
    }
    
    // Display student info
    void displayInfo() const override {
        Person::displayInfo();  // Display base class info
        std::cout << "GPA: " << std::fixed << std::setprecision(2) << gpa << std::endl;
        // If there are enrolled courses, display them
        if (!enrolledCourses.empty()) { 
            std::cout << "Enrolled Courses: ";
            //  Iterate through enrolled courses
            for (const auto& course : enrolledCourses) {    
                std::cout << course << " ";
            }
            std::cout << std::endl;
        }
    }
};

// Faculty class derived from Person
class Faculty : public Person {
private:
    std::string specialization;
    std::vector<std::string> coursesTeaching;
    
public:
    Faculty(const std::string& name, const std::string& id, int age, const std::string& specialization) //Constructor to initialize Faculty attributes
        : Person(name, id, age), specialization(specialization) {}
    
    // Specialization management
    std::string getSpecialization() const { return specialization; }
    void setSpecialization(const std::string& newSpec) { specialization = newSpec; }
    
    // Course management
    const std::vector<std::string>& getCoursesTeaching() const { return coursesTeaching; }
    // Add a course to the list of courses teaching
    void addCourse(const std::string& courseCode) { 
        if (std::find(coursesTeaching.begin(), coursesTeaching.end(), courseCode) == coursesTeaching.end()) {
            coursesTeaching.push_back(courseCode);
        }
    }
    // Remove a course from the list of courses teaching
    void removeCourse(const std::string& courseCode) {  
        auto it = std::find(coursesTeaching.begin(), coursesTeaching.end(), courseCode);
        if (it != coursesTeaching.end()) {
            coursesTeaching.erase(it);
        }
    }
    
    // Display faculty info
    void displayInfo() const override {
        Person::displayInfo();
        std::cout << "Specialization: " << specialization << std::endl;
        // If there are courses teaching, display them
        if (!coursesTeaching.empty()) {
            std::cout << "Courses Teaching: ";
            // Iterate through courses teaching
            for (const auto& course : coursesTeaching) {
                std::cout << course << " ";
            }
            std::cout << std::endl;
        }
    }
};

// Course class
class Course {
private:
    std::string code;
    std::string title;
    std::string facultyInCharge;
    std::vector<std::string> enrolledStudents;
    
public:
    // Constructor to initialize course attributes
    Course(const std::string& code, const std::string& title, const std::string& facultyInCharge)
        : code(code), title(title), facultyInCharge(facultyInCharge) {}
    
    // Getters
    std::string getCode() const { return code; }
    std::string getTitle() const { return title; }
    std::string getFacultyInCharge() const { return facultyInCharge; }
    const std::vector<std::string>& getEnrolledStudents() const { return enrolledStudents; }
    
    // Setters
    void setTitle(const std::string& newTitle) { title = newTitle; }
    void setFacultyInCharge(const std::string& newFaculty) { facultyInCharge = newFaculty; }
    
    // Student management
    void enrollStudent(const std::string& studentID) {
        if (std::find(enrolledStudents.begin(), enrolledStudents.end(), studentID) == enrolledStudents.end()) {
            enrolledStudents.push_back(studentID);
        }
    }
    // Drop a student from the course
    void dropStudent(const std::string& studentID) {
        auto it = std::find(enrolledStudents.begin(), enrolledStudents.end(), studentID);
        if (it != enrolledStudents.end()) {
            enrolledStudents.erase(it);
        }
    }
    
    // Display course info
    void displayInfo() const {
        std::cout << "Course Code: " << code << "\nTitle: " << title 
                  << "\nFaculty In Charge: " << facultyInCharge << std::endl;
        // If there are enrolled students, display them
        if (!enrolledStudents.empty()) {
            std::cout << "Enrolled Students (" << enrolledStudents.size() << "): ";
            for (const auto& student : enrolledStudents) {
                std::cout << student << " ";
            }
            std::cout << std::endl;
        }
    }
};

// Gradebook class
class Gradebook {
private:
    // Map of course code to map of student ID to grade (0-100)
    std::map<std::string, std::map<std::string, int>> grades;
    
    // Convert numerical grade (0-100) to letter grade
    char convertToLetterGrade(int numericalGrade) const {
        if (numericalGrade >= 90) return 'A';
        if (numericalGrade >= 80) return 'B';
        if (numericalGrade >= 70) return 'C';
        if (numericalGrade >= 60) return 'D';
        return 'F';
    }
    
    // Convert letter grade to grade points
    double gradeToPoints(char grade) const {
        switch (toupper(grade)) {
            case 'A': return 4.0;
            case 'B': return 3.0;
            case 'C': return 2.0;
            case 'D': return 1.0;
            case 'F': return 0.0;
            default: return 0.0;
        }
    }
    
public:
    // Add or update grade (takes numerical grade 0-100)
    void addGrade(const std::string& courseCode, const std::string& studentID, int numericalGrade) {
        if (numericalGrade < 0 || numericalGrade > 100) {
            throw InvalidInputException("Grade must be between 0 and 100");
        }
        // Ensure the course exists in the map
        grades[courseCode][studentID] = numericalGrade;
    }
    
    // Remove grade
    void removeGrade(const std::string& courseCode, const std::string& studentID) {
        if (grades.find(courseCode) != grades.end()) {
            grades[courseCode].erase(studentID);
            if (grades[courseCode].empty()) {
                grades.erase(courseCode);
            }
        }
    }
    
    // Get numerical grade for a student in a course
    int getNumericalGrade(const std::string& courseCode, const std::string& studentID) const {
        if (grades.find(courseCode) != grades.end()) {
            auto studentGrade = grades.at(courseCode).find(studentID);
            if (studentGrade != grades.at(courseCode).end()) {
                return studentGrade->second;
            }
        }
        return -1; // -1 indicates no grade
    }
    
    // Get letter grade for a student in a course
    char getLetterGrade(const std::string& courseCode, const std::string& studentID) const {
        int numericalGrade = getNumericalGrade(courseCode, studentID);
        if (numericalGrade != -1) {
            return convertToLetterGrade(numericalGrade);
        }
        return '\0'; // Null character indicates no grade
    }
    
    // Calculate GPA for a student
    double calculateGPA(const std::vector<std::string>& courses, const std::string& studentID) const {
        double totalPoints = 0.0;
        int count = 0;
        // Iterate through the courses and calculate total points
        for (const auto& course : courses) {
            char grade = getLetterGrade(course, studentID);
            if (grade != '\0') {
                totalPoints += gradeToPoints(grade);
                count++;
            }
        }
        // If no courses found, return 0.0 GPA
        return count > 0 ? totalPoints / count : 0.0;
    }
    
    // Get all grades for a student (returns numerical grades)
    std::map<std::string, int> getStudentNumericalGrades(const std::string& studentID) const {
        std::map<std::string, int> studentGrades;
        // Iterate through all courses and find grades for the student
        for (const auto& course : grades) {
            auto gradeIt = course.second.find(studentID);
            if (gradeIt != course.second.end()) {
                studentGrades[course.first] = gradeIt->second;
            }
        }
        // Return map of course code to numerical grade
        return studentGrades;
    }
    
    // Get all letter grades for a student
    std::map<std::string, char> getStudentLetterGrades(const std::string& studentID) const {
        std::map<std::string, char> studentGrades;
        for (const auto& course : grades) {
            auto gradeIt = course.second.find(studentID);
            if (gradeIt != course.second.end()) {
                studentGrades[course.first] = convertToLetterGrade(gradeIt->second);
            }
        }
        // Return map of course code to letter grade
        return studentGrades;
    }
    
    // Get all grades (const version)
    const std::map<std::string, std::map<std::string, int>>& getAllGrades() const {
        return grades;
    }
};

// Template class for a generic container
template <typename T>
class NotificationContainer {
private:
    std::vector<T> notifications;
// This class is used to store notifications or messages in a generic way
public:
// Add a notification to the container
    void addNotification(const T& notification) {
        notifications.push_back(notification);
    }
// Remove a notification by value
    void displayAll() const {
        for (const auto& note : notifications) {
            std::cout << "- " << note << std::endl;
        }
    }
// Remove a notification by value 
    void clear() {
        notifications.clear();
    }
    
    size_t size() const {
        return notifications.size();
    }
};

// University Management System class
class UniversityManagementSystem {
private:
    std::vector<Student> students;
    std::vector<Faculty> faculty;
    std::vector<Course> courses;
    Gradebook gradebook;
    NotificationContainer<std::string> notifications;
    
    // Helper functions for input validation
    int getValidIntInput(const std::string& prompt, int min = INT_MIN, int max = INT_MAX) {
        int value;
        // Loop until valid input is received
        while (true) {
            std::cout << prompt;
            std::cin >> value;
            if (std::cin.fail() || value < min || value > max) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a number between " 
                          << min << " and " << max << ".\n";
            } else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return value;
            }
        }
    }
    
    // Check for duplicate IDs
    bool isStudentIDExists(const std::string& id) const {
        return std::any_of(students.begin(), students.end(), 
            [&id](const Student& s) { return s.getID() == id; });
    }
    // Check for duplicate faculty IDs
    bool isFacultyIDExists(const std::string& id) const {
        return std::any_of(faculty.begin(), faculty.end(), 
            [&id](const Faculty& f) { return f.getID() == id; });
    }
    // Check for duplicate course codes
    bool isCourseCodeExists(const std::string& code) const {
        return std::any_of(courses.begin(), courses.end(), 
            [&code](const Course& c) { return c.getCode() == code; });
    }
    
    // Find functions (non-const versions)
    Student* findStudent(const std::string& id) {
        for (auto& student : students) {
            if (student.getID() == id) {
                return &student;
            }
        }
        return nullptr;
    }
    // Find faculty by ID
    Faculty* findFaculty(const std::string& id) {
        for (auto& f : faculty) {
            if (f.getID() == id) {
                return &f;
            }
        }
        return nullptr;
    }
    // Find course by code
    Course* findCourse(const std::string& code) {
        for (auto& course : courses) {
            if (course.getCode() == code) {
                return &course;
            }
        }
        return nullptr;
    }
    
    // Find functions (const versions)
    const Student* findStudent(const std::string& id) const {
        for (const auto& student : students) {
            if (student.getID() == id) {
                return &student;
            }
        }
        return nullptr;
    }
    // Find faculty by ID
    const Faculty* findFaculty(const std::string& id) const {
        for (const auto& f : faculty) {
            if (f.getID() == id) {
                return &f;
            }
        }
        return nullptr;
    }
    // Find course by code
    const Course* findCourse(const std::string& code) const {
        for (const auto& course : courses) {
            if (course.getCode() == code) {
                return &course;
            }
        }
        return nullptr;
    }
    
    // File handling
    void saveDataToFiles() {
        // Save students
        std::ofstream studentFile("students.dat");
        for (const auto& student : students) {
            studentFile << student.getName() << "," << student.getID() << "," 
                       << student.getAge() << "," << student.getGPA() << "\n";
        }
        studentFile.close();
        
        // Save faculty
        std::ofstream facultyFile("faculty.dat");
        for (const auto& f : faculty) {
            facultyFile << f.getName() << "," << f.getID() << "," 
                       << f.getAge() << "," << f.getSpecialization() << "\n";
        }
        facultyFile.close();
        
        // Save courses
        std::ofstream courseFile("courses.dat");
        for (const auto& course : courses) {
            courseFile << course.getCode() << "," << course.getTitle() << "," 
                      << course.getFacultyInCharge() << "\n";
        }
        courseFile.close();
        
        // Save grades
        std::ofstream gradeFile("grades.dat");
        const auto& allGrades = gradebook.getAllGrades();
        for (const auto& [courseCode, studentGrades] : allGrades) {
            for (const auto& [studentID, grade] : studentGrades) {
                gradeFile << courseCode << "," << studentID << "," 
                         << grade << "\n";
            }
        }
        gradeFile.close();
        
        notifications.addNotification("Data saved to files successfully.");
    }
    
    void loadDataFromFiles() {
        // Load students
        std::ifstream studentFile("students.dat");
        // Check if the file exists and can be opened
        if (studentFile) {
            std::string line;
            while (std::getline(studentFile, line)) {
                size_t pos1 = line.find(',');
                size_t pos2 = line.find(',', pos1 + 1);
                size_t pos3 = line.find(',', pos2 + 1);
                
                std::string name = line.substr(0, pos1);
                std::string id = line.substr(pos1 + 1, pos2 - pos1 - 1);
                int age = std::stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));
                double gpa = std::stod(line.substr(pos3 + 1));
                
                Student student(name, id, age);
                student.setGPA(gpa);
                students.push_back(student);
            }
            studentFile.close();
        }
        
        // Load faculty
        std::ifstream facultyFile("faculty.dat");
        // Check if the file exists and can be opened
        if (facultyFile) {
            std::string line;
            while (std::getline(facultyFile, line)) {
                size_t pos1 = line.find(',');
                size_t pos2 = line.find(',', pos1 + 1);
                size_t pos3 = line.find(',', pos2 + 1);
                
                std::string name = line.substr(0, pos1);
                std::string id = line.substr(pos1 + 1, pos2 - pos1 - 1);
                int age = std::stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));
                std::string specialization = line.substr(pos3 + 1);
                
                faculty.emplace_back(name, id, age, specialization);
            }
            facultyFile.close();
        }
        
        // Load courses
        std::ifstream courseFile("courses.dat");
        // Check if the file exists and can be opened
        if (courseFile) {
            std::string line;
            while (std::getline(courseFile, line)) {
                size_t pos1 = line.find(',');
                size_t pos2 = line.find(',', pos1 + 1);
                
                std::string code = line.substr(0, pos1);
                std::string title = line.substr(pos1 + 1, pos2 - pos1 - 1);
                std::string facultyInCharge = line.substr(pos2 + 1);
                
                courses.emplace_back(code, title, facultyInCharge);
            }
            courseFile.close();
        }
        
        // Load grades
        std::ifstream gradeFile("grades.dat");
        // Check if the file exists and can be opened
        if (gradeFile) {
            std::string line;
            while (std::getline(gradeFile, line)) {
                size_t pos1 = line.find(',');
                size_t pos2 = line.find(',', pos1 + 1);
                
                std::string courseCode = line.substr(0, pos1);
                std::string studentID = line.substr(pos1 + 1, pos2 - pos1 - 1);
                int grade = std::stoi(line.substr(pos2 + 1));
                
                gradebook.addGrade(courseCode, studentID, grade);
            }
            gradeFile.close();
        }
        // Notify that data has been loaded successfully
        notifications.addNotification("Data loaded from files successfully.");
    }
    
public:
// Constructor and destructor
    UniversityManagementSystem() {
        try {
            loadDataFromFiles();
        } catch (const std::exception& e) {
            notifications.addNotification(std::string("Error loading data: ") + e.what());
        }
    }
   // Destructor to save data to files before exiting 
    ~UniversityManagementSystem() {
        saveDataToFiles();
    }
    
    // Student management
    void addStudent() {
        std::string name, id;
        int age;
        
        std::cout << "Enter student name: ";
        std::getline(std::cin, name);
        
        std::cout << "Enter student ID: ";
        std::getline(std::cin, id);
        
        if (isStudentIDExists(id)) {
            throw DuplicateIDException("Student ID already exists.");
        }
        // Get valid age input
        age = getValidIntInput("Enter student age: ", 1, 120);
        // Create a new student and add to the list
        students.emplace_back(name, id, age);
        notifications.addNotification("Student added successfully.");
    }
    // Display all students
    void displayAllStudents() const {
        if (students.empty()) {
            std::cout << "No students registered.\n";
            return;
        }
        
        std::cout << "\nList of Students:\n";
        // Iterate through the list of students and display their info
        for (const auto& student : students) {
            student.displayInfo();
            std::cout << "-----------------\n";
        }
    }
    
    // Faculty management
    void addFaculty() {
        std::string name, id, specialization;
        int age;
        
        std::cout << "Enter faculty name: ";
        std::getline(std::cin, name);
        
        std::cout << "Enter faculty ID: ";
        std::getline(std::cin, id);
        // Check if faculty ID already exists
        if (isFacultyIDExists(id)) {
            throw DuplicateIDException("Faculty ID already exists.");
        }
        
        age = getValidIntInput("Enter faculty age: ", 1, 120);
        
        std::cout << "Enter specialization: ";
        std::getline(std::cin, specialization);
        
        faculty.emplace_back(name, id, age, specialization);
        notifications.addNotification("Faculty added successfully.");
    }
    // Display all faculty members
    void displayAllFaculty() const {
        if (faculty.empty()) {
            std::cout << "No faculty registered.\n";
            return;
        }
        
        std::cout << "\nList of Faculty:\n";
        for (const auto& f : faculty) {
            f.displayInfo();
            std::cout << "-----------------\n";
        }
    }
    
    // Course management
    void addCourse() {
        std::string code, title, facultyID;
        
        std::cout << "Enter course code: ";
        std::getline(std::cin, code);
     // Check if course code already exists   
        if (isCourseCodeExists(code)) {
            throw DuplicateIDException("Course code already exists.");
        }
        
        std::cout << "Enter course title: ";
        std::getline(std::cin, title);
        
        std::cout << "Enter faculty ID in charge: ";
        std::getline(std::cin, facultyID);
        // Check if faculty ID exists
        if (!isFacultyIDExists(facultyID)) {
            throw NotFoundException("Faculty ID not found.");
        }
        
        courses.emplace_back(code, title, facultyID);
        
        // Add this course to faculty's teaching list
        Faculty* f = findFaculty(facultyID);
        if (f) {
            f->addCourse(code);
        }
        
        notifications.addNotification("Course added successfully.");
    }
    // Display all courses
    void displayAllCourses() const {
        if (courses.empty()) {
            std::cout << "No courses available.\n";
            return;
        }
        
        std::cout << "\nList of Courses:\n";
        // Iterate through the list of courses and display their info
        for (const auto& course : courses) {
            course.displayInfo();
            std::cout << "-----------------\n";
        }
    }
    
    // Enrollment management
    void enrollStudentInCourse() {
        std::string studentID, courseCode;
        
        std::cout << "Enter student ID: ";
        std::getline(std::cin, studentID);
        
        std::cout << "Enter course code: ";
        std::getline(std::cin, courseCode);
        // Find student and course by ID and code
        Student* student = findStudent(studentID);
        // Find course by code
        Course* course = findCourse(courseCode);
        // Check if student and course exist
        if (!student) {
            throw NotFoundException("Student ID not found.");
        }
        // Check if course exists
        if (!course) {
            throw NotFoundException("Course code not found.");
        }
        
        student->enrollCourse(courseCode);
        course->enrollStudent(studentID);
        
        notifications.addNotification("Student enrolled in course successfully.");
    }
    // Drop student from course
    void dropStudentFromCourse() {
        std::string studentID, courseCode;
        
        std::cout << "Enter student ID: ";
        std::getline(std::cin, studentID);
        
        std::cout << "Enter course code: ";
        std::getline(std::cin, courseCode);
        
        Student* student = findStudent(studentID);
        Course* course = findCourse(courseCode);
        
        if (!student) {
            throw NotFoundException("Student ID not found.");
        }
        if (!course) {
            throw NotFoundException("Course code not found.");
        }
        
        student->dropCourse(courseCode);
        course->dropStudent(studentID);
        
        // Remove any grade for this student in this course
        gradebook.removeGrade(courseCode, studentID);
        
        notifications.addNotification("Student dropped from course successfully.");
    }
    
    // Grade management (now takes numerical grades 0-100)
    void addGrade() {
        std::string studentID, courseCode;
        int numericalGrade;
        
        std::cout << "Enter student ID: ";
        std::getline(std::cin, studentID);
        
        std::cout << "Enter course code: ";
        std::getline(std::cin, courseCode);
        
        Student* student = findStudent(studentID);
        Course* course = findCourse(courseCode);
        
        if (!student) {
            throw NotFoundException("Student ID not found.");
        }
        if (!course) {
            throw NotFoundException("Course code not found.");
        }
        
        // Check if student is enrolled in the course
        const auto& enrolledCourses = student->getEnrolledCourses();
        if (std::find(enrolledCourses.begin(), enrolledCourses.end(), courseCode) == enrolledCourses.end()) {
            throw NotFoundException("Student is not enrolled in this course.");
        }
        
        numericalGrade = getValidIntInput("Enter numerical grade (0-100): ", 0, 100);
        
        gradebook.addGrade(courseCode, studentID, numericalGrade);
        
        // Update student's GPA
        double gpa = gradebook.calculateGPA(enrolledCourses, studentID);
        student->setGPA(gpa);
        
        notifications.addNotification("Grade added successfully.");
    }
    
    // Reporting functions
    void displayStudentsInCourse() const {
        std::string courseCode;
        
        std::cout << "Enter course code: ";
        std::getline(std::cin, courseCode);
        
        const Course* course = findCourse(courseCode);
        if (!course) {
            throw NotFoundException("Course code not found.");
        }
        
        const auto& enrolledStudents = course->getEnrolledStudents();
        if (enrolledStudents.empty()) {
            std::cout << "No students enrolled in this course.\n";
            return;
        }
        
        std::cout << "\nStudents enrolled in " << courseCode << ":\n";
        for (const auto& studentID : enrolledStudents) {
            const Student* student = findStudent(studentID);
            if (student) {
                std::cout << student->getID() << " - " << student->getName();
                int grade = gradebook.getNumericalGrade(courseCode, studentID);
                if (grade != -1) {
                    std::cout << " (Grade: " << grade << " - " 
                              << gradebook.getLetterGrade(courseCode, studentID) << ")";
                }
                std::cout << std::endl;
            }
        }
    }
    // Display courses for a student
    void displayCoursesForStudent() const {
        std::string studentID;
        
        std::cout << "Enter student ID: ";
        std::getline(std::cin, studentID);
        
        const Student* student = findStudent(studentID);
        if (!student) {
            throw NotFoundException("Student ID not found.");
        }
        
        const auto& enrolledCourses = student->getEnrolledCourses();
        if (enrolledCourses.empty()) {
            std::cout << "Student is not enrolled in any courses.\n";
            return;
        }
        
        std::cout << "\nCourses enrolled by " << student->getName() << ":\n";
        for (const auto& courseCode : enrolledCourses) {
            const Course* course = findCourse(courseCode);
            if (course) {
                int numericalGrade = gradebook.getNumericalGrade(courseCode, studentID);
                std::cout << courseCode << " - " << course->getTitle();
                if (numericalGrade != -1) {
                    std::cout << " (Grade: " << numericalGrade << " - " 
                              << gradebook.getLetterGrade(courseCode, studentID) << ")";
                }
                std::cout << std::endl;
            }
        }
    }
    // Display GPA report for a student
    void displayStudentGPAReport() const {
        std::string studentID;
        
        std::cout << "Enter student ID: ";
        std::getline(std::cin, studentID);
        
        const Student* student = findStudent(studentID);
        if (!student) {
            throw NotFoundException("Student ID not found.");
        }
        
        std::cout << "\nGPA Report for " << student->getName() << ":\n";
        std::cout << "Current GPA: " << std::fixed << std::setprecision(2) << student->getGPA() << std::endl;
       //   Get all enrolled courses 
        auto grades = gradebook.getStudentLetterGrades(studentID);
        if (!grades.empty()) {
            std::cout << "\nGrade Details:\n";
            for (const auto& [courseCode, grade] : grades) {
                const Course* course = findCourse(courseCode);
                if (course) {
                    int numericalGrade = gradebook.getNumericalGrade(courseCode, studentID);
                    std::cout << courseCode << " - " << course->getTitle() 
                              << ": " << numericalGrade << " (" << grade << ")" << std::endl;
                }
            }
        }
    }
    
    // Template function for searching
    template <typename Container, typename Predicate>
    void searchAndDisplay(const Container& container, const std::string& header, Predicate pred) const {
        bool found = false;
        std::cout << "\n" << header << ":\n";
        
        for (const auto& item : container) {
            if (pred(item)) {
                item.displayInfo();
                std::cout << "-----------------\n";
                found = true;
            }
        }
        
        if (!found) {
            std::cout << "No matching records found.\n";
        }
    }
    
    // Search functions using the template
    void searchStudentsByName() const {
        std::string name;
        std::cout << "Enter student name (or part of name) to search: ";
        std::getline(std::cin, name);
        
        auto predicate = [&name](const Student& s) {
            return s.getName().find(name) != std::string::npos;
        };
        
        searchAndDisplay(students, "Matching Students", predicate);
    }
    // Search courses by title
    void searchCoursesByTitle() const {
        std::string title;
        std::cout << "Enter course title (or part of title) to search: ";
        std::getline(std::cin, title);
        
        auto predicate = [&title](const Course& c) {
            return c.getTitle().find(title) != std::string::npos;
        };
        // Use the template function to search and display courses
        searchAndDisplay(courses, "Matching Courses", predicate);
    }
    
    // Display notifications
    void displayNotifications() const {
        if (notifications.size() == 0) {
            std::cout << "No notifications.\n";
            return;
        }
        
        std::cout << "\nNotifications:\n";
        notifications.displayAll();
    }
    
    // Main menu
    void displayMenu() {
        std::cout << "\nUniversity Student Management System\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Add Faculty\n";
        std::cout << "3. Add Course\n";
        std::cout << "4. Enroll Student in Course\n";
        std::cout << "5. Drop Student from Course\n";
        std::cout << "6. Add/Update Grade\n";
        std::cout << "7. Display All Students\n";
        std::cout << "8. Display All Faculty\n";
        std::cout << "9. Display All Courses\n";
        std::cout << "10. Display Students in a Course\n";
        std::cout << "11. Display Courses for a Student\n";
        std::cout << "12. Display Student GPA Report\n";
        std::cout << "13. Search Students by Name\n";
        std::cout << "14. Search Courses by Title\n";
        std::cout << "15. View Notifications\n";
        std::cout << "16. Exit\n";
    }
    
    void run() {
        int choice;
        bool running = true;
       // Load data from files at the start 
        while (running) {
            displayMenu();
            choice = getValidIntInput("Enter your choice: ", 1, 16);
            
            try {
                switch (choice) {
                    case 1: addStudent(); break;
                    case 2: addFaculty(); break;
                    case 3: addCourse(); break;
                    case 4: enrollStudentInCourse(); break;
                    case 5: dropStudentFromCourse(); break;
                    case 6: addGrade(); break;
                    case 7: displayAllStudents(); break;
                    case 8: displayAllFaculty(); break;
                    case 9: displayAllCourses(); break;
                    case 10: displayStudentsInCourse(); break;
                    case 11: displayCoursesForStudent(); break;
                    case 12: displayStudentGPAReport(); break;
                    case 13: searchStudentsByName(); break;
                    case 14: searchCoursesByTitle(); break;
                    case 15: displayNotifications(); break;
                    case 16: running = false; break;
                    default: std::cout << "Invalid choice. Please try again.\n";
                }
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
                notifications.addNotification(std::string("Error: ") + e.what());
            }
        }
        
        std::cout << "Exiting system. Goodbye!\n";
    }
};
// 
int main() {
    UniversityManagementSystem ums;
    ums.run();
    return 0;
}
