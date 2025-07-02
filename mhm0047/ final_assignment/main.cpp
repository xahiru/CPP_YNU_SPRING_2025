#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stdexcept>
#include <limits>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

// Base class Person
class Person {
protected:
    string name;
    string id;
    int age;

public:
    Person(const string& name = "", const string& id = "", int age = 0) 
        : name(name), id(id), age(age) {}

    virtual ~Person() {}

    // Getters
    string getName() const { return name; }
    string getId() const { return id; }
    int getAge() const { return age; }

    // Setters
    void setName(const string& name) { this->name = name; }
    void setId(const string& id) { this->id = id; }
    void setAge(int age) { this->age = age; }

    virtual void display() const {
        cout << "Name: " << name << "\nID: " << id << "\nAge: " << age << endl;
    }

    bool operator==(const Person& other) const {
        return id == other.id;
    }

    bool operator!=(const Person& other) const {
        return !(*this == other);
    }

    friend ostream& operator<<(ostream& os, const Person& person);
};

ostream& operator<<(ostream& os, const Person& person) {
    os << "Name: " << person.name << ", ID: " << person.id << ", Age: " << person.age;
    return os;
}

// Derived class Student
class Student : public Person {
private:
    double gpa;
    vector<string> enrolledCourses;

public:
    Student(const string& name = "", const string& id = "", int age = 0, double gpa = 0.0)
        : Person(name, id, age), gpa(gpa) {}

    double getGpa() const { return gpa; }
    const vector<string>& getEnrolledCourses() const { return enrolledCourses; }

    void setGpa(double gpa) { this->gpa = gpa; }

    void enrollCourse(const string& courseCode) {
        if (find(enrolledCourses.begin(), enrolledCourses.end(), courseCode) == enrolledCourses.end()) {
            enrolledCourses.push_back(courseCode);
        }
    }

    void dropCourse(const string& courseCode) {
        auto it = find(enrolledCourses.begin(), enrolledCourses.end(), courseCode);
        if (it != enrolledCourses.end()) {
            enrolledCourses.erase(it);
        }
    }

    void display() const override {
        Person::display();
        cout << "GPA: " << fixed << setprecision(2) << gpa << endl;
        cout << "Enrolled Courses: ";
        for (const auto& course : enrolledCourses) {
            cout << course << " ";
        }
        cout << endl;
    }
};

// Derived class Faculty
class Faculty : public Person {
private:
    string specialization;

public:
    Faculty(const string& name = "", const string& id = "", int age = 0, const string& specialization = "")
        : Person(name, id, age), specialization(specialization) {}

    string getSpecialization() const { return specialization; }

    void setSpecialization(const string& specialization) { this->specialization = specialization; }

    void display() const override {
        Person::display();
        cout << "Specialization: " << specialization << endl;
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
    Course(const string& code = "", const string& title = "", const string& facultyId = "")
        : code(code), title(title), facultyId(facultyId) {}

    // Standard getter for template compatibility
    string getId() const { return code; }
    
    string getCode() const { return code; }
    string getTitle() const { return title; }
    string getFacultyId() const { return facultyId; }
    const vector<string>& getEnrolledStudents() const { return enrolledStudents; }

    void setCode(const string& code) { this->code = code; }
    void setTitle(const string& title) { this->title = title; }
    void setFacultyId(const string& facultyId) { this->facultyId = facultyId; }

    void enrollStudent(const string& studentId) {
        if (find(enrolledStudents.begin(), enrolledStudents.end(), studentId) == enrolledStudents.end()) {
            enrolledStudents.push_back(studentId);
        }
    }

    void dropStudent(const string& studentId) {
        auto it = find(enrolledStudents.begin(), enrolledStudents.end(), studentId);
        if (it != enrolledStudents.end()) {
            enrolledStudents.erase(it);
        }
    }

    void display() const {
        cout << "Course Code: " << code << "\nTitle: " << title 
             << "\nFaculty ID: " << facultyId << endl;
        cout << "Enrolled Students: ";
        for (const auto& student : enrolledStudents) {
            cout << student << " ";
        }
        cout << endl;
    }
};

// Gradebook class
class Gradebook {
private:
    map<pair<string, string>, char> grades;

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
    void addGrade(const string& studentId, const string& courseCode, char grade) {
        grades[{studentId, courseCode}] = toupper(grade);
    }

    void removeGrade(const string& studentId, const string& courseCode) {
        grades.erase({studentId, courseCode});
    }

    char getGrade(const string& studentId, const string& courseCode) const {
        auto it = grades.find({studentId, courseCode});
        if (it != grades.end()) {
            return it->second;
        }
        return '\0';
    }

    double calculateGpa(const vector<string>& courseCodes, const string& studentId) const {
        double totalPoints = 0.0;
        int count = 0;

        for (const auto& courseCode : courseCodes) {
            char grade = getGrade(studentId, courseCode);
            if (grade != '\0') {
                totalPoints += gradeToPoints(grade);
                count++;
            }
        }

        return count > 0 ? totalPoints / count : 0.0;
    }

    map<string, char> getStudentGrades(const string& studentId) const {
        map<string, char> studentGrades;
        for (const auto& entry : grades) {
            if (entry.first.first == studentId) {
                studentGrades[entry.first.second] = entry.second;
            }
        }
        return studentGrades;
    }
};

// University Management System class
class UniversityManagementSystem {
private:
    vector<Student> students;
    vector<Faculty> faculty;
    vector<Course> courses;
    Gradebook gradebook;

    template<typename T>
    int findById(const vector<T>& items, const string& id) const {
        for (size_t i = 0; i < items.size(); ++i) {
            if (items[i].getId() == id) {
                return static_cast<int>(i);
            }
        }
        return -1;
    }

    template<typename T>
    void displayAll(const vector<T>& items) const {
        for (const auto& item : items) {
            item.display();
            cout << "---------------------" << endl;
        }
    }

    void saveToFile(const string& filename, const vector<Student>& data) const {
        ofstream file(filename);
        if (file.is_open()) {
            for (const auto& student : data) {
                file << student.getName() << "," << student.getId() << "," 
                     << student.getAge() << "," << student.getGpa() << "\n";
            }
            file.close();
        }
    }

    void loadFromFile(const string& filename, vector<Student>& data) {
        ifstream file(filename);
        if (file.is_open()) {
            data.clear();
            string line;
            while (getline(file, line)) {
                stringstream ss(line);
                string name, id, ageStr, gpaStr;
                getline(ss, name, ',');
                getline(ss, id, ',');
                getline(ss, ageStr, ',');
                getline(ss, gpaStr, ',');

                try {
                    int age = stoi(ageStr);
                    double gpa = stod(gpaStr);
                    data.emplace_back(name, id, age, gpa);
                } catch (...) {
                    // Skip malformed entries
                }
            }
            file.close();
        }
    }

public:
    // Student management
    void addStudent(const Student& student) {
        if (findById(students, student.getId()) != -1) {
            throw runtime_error("Student with this ID already exists.");
        }
        students.push_back(student);
    }

    void removeStudent(const string& studentId) {
        int index = findById(students, studentId);
        if (index == -1) {
            throw runtime_error("Student not found.");
        }
        
        for (auto& course : courses) {
            course.dropStudent(studentId);
        }
        
        auto enrolledCourses = students[index].getEnrolledCourses();
        for (const auto& courseCode : enrolledCourses) {
            gradebook.removeGrade(studentId, courseCode);
        }
        
        students.erase(students.begin() + index);
    }

    const Student* getStudent(const string& studentId) const {
        int index = findById(students, studentId);
        return index != -1 ? &students[index] : nullptr;
    }

    // Faculty management
    void addFaculty(const Faculty& facultyMember) {
        if (findById(faculty, facultyMember.getId()) != -1) {
            throw runtime_error("Faculty with this ID already exists.");
        }
        faculty.push_back(facultyMember);
    }

    void removeFaculty(const string& facultyId) {
        int index = findById(faculty, facultyId);
        if (index == -1) {
            throw runtime_error("Faculty not found.");
        }
        
        for (auto& course : courses) {
            if (course.getFacultyId() == facultyId) {
                course.setFacultyId("");
            }
        }
        
        faculty.erase(faculty.begin() + index);
    }

    const Faculty* getFaculty(const string& facultyId) const {
        int index = findById(faculty, facultyId);
        return index != -1 ? &faculty[index] : nullptr;
    }

    // Course management
    void addCourse(const Course& course) {
        if (findById(courses, course.getCode()) != -1) {
            throw runtime_error("Course with this code already exists.");
        }
        courses.push_back(course);
    }

    void removeCourse(const string& courseCode) {
        int index = findById(courses, courseCode);
        if (index == -1) {
            throw runtime_error("Course not found.");
        }
        
        for (auto& student : students) {
            student.dropCourse(courseCode);
        }
        
        for (const auto& studentId : courses[index].getEnrolledStudents()) {
            gradebook.removeGrade(studentId, courseCode);
        }
        
        courses.erase(courses.begin() + index);
    }

    const Course* getCourse(const string& courseCode) const {
        int index = findById(courses, courseCode);
        return index != -1 ? &courses[index] : nullptr;
    }

    // Enrollment management
    void enrollStudentInCourse(const string& studentId, const string& courseCode) {
        int studentIndex = findById(students, studentId);
        if (studentIndex == -1) {
            throw runtime_error("Student not found.");
        }
        
        int courseIndex = findById(courses, courseCode);
        if (courseIndex == -1) {
            throw runtime_error("Course not found.");
        }
        
        students[studentIndex].enrollCourse(courseCode);
        courses[courseIndex].enrollStudent(studentId);
    }

    void dropStudentFromCourse(const string& studentId, const string& courseCode) {
        int studentIndex = findById(students, studentId);
        if (studentIndex == -1) {
            throw runtime_error("Student not found.");
        }
        
        int courseIndex = findById(courses, courseCode);
        if (courseIndex == -1) {
            throw runtime_error("Course not found.");
        }
        
        students[studentIndex].dropCourse(courseCode);
        courses[courseIndex].dropStudent(studentId);
        gradebook.removeGrade(studentId, courseCode);
    }

    // Grade management
    void addGrade(const string& studentId, const string& courseCode, char grade) {
        if (getStudent(studentId) == nullptr) {
            throw runtime_error("Student not found.");
        }
        
        if (getCourse(courseCode) == nullptr) {
            throw runtime_error("Course not found.");
        }
        
        grade = toupper(grade);
        if (grade != 'A' && grade != 'B' && grade != 'C' && grade != 'D' && grade != 'F') {
            throw runtime_error("Invalid grade. Must be A, B, C, D, or F.");
        }
        
        gradebook.addGrade(studentId, courseCode, grade);
        
        int studentIndex = findById(students, studentId);
        if (studentIndex != -1) {
            double newGpa = gradebook.calculateGpa(students[studentIndex].getEnrolledCourses(), studentId);
            students[studentIndex].setGpa(newGpa);
        }
    }

    void removeGrade(const string& studentId, const string& courseCode) {
        gradebook.removeGrade(studentId, courseCode);
        
        int studentIndex = findById(students, studentId);
        if (studentIndex != -1) {
            double newGpa = gradebook.calculateGpa(students[studentIndex].getEnrolledCourses(), studentId);
            students[studentIndex].setGpa(newGpa);
        }
    }

    // Reporting functions
    void displayStudentReport(const string& studentId) const {
        const Student* student = getStudent(studentId);
        if (student == nullptr) {
            throw runtime_error("Student not found.");
        }
        
        cout << "\n=== Student Report ===" << endl;
        student->display();
        
        auto grades = gradebook.getStudentGrades(studentId);
        if (!grades.empty()) {
            cout << "\nGrades:" << endl;
            for (const auto& entry : grades) {
                cout << "Course: " << entry.first << ", Grade: " << entry.second << endl;
            }
        } else {
            cout << "\nNo grades recorded." << endl;
        }
    }

    void displayCourseReport(const string& courseCode) const {
        const Course* course = getCourse(courseCode);
        if (course == nullptr) {
            throw runtime_error("Course not found.");
        }
        
        cout << "\n=== Course Report ===" << endl;
        course->display();
        
        cout << "\nEnrolled Students:" << endl;
        for (const auto& studentId : course->getEnrolledStudents()) {
            const Student* student = getStudent(studentId);
            if (student != nullptr) {
                cout << "ID: " << studentId << ", Name: " << student->getName();
                char grade = gradebook.getGrade(studentId, courseCode);
                if (grade != '\0') {
                    cout << ", Grade: " << grade;
                }
                cout << endl;
            }
        }
    }

    void displayAllStudents() const {
        cout << "\n=== All Students ===" << endl;
        displayAll(students);
    }

    void displayAllFaculty() const {
        cout << "\n=== All Faculty ===" << endl;
        displayAll(faculty);
    }

    void displayAllCourses() const {
        cout << "\n=== All Courses ===" << endl;
        displayAll(courses);
    }

    // File operations
    void saveData() const {
        saveToFile("students.txt", students);
        // Similar functions would be needed for faculty and courses
    }

    void loadData() {
        loadFromFile("students.txt", students);
        // Similar functions would be needed for faculty and courses
    }
};

// [Rest of the helper functions and menu implementations remain exactly the same]
// [Include all the getInput functions and menu functions from the original code]
// [Include the main() function from the original code]

// Helper functions for user input
int getIntInput(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
        } else {
            cin.ignore();
            return value;
        }
    }
}

double getDoubleInput(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
        } else {
            cin.ignore();
            return value;
        }
    }
}

string getStringInput(const string& prompt) {
    string value;
    cout << prompt;
    getline(cin, value);
    return value;
}

char getGradeInput(const string& prompt) {
    char grade;
    while (true) {
        cout << prompt;
        cin >> grade;
        grade = toupper(grade);
        if (grade == 'A' || grade == 'B' || grade == 'C' || grade == 'D' || grade == 'F') {
            cin.ignore();
            return grade;
        } else {
            cout << "Invalid grade. Must be A, B, C, D, or F." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// Main menu functions
void displayMainMenu() {
    cout << "\n=== University Student Management System ===" << endl;
    cout << "1. Student Management" << endl;
    cout << "2. Faculty Management" << endl;
    cout << "3. Course Management" << endl;
    cout << "4. Enrollment Management" << endl;
    cout << "5. Grade Management" << endl;
    cout << "6. Reports" << endl;
    cout << "7. Save Data" << endl;
    cout << "8. Load Data" << endl;
    cout << "0. Exit" << endl;
}

void studentManagementMenu(UniversityManagementSystem& ums) {
    while (true) {
        cout << "\n=== Student Management ===" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Remove Student" << endl;
        cout << "3. View Student" << endl;
        cout << "4. View All Students" << endl;
        cout << "0. Back to Main Menu" << endl;

        int choice = getIntInput("Enter your choice: ");
        
        try {
            switch (choice) {
                case 1: {
                    string name = getStringInput("Enter student name: ");
                    string id = getStringInput("Enter student ID: ");
                    int age = getIntInput("Enter student age: ");
                    double gpa = getDoubleInput("Enter student GPA: ");
                    ums.addStudent(Student(name, id, age, gpa));
                    cout << "Student added successfully." << endl;
                    break;
                }
                case 2: {
                    string id = getStringInput("Enter student ID to remove: ");
                    ums.removeStudent(id);
                    cout << "Student removed successfully." << endl;
                    break;
                }
                case 3: {
                    string id = getStringInput("Enter student ID to view: ");
                    ums.displayStudentReport(id);
                    break;
                }
                case 4:
                    ums.displayAllStudents();
                    break;
                case 0:
                    return;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }
}

void facultyManagementMenu(UniversityManagementSystem& ums) {
    while (true) {
        cout << "\n=== Faculty Management ===" << endl;
        cout << "1. Add Faculty" << endl;
        cout << "2. Remove Faculty" << endl;
        cout << "3. View Faculty" << endl;
        cout << "4. View All Faculty" << endl;
        cout << "0. Back to Main Menu" << endl;

        int choice = getIntInput("Enter your choice: ");
        
        try {
            switch (choice) {
                case 1: {
                    string name = getStringInput("Enter faculty name: ");
                    string id = getStringInput("Enter faculty ID: ");
                    int age = getIntInput("Enter faculty age: ");
                    string specialization = getStringInput("Enter faculty specialization: ");
                    ums.addFaculty(Faculty(name, id, age, specialization));
                    cout << "Faculty added successfully." << endl;
                    break;
                }
                case 2: {
                    string id = getStringInput("Enter faculty ID to remove: ");
                    ums.removeFaculty(id);
                    cout << "Faculty removed successfully." << endl;
                    break;
                }
                case 3: {
                    string id = getStringInput("Enter faculty ID to view: ");
                    const Faculty* faculty = ums.getFaculty(id);
                    if (faculty != nullptr) {
                        faculty->display();
                    } else {
                        cout << "Faculty not found." << endl;
                    }
                    break;
                }
                case 4:
                    ums.displayAllFaculty();
                    break;
                case 0:
                    return;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }
}

void courseManagementMenu(UniversityManagementSystem& ums) {
    while (true) {
        cout << "\n=== Course Management ===" << endl;
        cout << "1. Add Course" << endl;
        cout << "2. Remove Course" << endl;
        cout << "3. View Course" << endl;
        cout << "4. View All Courses" << endl;
        cout << "0. Back to Main Menu" << endl;

        int choice = getIntInput("Enter your choice: ");
        
        try {
            switch (choice) {
                case 1: {
                    string code = getStringInput("Enter course code: ");
                    string title = getStringInput("Enter course title: ");
                    string facultyId = getStringInput("Enter faculty ID (leave empty if none): ");
                    ums.addCourse(Course(code, title, facultyId));
                    cout << "Course added successfully." << endl;
                    break;
                }
                case 2: {
                    string code = getStringInput("Enter course code to remove: ");
                    ums.removeCourse(code);
                    cout << "Course removed successfully." << endl;
                    break;
                }
                case 3: {
                    string code = getStringInput("Enter course code to view: ");
                    ums.displayCourseReport(code);
                    break;
                }
                case 4:
                    ums.displayAllCourses();
                    break;
                case 0:
                    return;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }
}

void enrollmentManagementMenu(UniversityManagementSystem& ums) {
    while (true) {
        cout << "\n=== Enrollment Management ===" << endl;
        cout << "1. Enroll Student in Course" << endl;
        cout << "2. Drop Student from Course" << endl;
        cout << "0. Back to Main Menu" << endl;

        int choice = getIntInput("Enter your choice: ");
        
        try {
            switch (choice) {
                case 1: {
                    string studentId = getStringInput("Enter student ID: ");
                    string courseCode = getStringInput("Enter course code: ");
                    ums.enrollStudentInCourse(studentId, courseCode);
                    cout << "Student enrolled successfully." << endl;
                    break;
                }
                case 2: {
                    string studentId = getStringInput("Enter student ID: ");
                    string courseCode = getStringInput("Enter course code: ");
                    ums.dropStudentFromCourse(studentId, courseCode);
                    cout << "Student dropped successfully." << endl;
                    break;
                }
                case 0:
                    return;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }
}

void gradeManagementMenu(UniversityManagementSystem& ums) {
    while (true) {
        cout << "\n=== Grade Management ===" << endl;
        cout << "1. Add/Update Grade" << endl;
        cout << "2. Remove Grade" << endl;
        cout << "0. Back to Main Menu" << endl;

        int choice = getIntInput("Enter your choice: ");
        
        try {
            switch (choice) {
                case 1: {
                    string studentId = getStringInput("Enter student ID: ");
                    string courseCode = getStringInput("Enter course code: ");
                    char grade = getGradeInput("Enter grade (A, B, C, D, F): ");
                    ums.addGrade(studentId, courseCode, grade);
                    cout << "Grade added/updated successfully." << endl;
                    break;
                }
                case 2: {
                    string studentId = getStringInput("Enter student ID: ");
                    string courseCode = getStringInput("Enter course code: ");
                    ums.removeGrade(studentId, courseCode);
                    cout << "Grade removed successfully." << endl;
                    break;
                }
                case 0:
                    return;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }
}

void reportsMenu(UniversityManagementSystem& ums) {
    while (true) {
        cout << "\n=== Reports ===" << endl;
        cout << "1. Student Report" << endl;
        cout << "2. Course Report" << endl;
        cout << "3. View All Students" << endl;
        cout << "4. View All Faculty" << endl;
        cout << "5. View All Courses" << endl;
        cout << "0. Back to Main Menu" << endl;

        int choice = getIntInput("Enter your choice: ");
        
        try {
            switch (choice) {
                case 1: {
                    string id = getStringInput("Enter student ID: ");
                    ums.displayStudentReport(id);
                    break;
                }
                case 2: {
                    string code = getStringInput("Enter course code: ");
                    ums.displayCourseReport(code);
                    break;
                }
                case 3:
                    ums.displayAllStudents();
                    break;
                case 4:
                    ums.displayAllFaculty();
                    break;
                case 5:
                    ums.displayAllCourses();
                    break;
                case 0:
                    return;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }
}

int main() {
    UniversityManagementSystem ums;
    
    // Load any existing data
    try {
        ums.loadData();
    } catch (...) {
        cout << "No existing data found or error loading data." << endl;
    }

    while (true) {
        displayMainMenu();
        int choice = getIntInput("Enter your choice: ");
        
        try {
            switch (choice) {
                case 1:
                    studentManagementMenu(ums);
                    break;
                case 2:
                    facultyManagementMenu(ums);
                    break;
                case 3:
                    courseManagementMenu(ums);
                    break;
                case 4:
                    enrollmentManagementMenu(ums);
                    break;
                case 5:
                    gradeManagementMenu(ums);
                    break;
                case 6:
                    reportsMenu(ums);
                    break;
                case 7:
                    ums.saveData();
                    cout << "Data saved successfully." << endl;
                    break;
                case 8:
                    ums.loadData();
                    cout << "Data loaded successfully." << endl;
                    break;
                case 0:
                    cout << "Exiting system. Goodbye!" << endl;
                    return 0;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    return 0;
}