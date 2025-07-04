#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <stdexcept>
#include <fstream>
#include <limits>
#include <iomanip>
#include <cstdlib>
#include <filesystem>
#include <ctime>

using namespace std;

// ====================== Exception Classes ======================
class DuplicateIdException : public runtime_error {
public:
    DuplicateIdException(const string& id) : runtime_error("Duplicate ID found: " + id) {}
};

class NotFoundException : public runtime_error {
public:
    NotFoundException(const string& type, const string& id) 
        : runtime_error(type + " not found with ID: " + id) {}
};

class InvalidInputException : public runtime_error {
public:
    InvalidInputException(const string& message) 
        : runtime_error("Invalid input: " + message) {}
};

class EnrollmentException : public runtime_error {
public:
    EnrollmentException(const string& message) 
        : runtime_error("Enrollment error: " + message) {}
};

// ====================== Base Person Class ======================
class Person {
protected:
    string name;
    string id;
    int age;

public:
    Person(const string& name, const string& id, int age) 
        : name(name), id(id), age(age) {}

    virtual ~Person() = default;

    string getName() const { return name; }
    string getId() const { return id; }
    int getAge() const { return age; }

    void setName(const string& name) { this->name = name; }
    void setId(const string& id) { this->id = id; }
    void setAge(int age) { this->age = age; }

    virtual void display() const {
        cout << "ID: " << id << "\nName: " << name << "\nAge: " << age << endl;
    }
};

// ====================== Course Class ======================
class Course {
private:
    string courseCode;
    string title;
    Person* facultyInCharge;
    map<string, Person*> enrolledStudents;

public:
    Course(const string& courseCode, const string& title) 
        : courseCode(courseCode), title(title), facultyInCharge(nullptr) {}

    string getCourseCode() const { return courseCode; }
    string getTitle() const { return title; }
    Person* getFacultyInCharge() const { return facultyInCharge; }

    void assignFaculty(Person* faculty) {
        if (facultyInCharge == faculty) {
            throw EnrollmentException("Faculty already in charge of this course");
        }
        facultyInCharge = faculty;
    }

    void removeFaculty() {
        facultyInCharge = nullptr;
    }

    void enrollStudent(Person* student) {
        if (enrolledStudents.find(student->getId()) != enrolledStudents.end()) {
            throw EnrollmentException("Student already enrolled in this course");
        }
        enrolledStudents[student->getId()] = student;
    }

    void dropStudent(const string& studentId) {
        if (enrolledStudents.find(studentId) == enrolledStudents.end()) {
            throw NotFoundException("Enrollment", studentId);
        }
        enrolledStudents.erase(studentId);
    }

    const map<string, Person*>& getEnrolledStudents() const { return enrolledStudents; }

    void display() const {
        cout << "Course Code: " << courseCode << "\nTitle: " << title << endl;
        if (facultyInCharge) {
            cout << "Faculty In Charge: " << facultyInCharge->getName() << endl;
        } else {
            cout << "Faculty In Charge: Not assigned" << endl;
        }
        cout << "Enrolled Students: " << enrolledStudents.size() << endl;
    }
};

// ====================== Student Class ======================
class Student : public Person {
private:
    double gpa;
    map<string, Course*> enrolledCourses;

public:
    Student(const string& name, const string& id, int age) 
        : Person(name, id, age), gpa(0.0) {}

    double getGPA() const { return gpa; }
    void updateGPA(double newGpa) { gpa = newGpa; }

    void enrollCourse(Course* course) {
        if (!course) {
            throw invalid_argument("Invalid course pointer");
        }
        if (enrolledCourses.find(course->getCourseCode()) != enrolledCourses.end()) {
            throw EnrollmentException("Student already enrolled in this course");
        }
        enrolledCourses[course->getCourseCode()] = course;
    }

    void dropCourse(const string& courseId) {
        if (enrolledCourses.find(courseId) == enrolledCourses.end()) {
            throw NotFoundException("Enrollment", courseId);
        }
        enrolledCourses.erase(courseId);
    }

    const map<string, Course*>& getEnrolledCourses() const { return enrolledCourses; }

    void display() const override {
        Person::display();
        cout << "GPA: " << fixed << setprecision(2) << gpa << endl;
    }
};

// ====================== Faculty Class ======================
class Faculty : public Person {
private:
    string specialization;
    vector<Course*> coursesTeaching;

public:
    Faculty(const string& name, const string& id, int age, const string& specialization)
        : Person(name, id, age), specialization(specialization) {}

    string getSpecialization() const { return specialization; }
    void setSpecialization(const string& specialization) { 
        this->specialization = specialization; 
    }

    void assignCourse(Course* course) {
        if (!course) {
            throw invalid_argument("Invalid course pointer");
        }
        if (find(coursesTeaching.begin(), coursesTeaching.end(), course) != coursesTeaching.end()) {
            throw EnrollmentException("Faculty already assigned to this course");
        }
        coursesTeaching.push_back(course);
    }

    void removeCourse(const string& courseId) {
        auto it = find_if(coursesTeaching.begin(), coursesTeaching.end(),
            [&courseId](Course* c) { return c && c->getCourseCode() == courseId; });
        
        if (it == coursesTeaching.end()) {
            throw NotFoundException("Course assignment", courseId);
        }
        
        coursesTeaching.erase(it);
    }

    const vector<Course*>& getCoursesTeaching() const { return coursesTeaching; }

    void display() const override {
        Person::display();
        cout << "Specialization: " << specialization << endl;
        if (!coursesTeaching.empty()) {
            cout << "Courses Teaching:\n";
            for (const auto& course : coursesTeaching) {
                if (course) {
                    cout << "- " << course->getCourseCode() << ": " << course->getTitle() << endl;
                }
            }
        }
    }
};

// ====================== Gradebook Class ======================
enum class Grade { A, B, C, D, F };

class Gradebook {
private:
    map<string, map<string, Grade>> grades;
    
    static double gradeToPoints(Grade grade) {
        switch (grade) {
            case Grade::A: return 4.0;
            case Grade::B: return 3.0;
            case Grade::C: return 2.0;
            case Grade::D: return 1.0;
            case Grade::F: return 0.0;
            default: return 0.0;
        }
    }
    
public:
    void addGrade(const string& studentId, const string& courseId, Grade grade) {
        grades[studentId][courseId] = grade;
    }
    
    void updateGrade(const string& studentId, const string& courseId, Grade newGrade) {
        if (grades.find(studentId) == grades.end() || 
            grades[studentId].find(courseId) == grades[studentId].end()) {
            throw NotFoundException("Grade entry", studentId + " in " + courseId);
        }
        grades[studentId][courseId] = newGrade;
    }
    
    void removeGrade(const string& studentId, const string& courseId) {
        if (grades.find(studentId) != grades.end()) {
            grades[studentId].erase(courseId);
            if (grades[studentId].empty()) {
                grades.erase(studentId);
            }
        }
    }
    
    Grade getGrade(const string& studentId, const string& courseId) const {
        auto studentIt = grades.find(studentId);
        if (studentIt == grades.end()) {
            throw NotFoundException("Grade entry", studentId);
        }
        
        auto courseIt = studentIt->second.find(courseId);
        if (courseIt == studentIt->second.end()) {
            throw NotFoundException("Grade entry", courseId);
        }
        
        return courseIt->second;
    }
    
    double calculateGPA(const string& studentId) const {
        auto studentIt = grades.find(studentId);
        if (studentIt == grades.end()) {
            return 0.0;
        }
        
        double totalPoints = 0.0;
        int count = 0;
        
        for (const auto& courseGrade : studentIt->second) {
            totalPoints += gradeToPoints(courseGrade.second);
            count++;
        }
        
        return count > 0 ? totalPoints / count : 0.0;
    }
    
    void generateStudentReport(const string& studentId) const {
        auto studentIt = grades.find(studentId);
        if (studentIt == grades.end()) {
            cout << "No grade records found for this student.\n";
            return;
        }
        
        for (const auto& courseGrade : studentIt->second) {
            cout << "Course: " << courseGrade.first << " - Grade: ";
            switch (courseGrade.second) {
                case Grade::A: cout << "A"; break;
                case Grade::B: cout << "B"; break;
                case Grade::C: cout << "C"; break;
                case Grade::D: cout << "D"; break;
                case Grade::F: cout << "F"; break;
            }
            cout << " (" << gradeToPoints(courseGrade.second) << " points)\n";
        }
    }
    
    void generateCourseReport(const string& courseId) const {
        bool found = false;
        
        for (const auto& studentGrades : grades) {
            auto courseIt = studentGrades.second.find(courseId);
            if (courseIt != studentGrades.second.end()) {
                found = true;
                cout << "Student: " << studentGrades.first << " - Grade: ";
                switch (courseIt->second) {
                    case Grade::A: cout << "A"; break;
                    case Grade::B: cout << "B"; break;
                    case Grade::C: cout << "C"; break;
                    case Grade::D: cout << "D"; break;
                    case Grade::F: cout << "F"; break;
                }
                cout << endl;
            }
        }
        
        if (!found) {
            cout << "No grade records found for this course.\n";
        }
    }
    
    const map<string, map<string, Grade>>& getAllGrades() const {
        return grades;
    }
};

// ====================== Notification Class ======================
template<typename T>
class Notification {
    T message;
    string timestamp;
public:
    Notification(const T& msg) : message(msg) {
        time_t now = time(nullptr);
        timestamp = ctime(&now);
        timestamp.pop_back(); // Remove newline
    }
    
    void display() const {
        cout << "[" << timestamp << "] " << message << endl;
    }
};

// ====================== USMS Class ======================
class USMS {
private:
    map<string, Student*> students;
    map<string, Faculty*> faculty;
    map<string, Course*> courses;
    Gradebook gradebook;
    vector<Notification<string>> notifications;
    
    void loadData() {
        system("mkdir -p data");
        
        try {
            // Load students
            ifstream studentFile("data/students.txt");
            if (studentFile) {
                string line;
                while (getline(studentFile, line)) { // Name
                    string name = line;
                    if (!getline(studentFile, line)) break; // ID
                    string id = line;
                    if (!getline(studentFile, line)) break; // Age
                    int age = stoi(line);
                    students[id] = new Student(name, id, age);
                }
                studentFile.close();
            }
            
            // Load faculty
            ifstream facultyFile("data/faculty.txt");
            if (facultyFile) {
                string line;
                while (getline(facultyFile, line)) { // Name
                    string name = line;
                    if (!getline(facultyFile, line)) break; // ID
                    string id = line;
                    if (!getline(facultyFile, line)) break; // Age
                    int age = stoi(line);
                    if (!getline(facultyFile, line)) break; // Specialization
                    string specialization = line;
                    faculty[id] = new Faculty(name, id, age, specialization);
                }
                facultyFile.close();
            }
            
            // Load courses
            ifstream courseFile("data/courses.txt");
            if (courseFile) {
                string line;
                while (getline(courseFile, line)) { // Course code
                    string code = line;
                    if (!getline(courseFile, line)) break; // Title
                    string title = line;
                    courses[code] = new Course(code, title);
                }
                courseFile.close();
            }
            
            // Load enrollments
            ifstream enrollFile("data/enrollments.txt");
            if (enrollFile) {
                string studentId, courseCode;
                while (enrollFile >> studentId >> courseCode) {
                    if (students.find(studentId) != students.end() && 
                        courses.find(courseCode) != courses.end()) {
                        students[studentId]->enrollCourse(courses[courseCode]);
                        courses[courseCode]->enrollStudent(students[studentId]);
                    }
                }
                enrollFile.close();
            }
            
            // Load faculty assignments
            ifstream assignFile("data/assignments.txt");
            if (assignFile) {
                string facultyId, courseCode;
                while (assignFile >> facultyId >> courseCode) {
                    if (faculty.find(facultyId) != faculty.end() && 
                        courses.find(courseCode) != courses.end()) {
                        courses[courseCode]->assignFaculty(faculty[facultyId]);
                        faculty[facultyId]->assignCourse(courses[courseCode]);
                    }
                }
                assignFile.close();
            }
            
            // Load grades
            ifstream gradeFile("data/grades.txt");
            if (gradeFile) {
                string studentId, courseCode, gradeStr;
                while (gradeFile >> studentId >> courseCode >> gradeStr) {
                    Grade grade;
                    switch (gradeStr[0]) {
                        case 'A': grade = Grade::A; break;
                        case 'B': grade = Grade::B; break;
                        case 'C': grade = Grade::C; break;
                        case 'D': grade = Grade::D; break;
                        case 'F': grade = Grade::F; break;
                        default: continue;
                    }
                    gradebook.addGrade(studentId, courseCode, grade);
                    if (students.find(studentId) != students.end()) {
                        students[studentId]->updateGPA(gradebook.calculateGPA(studentId));
                    }
                }
                gradeFile.close();
            }
            
            notifications.emplace_back("System data loaded successfully");
        } catch (const exception& e) {
            cerr << "Warning: Error loading data files: " << e.what() << "\n";
        }
    }
    
    void saveData() {
        system("mkdir -p data");
        
        try {
            // Save students
            ofstream studentFile("data/students.txt");
            for (const auto& s : students) {
                if (s.second) {
                    studentFile << s.second->getName() << "\n" 
                              << s.second->getId() << "\n" 
                              << s.second->getAge() << "\n";
                }
            }
            studentFile.close();
            
            // Save faculty
            ofstream facultyFile("data/faculty.txt");
            for (const auto& f : faculty) {
                if (f.second) {
                    facultyFile << f.second->getName() << "\n" 
                               << f.second->getId() << "\n" 
                               << f.second->getAge() << "\n" 
                               << f.second->getSpecialization() << "\n";
                }
            }
            facultyFile.close();
            
            // Save courses
            ofstream courseFile("data/courses.txt");
            for (const auto& c : courses) {
                if (c.second) {
                    courseFile << c.second->getCourseCode() << "\n" 
                             << c.second->getTitle() << "\n";
                }
            }
            courseFile.close();
            
            // Save enrollments
            ofstream enrollFile("data/enrollments.txt");
            for (const auto& s : students) {
                if (s.second) {
                    const auto& enrolledCourses = s.second->getEnrolledCourses();
                    for (const auto& c : enrolledCourses) {
                        if (c.second) {
                            enrollFile << s.first << " " << c.first << "\n";
                        }
                    }
                }
            }
            enrollFile.close();
            
            // Save faculty assignments
            ofstream assignFile("data/assignments.txt");
            for (const auto& c : courses) {
                if (c.second && c.second->getFacultyInCharge()) {
                    assignFile << c.second->getFacultyInCharge()->getId() << " " 
                             << c.first << "\n";
                }
            }
            assignFile.close();
            
            // Save grades
            ofstream gradeFile("data/grades.txt");
            const auto& allGrades = gradebook.getAllGrades();
            for (const auto& studentGrades : allGrades) {
                for (const auto& courseGrade : studentGrades.second) {
                    char gradeChar;
                    switch (courseGrade.second) {
                        case Grade::A: gradeChar = 'A'; break;
                        case Grade::B: gradeChar = 'B'; break;
                        case Grade::C: gradeChar = 'C'; break;
                        case Grade::D: gradeChar = 'D'; break;
                        case Grade::F: gradeChar = 'F'; break;
                    }
                    gradeFile << studentGrades.first << " " 
                             << courseGrade.first << " " 
                             << gradeChar << "\n";
                }
            }
            gradeFile.close();
            
            notifications.emplace_back("System data saved successfully");
        } catch (const exception& e) {
            cerr << "Error saving data: " << e.what() << "\n";
        }
    }
    
    template<typename T>
    void displayAll(const map<string, T*>& items) const {
        if (items.empty()) {
            cout << "No records found.\n";
            return;
        }
        
        for (const auto& pair : items) {
            if (pair.second) {
                pair.second->display();
                cout << "------------------------\n";
            }
        }
    }
    
    void studentManagementMenu();
    void facultyManagementMenu();
    void courseManagementMenu();
    void enrollmentManagementMenu();
    void gradeManagementMenu();
    void reportsMenu();
    
public:
    USMS() {
        loadData();
        notifications.emplace_back("System initialized");
    }
    
    ~USMS() {
        for (auto& s : students) {
            if (s.second) {
                delete s.second;
                s.second = nullptr;
            }
        }
        students.clear();
        
        for (auto& f : faculty) {
            if (f.second) {
                delete f.second;
                f.second = nullptr;
            }
        }
        faculty.clear();
        
        for (auto& c : courses) {
            if (c.second) {
                delete c.second;
                c.second = nullptr;
            }
        }
        courses.clear();
        
        notifications.emplace_back("System shutdown");
    }
    
    void addStudent(const string& name, const string& id, int age) {
        if (students.find(id) != students.end()) {
            throw DuplicateIdException(id);
        }
        students[id] = new Student(name, id, age);
        notifications.emplace_back("Added new student: " + name);
    }
    
    void removeStudent(const string& id) {
        auto it = students.find(id);
        if (it == students.end()) {
            throw NotFoundException("Student", id);
        }
        
        for (auto& coursePair : courses) {
            if (coursePair.second) {
                try {
                    coursePair.second->dropStudent(id);
                } catch (...) {}
            }
        }
        
        for (auto& coursePair : courses) {
            if (coursePair.second) {
                try {
                    gradebook.removeGrade(id, coursePair.first);
                } catch (...) {}
            }
        }
        
        delete it->second;
        students.erase(it);
        notifications.emplace_back("Removed student ID: " + id);
    }
    
    Student* getStudent(const string& id) const {
        auto it = students.find(id);
        return it != students.end() ? it->second : nullptr;
    }
    
    void displayAllStudents() const {
        displayAll(students);
    }
    
    void addFaculty(const string& name, const string& id, int age, 
                    const string& specialization) {
        if (faculty.find(id) != faculty.end()) {
            throw DuplicateIdException(id);
        }
        faculty[id] = new Faculty(name, id, age, specialization);
        notifications.emplace_back("Added new faculty: " + name);
    }
    
    void removeFaculty(const string& id) {
        auto it = faculty.find(id);
        if (it == faculty.end()) {
            throw NotFoundException("Faculty", id);
        }
        
        for (auto& coursePair : courses) {
            if (coursePair.second && coursePair.second->getFacultyInCharge() == it->second) {
                coursePair.second->removeFaculty();
            }
        }
        
        delete it->second;
        faculty.erase(it);
        notifications.emplace_back("Removed faculty ID: " + id);
    }
    
    Faculty* getFaculty(const string& id) const {
        auto it = faculty.find(id);
        return it != faculty.end() ? it->second : nullptr;
    }
    
    void displayAllFaculty() const {
        displayAll(faculty);
    }
    
    void addCourse(const string& courseCode, const string& title) {
        if (courses.find(courseCode) != courses.end()) {
            throw DuplicateIdException(courseCode);
        }
        courses[courseCode] = new Course(courseCode, title);
        notifications.emplace_back("Added new course: " + title);
    }
    
    void removeCourse(const string& courseCode) {
        auto it = courses.find(courseCode);
        if (it == courses.end()) {
            throw NotFoundException("Course", courseCode);
        }
        
        for (auto& studentPair : students) {
            if (studentPair.second) {
                try {
                    studentPair.second->dropCourse(courseCode);
                } catch (...) {}
            }
        }
        
        for (auto& studentPair : students) {
            if (studentPair.second) {
                try {
                    gradebook.removeGrade(studentPair.first, courseCode);
                } catch (...) {}
            }
        }
        
        delete it->second;
        courses.erase(it);
        notifications.emplace_back("Removed course: " + courseCode);
    }
    
    Course* getCourse(const string& courseCode) const {
        auto it = courses.find(courseCode);
        return it != courses.end() ? it->second : nullptr;
    }
    
    void displayAllCourses() const {
        displayAll(courses);
    }
    
    void enrollStudentInCourse(const string& studentId, const string& courseCode) {
        Student* student = getStudent(studentId);
        Course* course = getCourse(courseCode);
        
        if (!student) throw NotFoundException("Student", studentId);
        if (!course) throw NotFoundException("Course", courseCode);
        
        course->enrollStudent(student);
        student->enrollCourse(course);
        notifications.emplace_back("Enrolled student " + studentId + " in course " + courseCode);
    }
    
    void dropStudentFromCourse(const string& studentId, const string& courseCode) {
        Student* student = getStudent(studentId);
        Course* course = getCourse(courseCode);
        
        if (!student) throw NotFoundException("Student", studentId);
        if (!course) throw NotFoundException("Course", courseCode);
        
        course->dropStudent(studentId);
        student->dropCourse(courseCode);
        gradebook.removeGrade(studentId, courseCode);
        
        double newGpa = gradebook.calculateGPA(studentId);
        student->updateGPA(newGpa);
        notifications.emplace_back("Dropped student " + studentId + " from course " + courseCode);
    }
    
    void addGrade(const string& studentId, const string& courseCode, Grade grade) {
        if (students.find(studentId) == students.end()) {
            throw NotFoundException("Student", studentId);
        }
        
        if (courses.find(courseCode) == courses.end()) {
            throw NotFoundException("Course", courseCode);
        }
        
        Course* course = courses[courseCode];
        if (course->getEnrolledStudents().find(studentId) == course->getEnrolledStudents().end()) {
            throw EnrollmentException("Student not enrolled in the course");
        }
        
        gradebook.addGrade(studentId, courseCode, grade);
        
        double newGpa = gradebook.calculateGPA(studentId);
        students[studentId]->updateGPA(newGpa);
        notifications.emplace_back("Added grade for student " + studentId + " in course " + courseCode);
    }
    
    void updateGrade(const string& studentId, const string& courseCode, Grade newGrade) {
        gradebook.updateGrade(studentId, courseCode, newGrade);
        
        double newGpa = gradebook.calculateGPA(studentId);
        students[studentId]->updateGPA(newGpa);
        notifications.emplace_back("Updated grade for student " + studentId + " in course " + courseCode);
    }
    
    void removeGrade(const string& studentId, const string& courseCode) {
        gradebook.removeGrade(studentId, courseCode);
        
        double newGpa = gradebook.calculateGPA(studentId);
        students[studentId]->updateGPA(newGpa);
        notifications.emplace_back("Removed grade for student " + studentId + " in course " + courseCode);
    }
    
    void generateStudentReport(const string& studentId) const {
        if (students.find(studentId) == students.end()) {
            throw NotFoundException("Student", studentId);
        }
        
        cout << "\nStudent Report for ID: " << studentId << "\n";
        students.at(studentId)->display();
        
        cout << "\nEnrolled Courses:\n";
        displayStudentCourses(studentId);
        
        cout << "\nGrade Summary:\n";
        gradebook.generateStudentReport(studentId);
        
        cout << "\nOverall GPA: " << fixed << setprecision(2) 
             << students.at(studentId)->getGPA() << "\n";
    }
    
    void generateCourseReport(const string& courseCode) const {
        if (courses.find(courseCode) == courses.end()) {
            throw NotFoundException("Course", courseCode);
        }
        
        cout << "\nCourse Report for " << courseCode << "\n";
        courses.at(courseCode)->display();
        
        cout << "\nStudent Grades:\n";
        gradebook.generateCourseReport(courseCode);
    }
    
    void displayStudentCourses(const string& studentId) const {
        Student* student = getStudent(studentId);
        if (!student) {
            throw NotFoundException("Student", studentId);
        }
        
        const auto& enrolledCourses = student->getEnrolledCourses();
        
        if (enrolledCourses.empty()) {
            cout << "Student is not enrolled in any courses.\n";
            return;
        }
        
        for (const auto& course : enrolledCourses) {
            if (course.second) {
                cout << course.second->getCourseCode() << " - " 
                     << course.second->getTitle() << endl;
            }
        }
    }
    
    void displayCourseStudents(const string& courseCode) const {
        Course* course = getCourse(courseCode);
        if (!course) {
            throw NotFoundException("Course", courseCode);
        }
        
        const auto& enrolledStudents = course->getEnrolledStudents();
        
        if (enrolledStudents.empty()) {
            cout << "No students enrolled in this course.\n";
            return;
        }
        
        for (const auto& student : enrolledStudents) {
            if (student.second) {
                cout << student.second->getId() << " - " 
                     << student.second->getName() << endl;
            }
        }
    }
    
    void displayMainMenu() {
        cout << "\nUniversity Student Management System\n";
        cout << "1. Student Management\n";
        cout << "2. Faculty Management\n";
        cout << "3. Course Management\n";
        cout << "4. Enrollment Management\n";
        cout << "5. Grade Management\n";
        cout << "6. Reports\n";
        cout << "7. System Notifications\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
    }
    
    void run() {
        int choice;
        bool running = true;
        
        while (running) {
            try {
                displayMainMenu();
                cin >> choice;
                
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw InvalidInputException("Please enter a number");
                }
                
                switch (choice) {
                    case 1: studentManagementMenu(); break;
                    case 2: facultyManagementMenu(); break;
                    case 3: courseManagementMenu(); break;
                    case 4: enrollmentManagementMenu(); break;
                    case 5: gradeManagementMenu(); break;
                    case 6: reportsMenu(); break;
                    case 7:
                        cout << "\nSystem Notifications:\n";
                        for (const auto& note : notifications) {
                            note.display();
                        }
                        break;
                    case 8: 
                        saveData();
                        running = false; 
                        cout << "Save data and Exiting...\n";
                        break;
                    default:
                        cout << "Invalid choice. Please try again.\n";
                }
            } catch (const exception& e) {
                cerr << "Error: " << e.what() << "\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }
};

// ====================== Menu Implementations ======================
void USMS::studentManagementMenu() {
    int choice;
    string name, id;
    int age;
    
    do {
        cout << "\nStudent Management\n";
        cout << "1. Add Student\n";
        cout << "2. Remove Student\n";
        cout << "3. View All Students\n";
        cout << "4. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        try {
            switch (choice) {
                case 1:
                    cout << "Enter student name: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter student ID: ";
                    cin >> id;
                    cout << "Enter student age: ";
                    cin >> age;
                    addStudent(name, id, age);
                    cout << "Student added successfully.\n";
                    break;
                case 2:
                    cout << "Enter student ID to remove: ";
                    cin >> id;
                    removeStudent(id);
                    cout << "Student removed successfully.\n";
                    break;
                case 3:
                    displayAllStudents();
                    break;
                case 4:
                    return;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << "\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (true);
}

void USMS::facultyManagementMenu() {
    int choice;
    string name, id, specialization;
    int age;
    
    do {
        cout << "\nFaculty Management\n";
        cout << "1. Add Faculty\n";
        cout << "2. Remove Faculty\n";
        cout << "3. View All Faculty\n";
        cout << "4. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        try {
            switch (choice) {
                case 1:
                    cout << "Enter faculty name: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter faculty ID: ";
                    cin >> id;
                    cout << "Enter faculty age: ";
                    cin >> age;
                    cout << "Enter specialization: ";
                    cin.ignore();
                    getline(cin, specialization);
                    addFaculty(name, id, age, specialization);
                    cout << "Faculty added successfully.\n";
                    break;
                case 2:
                    cout << "Enter faculty ID to remove: ";
                    cin >> id;
                    removeFaculty(id);
                    cout << "Faculty removed successfully.\n";
                    break;
                case 3:
                    displayAllFaculty();
                    break;
                case 4:
                    return;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << "\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (true);
}

void USMS::courseManagementMenu() {
    int choice;
    string code, title, facultyId;
    
    do {
        cout << "\nCourse Management\n";
        cout << "1. Add Course\n";
        cout << "2. Remove Course\n";
        cout << "3. Assign Faculty to Course\n";
        cout << "4. View All Courses\n";
        cout << "5. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        try {
            switch (choice) {
                case 1:
                    cout << "Enter course code: ";
                    cin >> code;
                    cout << "Enter course title: ";
                    cin.ignore();
                    getline(cin, title);
                    addCourse(code, title);
                    cout << "Course added successfully.\n";
                    break;
                case 2:
                    cout << "Enter course code to remove: ";
                    cin >> code;
                    removeCourse(code);
                    cout << "Course removed successfully.\n";
                    break;
                case 3: {
                    cout << "Enter course code: ";
                    cin >> code;
                    cout << "Enter faculty ID: ";
                    cin >> facultyId;
                    
                    Course* course = getCourse(code);
                    Faculty* facultyMember = getFaculty(facultyId);
                    
                    if (!course) throw NotFoundException("Course", code);
                    if (!facultyMember) throw NotFoundException("Faculty", facultyId);
                    
                    // Check if faculty is already assigned to this course
                    if (course->getFacultyInCharge() == facultyMember) {
                        cout << "This faculty is already assigned to this course.\n";
                        break;
                    }
                    
                    // Check if faculty is assigned to another course
                    bool assignedToOtherCourse = false;
                    for (const auto& c : courses) {
                        if (c.second && c.second->getFacultyInCharge() == facultyMember && c.second != course) {
                            assignedToOtherCourse = true;
                            break;
                        }
                    }
                    
                    if (assignedToOtherCourse) {
                        cout << "This faculty is already assigned to another course.\n";
                        cout << "Do you want to reassign them to this course? (y/n): ";
                        char confirm;
                        cin >> confirm;
                        if (tolower(confirm) == 'y') {
                            // Remove from other course first
                            for (auto& c : courses) {
                                if (c.second && c.second->getFacultyInCharge() == facultyMember) {
                                    c.second->removeFaculty();
                                }
                            }
                            // Assign to new course
                            course->assignFaculty(facultyMember);
                            facultyMember->assignCourse(course);
                            cout << "Faculty reassigned successfully.\n";
                        } else {
                            cout << "Assignment cancelled.\n";
                        }
                    } else {
                        course->assignFaculty(facultyMember);
                        facultyMember->assignCourse(course);
                        cout << "Faculty assigned successfully.\n";
                    }
                    break;
                }
                case 4:
                    displayAllCourses();
                    break;
                case 5:
                    return;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << "\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (true);
}

void USMS::enrollmentManagementMenu() {
    int choice;
    string studentId, courseCode;
    
    do {
        cout << "\nEnrollment Management\n";
        cout << "1. Enroll Student in Course\n";
        cout << "2. Drop Student from Course\n";
        cout << "3. View Students in Course\n";
        cout << "4. View Courses for Student\n";
        cout << "5. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        try {
            switch (choice) {
                case 1:
                    cout << "Enter student ID: ";
                    cin >> studentId;
                    cout << "Enter course code: ";
                    cin >> courseCode;
                    enrollStudentInCourse(studentId, courseCode);
                    cout << "Enrollment successful.\n";
                    break;
                case 2:
                    cout << "Enter student ID: ";
                    cin >> studentId;
                    cout << "Enter course code: ";
                    cin >> courseCode;
                    dropStudentFromCourse(studentId, courseCode);
                    cout << "Student dropped successfully.\n";
                    break;
                case 3:
                    cout << "Enter course code: ";
                    cin >> courseCode;
                    displayCourseStudents(courseCode);
                    break;
                case 4:
                    cout << "Enter student ID: ";
                    cin >> studentId;
                    displayStudentCourses(studentId);
                    break;
                case 5:
                    return;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << "\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (true);
}

void USMS::gradeManagementMenu() {
    int choice;
    string studentId, courseCode;
    char gradeChar;
    Grade grade;
    
    do {
        cout << "\nGrade Management\n";
        cout << "1. Add Grade\n";
        cout << "2. Update Grade\n";
        cout << "3. Remove Grade\n";
        cout << "4. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        try {
            switch (choice) {
                case 1:
                case 2:
                    cout << "Enter student ID: ";
                    cin >> studentId;
                    cout << "Enter course code: ";
                    cin >> courseCode;
                    cout << "Enter grade (A, B, C, D, F): ";
                    cin >> gradeChar;
                    
                    switch (toupper(gradeChar)) {
                        case 'A': grade = Grade::A; break;
                        case 'B': grade = Grade::B; break;
                        case 'C': grade = Grade::C; break;
                        case 'D': grade = Grade::D; break;
                        case 'F': grade = Grade::F; break;
                        default:
                            throw InvalidInputException("Invalid grade. Use A, B, C, D, or F");
                    }
                    
                    if (choice == 1) {
                        addGrade(studentId, courseCode, grade);
                        cout << "Grade added successfully.\n";
                    } else {
                        updateGrade(studentId, courseCode, grade);
                        cout << "Grade updated successfully.\n";
                    }
                    break;
                case 3:
                    cout << "Enter student ID: ";
                    cin >> studentId;
                    cout << "Enter course code: ";
                    cin >> courseCode;
                    removeGrade(studentId, courseCode);
                    cout << "Grade removed successfully.\n";
                    break;
                case 4:
                    return;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << "\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (true);
}

void USMS::reportsMenu() {
    int choice;
    string id;
    
    do {
        cout << "\nReports\n";
        cout << "1. Student Report\n";
        cout << "2. Course Report\n";
        cout << "3. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        try {
            switch (choice) {
                case 1:
                    cout << "Enter student ID: ";
                    cin >> id;
                    generateStudentReport(id);
                    break;
                case 2:
                    cout << "Enter course code: ";
                    cin >> id;
                    generateCourseReport(id);
                    break;
                case 3:
                    return;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << "\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (true);
}

// ====================== Main Function ======================
int main() {
    USMS system;
    system.run();
    return 0;
}