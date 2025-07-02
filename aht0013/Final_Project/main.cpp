#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stdexcept>
#include <fstream>
#include <iomanip>
#include <memory>
#include <limits>
#include <cctype>

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

    // Operator overloading
    bool operator==(const Person& other) const {
        return id == other.id;
    }

    friend ostream& operator<<(ostream& os, const Person& person);
};

ostream& operator<<(ostream& os, const Person& person) {
    person.display();
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

    // Getters
    double getGpa() const { return gpa; }
    const vector<string>& getEnrolledCourses() const { return enrolledCourses; }

    // Setters
    void setGpa(double gpa) { this->gpa = gpa; }

    void enrollCourse(const string& courseCode) {
        if (find(enrolledCourses.begin(), enrolledCourses.end(), courseCode) == enrolledCourses.end()) {
            enrolledCourses.push_back(courseCode);
        }
    }

    void dropCourse(const string& courseCode) {
        enrolledCourses.erase(
            remove(enrolledCourses.begin(), enrolledCourses.end(), courseCode),
            enrolledCourses.end()
        );
    }

    bool isEnrolledInCourse(const string& courseCode) const {
        return find(enrolledCourses.begin(), enrolledCourses.end(), courseCode) != enrolledCourses.end();
    }

    void display() const override {
        Person::display();
        cout << "GPA: " << fixed << setprecision(2) << gpa << "\nEnrolled Courses: ";
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
    vector<string> coursesTeaching;

public:
    Faculty(const string& name = "", const string& id = "", int age = 0, const string& specialization = "")
        : Person(name, id, age), specialization(specialization) {}

    // Getters
    string getSpecialization() const { return specialization; }
    const vector<string>& getCoursesTeaching() const { return coursesTeaching; }

    // Setters
    void setSpecialization(const string& specialization) { this->specialization = specialization; }

    void assignCourse(const string& courseCode) {
        if (find(coursesTeaching.begin(), coursesTeaching.end(), courseCode) == coursesTeaching.end()) {
            coursesTeaching.push_back(courseCode);
        }
    }

    void removeCourse(const string& courseCode) {
        coursesTeaching.erase(
            remove(coursesTeaching.begin(), coursesTeaching.end(), courseCode),
            coursesTeaching.end()
        );
    }

    void display() const override {
        Person::display();
        cout << "Specialization: " << specialization << "\nCourses Teaching: ";
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
    Course(const string& code = "", const string& title = "", const string& facultyId = "")
        : code(code), title(title), facultyId(facultyId) {}

    // Getters
    string getCode() const { return code; }
    string getTitle() const { return title; }
    string getFacultyId() const { return facultyId; }
    const vector<string>& getEnrolledStudents() const { return enrolledStudents; }

    // Setters
    void setCode(const string& code) { this->code = code; }
    void setTitle(const string& title) { this->title = title; }
    void setFacultyId(const string& facultyId) { this->facultyId = facultyId; }

    void enrollStudent(const string& studentId) {
        if (find(enrolledStudents.begin(), enrolledStudents.end(), studentId) == enrolledStudents.end()) {
            enrolledStudents.push_back(studentId);
        }
    }

    void dropStudent(const string& studentId) {
        enrolledStudents.erase(
            remove(enrolledStudents.begin(), enrolledStudents.end(), studentId),
            enrolledStudents.end()
        );
    }

    void display() const {
        cout << "Course Code: " << code << "\nTitle: " << title 
             << "\nFaculty ID: " << (facultyId.empty() ? "None" : facultyId) 
             << "\nEnrolled Students: ";
        for (const auto& student : enrolledStudents) {
            cout << student << " ";
        }
        cout << endl;
    }
};

// Gradebook class
class Gradebook {
private:
    map<pair<string, string>, char> grades; // Key: (studentId, courseCode), Value: grade

public:
    void addGrade(const string& studentId, const string& courseCode, char grade) {
        grades[{studentId, courseCode}] = toupper(grade);
    }

    void updateGrade(const string& studentId, const string& courseCode, char grade) {
        if (grades.find({studentId, courseCode}) == grades.end()) {
            throw invalid_argument("Grade entry not found");
        }
        grades[{studentId, courseCode}] = toupper(grade);
    }

    void removeGrade(const string& studentId, const string& courseCode) {
        grades.erase({studentId, courseCode});
    }

    char getGrade(const string& studentId, const string& courseCode) const {
        auto it = grades.find({studentId, courseCode});
        if (it == grades.end()) {
            throw invalid_argument("Grade entry not found");
        }
        return it->second;
    }

    bool hasGrade(const string& studentId, const string& courseCode) const {
        return grades.find({studentId, courseCode}) != grades.end();
    }

    const map<pair<string, string>, char>& getAllGrades() const {
        return grades;
    }
};

// GPA Calculator
class GPACalculator {
private:
    static double gradeToPoint(char grade) {
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
    static double calculateGPA(const Student& student, const Gradebook& gradebook) {
        const vector<string>& courses = student.getEnrolledCourses();
        if (courses.empty()) return 0.0;

        double totalPoints = 0.0;
        int count = 0;

        for (const auto& courseCode : courses) {
            try {
                char grade = gradebook.getGrade(student.getId(), courseCode);
                totalPoints += gradeToPoint(grade);
                count++;
            } catch (const invalid_argument&) {
                // Grade not found for this course, skip it
                continue;
            }
        }

        return count > 0 ? totalPoints / count : 0.0;
    }
};

// University System class
class UniversitySystem {
private:
    vector<Student> students;
    vector<Faculty> faculty;
    vector<Course> courses;
    Gradebook gradebook;

    // Generic find by ID for types with getId()
    template<typename T>
    int findById(const vector<T>& vec, const string& id) const {
        auto it = find_if(vec.begin(), vec.end(), 
            [&id](const T& item) { return item.getId() == id; });
        return it != vec.end() ? distance(vec.begin(), it) : -1;
    }

    int findCourseByCode(const string& code) const {
        auto it = find_if(courses.begin(), courses.end(),
            [&code](const Course& course) { return course.getCode() == code; });
        return it != courses.end() ? distance(courses.begin(), it) : -1;
    }

    // Convenience wrappers
    int findStudentById(const string& id) const {
        return findById(students, id);
    }

    int findFacultyById(const string& id) const {
        return findById(faculty, id);
    }

    void updateStudentGPA(Student& student) {
        student.setGpa(GPACalculator::calculateGPA(student, gradebook));
    }

    void validateStudentExists(const string& studentId) const {
        if (findStudentById(studentId) == -1) {
            throw invalid_argument("Student not found with ID: " + studentId);
        }
    }

    void validateFacultyExists(const string& facultyId) const {
        if (findFacultyById(facultyId) == -1) {
            throw invalid_argument("Faculty not found with ID: " + facultyId);
        }
    }

    void validateCourseExists(const string& courseCode) const {
        if (findCourseByCode(courseCode) == -1) {
            throw invalid_argument("Course not found with code: " + courseCode);
        }
    }

public:
    // Student management
    void addStudent(const Student& student) {
        if (findStudentById(student.getId()) != -1) {
            throw invalid_argument("Student with ID " + student.getId() + " already exists");
        }
        students.push_back(student);
    }

    void removeStudent(const string& studentId) {
        int index = findStudentById(studentId);
        if (index == -1) {
            throw invalid_argument("Student not found with ID: " + studentId);
        }

        // Remove student from all courses
        for (auto& course : courses) {
            course.dropStudent(studentId);
        }

        // Remove student's grades
        for (const auto& courseCode : students[index].getEnrolledCourses()) {
            gradebook.removeGrade(studentId, courseCode);
        }

        students.erase(students.begin() + index);
    }

    Student* getStudent(const string& studentId) {
        int index = findStudentById(studentId);
        return index != -1 ? &students[index] : nullptr;
    }

    const Student* getStudent(const string& studentId) const {
        int index = findStudentById(studentId);
        return index != -1 ? &students[index] : nullptr;
    }

    vector<Student> getAllStudents() const {
        return students;
    }

    // Faculty management
    void addFaculty(const Faculty& facultyMember) {
        if (findFacultyById(facultyMember.getId()) != -1) {
            throw invalid_argument("Faculty with ID " + facultyMember.getId() + " already exists");
        }
        faculty.push_back(facultyMember);
    }

    void removeFaculty(const string& facultyId) {
        int index = findFacultyById(facultyId);
        if (index == -1) {
            throw invalid_argument("Faculty not found with ID: " + facultyId);
        }

        // Remove faculty from all courses
        for (auto& course : courses) {
            if (course.getFacultyId() == facultyId) {
                course.setFacultyId("");
            }
        }

        faculty.erase(faculty.begin() + index);
    }

    Faculty* getFaculty(const string& facultyId) {
        int index = findFacultyById(facultyId);
        return index != -1 ? &faculty[index] : nullptr;
    }

    const Faculty* getFaculty(const string& facultyId) const {
        int index = findFacultyById(facultyId);
        return index != -1 ? &faculty[index] : nullptr;
    }

    vector<Faculty> getAllFaculty() const {
        return faculty;
    }

    // Course management
    void addCourse(const Course& course) {
        if (findCourseByCode(course.getCode()) != -1) {
            throw invalid_argument("Course with code " + course.getCode() + " already exists");
        }
        
        if (!course.getFacultyId().empty() && !getFaculty(course.getFacultyId())) {
            throw invalid_argument("Assigned faculty not found with ID: " + course.getFacultyId());
        }
        
        courses.push_back(course);
        
        // Assign course to faculty if specified
        if (!course.getFacultyId().empty()) {
            Faculty* facultyMember = getFaculty(course.getFacultyId());
            if (facultyMember) {
                facultyMember->assignCourse(course.getCode());
            }
        }
    }

    void removeCourse(const string& courseCode) {
        int index = findCourseByCode(courseCode);
        if (index == -1) {
            throw invalid_argument("Course not found with code: " + courseCode);
        }

        // Remove course from all students
        for (auto& student : students) {
            student.dropCourse(courseCode);
        }

        // Remove course from faculty teaching lists
        for (auto& facultyMember : faculty) {
            facultyMember.removeCourse(courseCode);
        }

        // Remove all grades for this course
        for (const auto& studentId : courses[index].getEnrolledStudents()) {
            gradebook.removeGrade(studentId, courseCode);
        }

        courses.erase(courses.begin() + index);
    }

    Course* getCourse(const string& courseCode) {
        int index = findCourseByCode(courseCode);
        return index != -1 ? &courses[index] : nullptr;
    }

    const Course* getCourse(const string& courseCode) const {
        int index = findCourseByCode(courseCode);
        return index != -1 ? &courses[index] : nullptr;
    }

    vector<Course> getAllCourses() const {
        return courses;
    }

    // Enrollment
    void enrollStudentInCourse(const string& studentId, const string& courseCode) {
        Student* student = getStudent(studentId);
        Course* course = getCourse(courseCode);

        if (!student) throw invalid_argument("Student not found with ID: " + studentId);
        if (!course) throw invalid_argument("Course not found with code: " + courseCode);

        // Check if already enrolled
        if (student->isEnrolledInCourse(courseCode)) {
            throw invalid_argument("Student " + studentId + " already enrolled in course " + courseCode);
        }

        student->enrollCourse(courseCode);
        course->enrollStudent(studentId);
    }

    void dropStudentFromCourse(const string& studentId, const string& courseCode) {
        Student* student = getStudent(studentId);
        Course* course = getCourse(courseCode);

        if (!student) throw invalid_argument("Student not found with ID: " + studentId);
        if (!course) throw invalid_argument("Course not found with code: " + courseCode);

        if (!student->isEnrolledInCourse(courseCode)) {
            throw invalid_argument("Student " + studentId + " not enrolled in course " + courseCode);
        }

        student->dropCourse(courseCode);
        course->dropStudent(studentId);
        gradebook.removeGrade(studentId, courseCode);
        updateStudentGPA(*student);
    }

    // Grade management
    void addGrade(const string& studentId, const string& courseCode, char grade) {
        validateStudentExists(studentId);
        validateCourseExists(courseCode);

        Student* student = getStudent(studentId);
        if (!student->isEnrolledInCourse(courseCode)) {
            throw invalid_argument("Student not enrolled in this course");
        }

        gradebook.addGrade(studentId, courseCode, grade);
        updateStudentGPA(*student);
    }

    void updateGrade(const string& studentId, const string& courseCode, char grade) {
        validateStudentExists(studentId);
        validateCourseExists(courseCode);

        if (!gradebook.hasGrade(studentId, courseCode)) {
            throw invalid_argument("Grade record not found");
        }

        gradebook.updateGrade(studentId, courseCode, grade);
        
        Student* student = getStudent(studentId);
        if (student) {
            updateStudentGPA(*student);
        }
    }

    char getGrade(const string& studentId, const string& courseCode) const {
        validateStudentExists(studentId);
        validateCourseExists(courseCode);
        
        if (!gradebook.hasGrade(studentId, courseCode)) {
            throw invalid_argument("Grade record not found");
        }
        
        return gradebook.getGrade(studentId, courseCode);
    }

    // Reporting
    void displayAllStudents() const {
        cout << "\n=== All Students (" << students.size() << ") ===\n";
        for (const auto& student : students) {
            cout << student << "\n-----------------\n";
        }
    }

    void displayAllFaculty() const {
        cout << "\n=== All Faculty (" << faculty.size() << ") ===\n";
        for (const auto& facultyMember : faculty) {
            cout << facultyMember << "\n-----------------\n";
        }
    }

    void displayAllCourses() const {
        cout << "\n=== All Courses (" << courses.size() << ") ===\n";
        for (const auto& course : courses) {
            course.display();
            cout << "-----------------\n";
        }
    }

    void displayStudentsInCourse(const string& courseCode) const {
        const Course* course = getCourse(courseCode);
        if (!course) {
            throw invalid_argument("Course not found with code: " + courseCode);
        }

        cout << "\n=== Students enrolled in " << courseCode << " (" 
             << course->getEnrolledStudents().size() << ") ===\n";
        for (const auto& studentId : course->getEnrolledStudents()) {
            const Student* student = getStudent(studentId);
            if (student) {
                cout << *student << "\n-----------------\n";
            }
        }
    }

    void displayCoursesForStudent(const string& studentId) const {
        const Student* student = getStudent(studentId);
        if (!student) {
            throw invalid_argument("Student not found with ID: " + studentId);
        }

        cout << "\n=== Courses for student " << studentId << " (" 
             << student->getEnrolledCourses().size() << ") ===\n";
        for (const auto& courseCode : student->getEnrolledCourses()) {
            const Course* course = getCourse(courseCode);
            if (course) {
                course->display();
                cout << "-----------------\n";
            }
        }
    }

    void displayStudentTranscript(const string& studentId) const {
        const Student* student = getStudent(studentId);
        if (!student) {
            throw invalid_argument("Student not found with ID: " + studentId);
        }

        cout << "\n=== Transcript for student " << studentId << " ===\n";
        cout << "Name: " << student->getName() << "\n";
        cout << "ID: " << student->getId() << "\n";
        cout << "GPA: " << fixed << setprecision(2) << student->getGpa() << "\n\n";
        cout << "Course Grades:\n";

        for (const auto& courseCode : student->getEnrolledCourses()) {
            const Course* course = getCourse(courseCode);
            if (course) {
                cout << courseCode << " - " << course->getTitle() << ": ";
                if (gradebook.hasGrade(studentId, courseCode)) {
                    cout << gradebook.getGrade(studentId, courseCode);
                } else {
                    cout << "No grade assigned";
                }
                cout << "\n";
            }
        }
    }

    // File handling
    void saveToFile(const string& filename) const {
        ofstream outFile(filename);
        if (!outFile) {
            throw runtime_error("Unable to open file for writing: " + filename);
        }

        // Save students
        outFile << "STUDENTS\n";
        for (const auto& student : students) {
            outFile << student.getName() << "," << student.getId() << "," 
                   << student.getAge() << "," << student.getGpa() << "\n";
        }

        // Save faculty
        outFile << "FACULTY\n";
        for (const auto& facultyMember : faculty) {
            outFile << facultyMember.getName() << "," << facultyMember.getId() << "," 
                   << facultyMember.getAge() << "," << facultyMember.getSpecialization() << "\n";
        }

        // Save courses
        outFile << "COURSES\n";
        for (const auto& course : courses) {
            outFile << course.getCode() << "," << course.getTitle() << "," 
                   << course.getFacultyId() << "\n";
        }

        // Save enrollments
        outFile << "ENROLLMENTS\n";
        for (const auto& student : students) {
            for (const auto& courseCode : student.getEnrolledCourses()) {
                outFile << student.getId() << "," << courseCode << "\n";
            }
        }

        // Save grades
        outFile << "GRADES\n";
        for (const auto& gradeEntry : gradebook.getAllGrades()) {
            outFile << gradeEntry.first.first << "," << gradeEntry.first.second << "," 
                   << gradeEntry.second << "\n";
        }

        outFile.close();
    }

    void loadFromFile(const string& filename) {
        ifstream inFile(filename);
        if (!inFile) {
            throw runtime_error("Unable to open file for reading: " + filename);
        }

        // Clear existing data
        students.clear();
        faculty.clear();
        courses.clear();
        gradebook = Gradebook();

        string line;
        string section;

        while (getline(inFile, line)) {
            if (line.empty()) continue;

            if (line == "STUDENTS" || line == "FACULTY" || line == "COURSES" || 
                line == "ENROLLMENTS" || line == "GRADES") {
                section = line;
                continue;
            }

            try {
                if (section == "STUDENTS") {
                    string name, id;
                    int age;
                    double gpa;

                    size_t pos1 = line.find(',');
                    size_t pos2 = line.find(',', pos1 + 1);
                    size_t pos3 = line.find(',', pos2 + 1);

                    name = line.substr(0, pos1);
                    id = line.substr(pos1 + 1, pos2 - pos1 - 1);
                    age = stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));
                    gpa = stod(line.substr(pos3 + 1));

                    students.emplace_back(name, id, age, gpa);
                }
                else if (section == "FACULTY") {
                    string name, id, specialization;
                    int age;

                    size_t pos1 = line.find(',');
                    size_t pos2 = line.find(',', pos1 + 1);
                    size_t pos3 = line.find(',', pos2 + 1);

                    name = line.substr(0, pos1);
                    id = line.substr(pos1 + 1, pos2 - pos1 - 1);
                    age = stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));
                    specialization = line.substr(pos3 + 1);

                    faculty.emplace_back(name, id, age, specialization);
                }
                else if (section == "COURSES") {
                    string code, title, facultyId;

                    size_t pos1 = line.find(',');
                    size_t pos2 = line.find(',', pos1 + 1);

                    code = line.substr(0, pos1);
                    title = line.substr(pos1 + 1, pos2 - pos1 - 1);
                    facultyId = line.substr(pos2 + 1);

                    courses.emplace_back(code, title, facultyId);
                }
                else if (section == "ENROLLMENTS") {
                    string studentId, courseCode;

                    size_t pos = line.find(',');
                    studentId = line.substr(0, pos);
                    courseCode = line.substr(pos + 1);

                    Student* student = getStudent(studentId);
                    Course* course = getCourse(courseCode);

                    if (student && course) {
                        student->enrollCourse(courseCode);
                        course->enrollStudent(studentId);
                    }
                }
                else if (section == "GRADES") {
                    string studentId, courseCode;
                    char grade;

                    size_t pos1 = line.find(',');
                    size_t pos2 = line.find(',', pos1 + 1);

                    studentId = line.substr(0, pos1);
                    courseCode = line.substr(pos1 + 1, pos2 - pos1 - 1);
                    grade = line.substr(pos2 + 1)[0];

                    gradebook.addGrade(studentId, courseCode, grade);
                }
            } catch (const exception& e) {
                cerr << "Error processing line: " << line << "\nError: " << e.what() << endl;
                continue;
            }
        }

        // Update all student GPAs
        for (auto& student : students) {
            updateStudentGPA(student);
        }

        inFile.close();
    }
};

// Template function for sorting
template<typename T>
void sortById(vector<T>& items) {
    sort(items.begin(), items.end(), [](const T& a, const T& b) {
        return a.getId() < b.getId();
    });
}

// Template function for searching
template<typename T>
vector<T> searchByName(const vector<T>& items, const string& name) {
    vector<T> results;
    for (const auto& item : items) {
        if (item.getName().find(name) != string::npos) {
            results.push_back(item);
        }
    }
    return results;
}

// Menu system
void displayMainMenu() {
    cout << "\n=== University Student Management System ===\n";
    cout << "1. Student Management\n";
    cout << "2. Faculty Management\n";
    cout << "3. Course Management\n";
    cout << "4. Enrollment Management\n";
    cout << "5. Grade Management\n";
    cout << "6. Reports\n";
    cout << "7. File Operations\n";
    cout << "8. Exit\n";
    cout << "Enter your choice: ";
}

void displayStudentMenu() {
    cout << "\n=== Student Management ===\n";
    cout << "1. Add Student\n";
    cout << "2. Remove Student\n";
    cout << "3. View Student Details\n";
    cout << "4. List All Students\n";
    cout << "5. Back to Main Menu\n";
    cout << "Enter your choice: ";
}

void displayFacultyMenu() {
    cout << "\n=== Faculty Management ===\n";
    cout << "1. Add Faculty\n";
    cout << "2. Remove Faculty\n";
    cout << "3. View Faculty Details\n";
    cout << "4. List All Faculty\n";
    cout << "5. Back to Main Menu\n";
    cout << "Enter your choice: ";
}

void displayCourseMenu() {
    cout << "\n=== Course Management ===\n";
    cout << "1. Add Course\n";
    cout << "2. Remove Course\n";
    cout << "3. View Course Details\n";
    cout << "4. List All Courses\n";
    cout << "5. Back to Main Menu\n";
    cout << "Enter your choice: ";
}

void displayEnrollmentMenu() {
    cout << "\n=== Enrollment Management ===\n";
    cout << "1. Enroll Student in Course\n";
    cout << "2. Drop Student from Course\n";
    cout << "3. Back to Main Menu\n";
    cout << "Enter your choice: ";
}

void displayGradeMenu() {
    cout << "\n=== Grade Management ===\n";
    cout << "1. Add/Update Grade\n";
    cout << "2. View Grade\n";
    cout << "3. Back to Main Menu\n";
    cout << "Enter your choice: ";
}

void displayReportMenu() {
    cout << "\n=== Reports ===\n";
    cout << "1. View Students in a Course\n";
    cout << "2. View Courses for a Student\n";
    cout << "3. View Student Transcript\n";
    cout << "4. Back to Main Menu\n";
    cout << "Enter your choice: ";
}

void displayFileMenu() {
    cout << "\n=== File Operations ===\n";
    cout << "1. Save Data to File\n";
    cout << "2. Load Data from File\n";
    cout << "3. Back to Main Menu\n";
    cout << "Enter your choice: ";
}

// Helper function for input
template<typename T>
T getInput(const string& prompt) {
    T value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please try again.\n";
        }
    }
    return value;
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
        if (grade >= 'A' && grade <= 'F' && grade != 'E') {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid grade. Please enter A, B, C, D, or F.\n";
        }
    }
    return grade;
}

int main() {
    UniversitySystem university;
    bool running = true;

    // Try to load data from file on startup
    try {
        university.loadFromFile("university_data.txt");
        cout << "Data loaded successfully from file.\n";
    } catch (const exception& e) {
        cout << "Could not load data from file: " << e.what() << "\nStarting with empty system.\n";
    }

    while (running) {
        displayMainMenu();
        int choice = getInput<int>("");

        try {
            switch (choice) {
                case 1: { // Student Management
                    bool inStudentMenu = true;
                    while (inStudentMenu) {
                        displayStudentMenu();
                        int studentChoice = getInput<int>("");

                        switch (studentChoice) {
                            case 1: { // Add Student
                                string name = getStringInput("Enter student name: ");
                                string id = getStringInput("Enter student ID: ");
                                int age = getInput<int>("Enter student age: ");
                                double gpa = getInput<double>("Enter student GPA: ");

                                Student student(name, id, age, gpa);
                                university.addStudent(student);
                                cout << "Student added successfully.\n";
                                break;
                            }
                            case 2: { // Remove Student
                                string id = getStringInput("Enter student ID to remove: ");
                                university.removeStudent(id);
                                cout << "Student removed successfully.\n";
                                break;
                            }
                            case 3: { // View Student Details
                                string id = getStringInput("Enter student ID: ");
                                Student* student = university.getStudent(id);
                                if (student) {
                                    cout << *student << endl;
                                } else {
                                    cout << "Student not found.\n";
                                }
                                break;
                            }
                            case 4: // List All Students
                                university.displayAllStudents();
                                break;
                            case 5: // Back to Main Menu
                                inStudentMenu = false;
                                break;
                            default:
                                cout << "Invalid choice. Please try again.\n";
                        }
                    }
                    break;
                }
                case 2: { // Faculty Management
                    bool inFacultyMenu = true;
                    while (inFacultyMenu) {
                        displayFacultyMenu();
                        int facultyChoice = getInput<int>("");

                        switch (facultyChoice) {
                            case 1: { // Add Faculty
                                string name = getStringInput("Enter faculty name: ");
                                string id = getStringInput("Enter faculty ID: ");
                                int age = getInput<int>("Enter faculty age: ");
                                string specialization = getStringInput("Enter faculty specialization: ");

                                Faculty facultyMember(name, id, age, specialization);
                                university.addFaculty(facultyMember);
                                cout << "Faculty added successfully.\n";
                                break;
                            }
                            case 2: { // Remove Faculty
                                string id = getStringInput("Enter faculty ID to remove: ");
                                university.removeFaculty(id);
                                cout << "Faculty removed successfully.\n";
                                break;
                            }
                            case 3: { // View Faculty Details
                                string id = getStringInput("Enter faculty ID: ");
                                Faculty* facultyMember = university.getFaculty(id);
                                if (facultyMember) {
                                    cout << *facultyMember << endl;
                                } else {
                                    cout << "Faculty not found.\n";
                                }
                                break;
                            }
                            case 4: // List All Faculty
                                university.displayAllFaculty();
                                break;
                            case 5: // Back to Main Menu
                                inFacultyMenu = false;
                                break;
                            default:
                                cout << "Invalid choice. Please try again.\n";
                        }
                    }
                    break;
                }
                case 3: { // Course Management
                    bool inCourseMenu = true;
                    while (inCourseMenu) {
                        displayCourseMenu();
                        int courseChoice = getInput<int>("");

                        switch (courseChoice) {
                            case 1: { // Add Course
                                string code = getStringInput("Enter course code: ");
                                string title = getStringInput("Enter course title: ");
                                string facultyId = getStringInput("Enter faculty ID (leave empty if none): ");

                                if (!facultyId.empty() && !university.getFaculty(facultyId)) {
                                    cout << "Faculty ID not found. Course will be added without faculty.\n";
                                    facultyId = "";
                                }

                                Course course(code, title, facultyId);
                                university.addCourse(course);
                                
                                if (!facultyId.empty()) {
                                    Faculty* facultyMember = university.getFaculty(facultyId);
                                    if (facultyMember) {
                                        facultyMember->assignCourse(code);
                                    }
                                }
                                
                                cout << "Course added successfully.\n";
                                break;
                            }
                            case 2: { // Remove Course
                                string code = getStringInput("Enter course code to remove: ");
                                university.removeCourse(code);
                                cout << "Course removed successfully.\n";
                                break;
                            }
                            case 3: { // View Course Details
                                string code = getStringInput("Enter course code: ");
                                Course* course = university.getCourse(code);
                                if (course) {
                                    course->display();
                                } else {
                                    cout << "Course not found.\n";
                                }
                                break;
                            }
                            case 4: // List All Courses
                                university.displayAllCourses();
                                break;
                            case 5: // Back to Main Menu
                                inCourseMenu = false;
                                break;
                            default:
                                cout << "Invalid choice. Please try again.\n";
                        }
                    }
                    break;
                }
                case 4: { // Enrollment Management
                    bool inEnrollmentMenu = true;
                    while (inEnrollmentMenu) {
                        displayEnrollmentMenu();
                        int enrollmentChoice = getInput<int>("");

                        switch (enrollmentChoice) {
                            case 1: { // Enroll Student in Course
                                string studentId = getStringInput("Enter student ID: ");
                                string courseCode = getStringInput("Enter course code: ");
                                university.enrollStudentInCourse(studentId, courseCode);
                                cout << "Student enrolled successfully.\n";
                                break;
                            }
                            case 2: { // Drop Student from Course
                                string studentId = getStringInput("Enter student ID: ");
                                string courseCode = getStringInput("Enter course code: ");
                                university.dropStudentFromCourse(studentId, courseCode);
                                cout << "Student dropped successfully.\n";
                                break;
                            }
                            case 3: // Back to Main Menu
                                inEnrollmentMenu = false;
                                break;
                            default:
                                cout << "Invalid choice. Please try again.\n";
                        }
                    }
                    break;
                }
                case 5: { // Grade Management
                    bool inGradeMenu = true;
                    while (inGradeMenu) {
                        displayGradeMenu();
                        int gradeChoice = getInput<int>("");

                        switch (gradeChoice) {
                            case 1: { // Add/Update Grade
                                string studentId = getStringInput("Enter student ID: ");
                                string courseCode = getStringInput("Enter course code: ");
                                char grade = getGradeInput("Enter grade (A-F): ");
                                
                                try {
                                    // Try to update first
                                    university.updateGrade(studentId, courseCode, grade);
                                    cout << "Grade updated successfully.\n";
                                } catch (const invalid_argument&) {
                                    // If update fails, try to add
                                    try {
                                        university.addGrade(studentId, courseCode, grade);
                                        cout << "Grade added successfully.\n";
                                    } catch (const invalid_argument& e) {
                                        cout << "Error: " << e.what() << "\n";
                                    }
                                }
                                break;
                            }
                            case 2: { // View Grade
                                string studentId = getStringInput("Enter student ID: ");
                                string courseCode = getStringInput("Enter course code: ");
                                try {
                                    char grade = university.getGrade(studentId, courseCode);
                                    cout << "Grade for student " << studentId << " in course " 
                                         << courseCode << ": " << grade << endl;
                                } catch (const invalid_argument& e) {
                                    cout << "Error: " << e.what() << "\n";
                                }
                                break;
                            }
                            case 3: // Back to Main Menu
                                inGradeMenu = false;
                                break;
                            default:
                                cout << "Invalid choice. Please try again.\n";
                        }
                    }
                    break;
                }
                case 6: { // Reports
                    bool inReportMenu = true;
                    while (inReportMenu) {
                        displayReportMenu();
                        int reportChoice = getInput<int>("");

                        switch (reportChoice) {
                            case 1: { // View Students in a Course
                                string courseCode = getStringInput("Enter course code: ");
                                university.displayStudentsInCourse(courseCode);
                                break;
                            }
                            case 2: { // View Courses for a Student
                                string studentId = getStringInput("Enter student ID: ");
                                university.displayCoursesForStudent(studentId);
                                break;
                            }
                            case 3: { // View Student Transcript
                                string studentId = getStringInput("Enter student ID: ");
                                university.displayStudentTranscript(studentId);
                                break;
                            }
                            case 4: // Back to Main Menu
                                inReportMenu = false;
                                break;
                            default:
                                cout << "Invalid choice. Please try again.\n";
                        }
                    }
                    break;
                }
                case 7: { // File Operations
                    bool inFileMenu = true;
                    while (inFileMenu) {
                        displayFileMenu();
                        int fileChoice = getInput<int>("");

                        switch (fileChoice) {
                            case 1: { // Save Data to File
                                string filename = getStringInput("Enter filename (default: university_data.txt): ");
                                if (filename.empty()) {
                                    filename = "university_data.txt";
                                }
                                university.saveToFile(filename);
                                cout << "Data saved successfully to " << filename << ".\n";
                                break;
                            }
                            case 2: { // Load Data from File
                                string filename = getStringInput("Enter filename (default: university_data.txt): ");
                                if (filename.empty()) {
                                    filename = "university_data.txt";
                                }
                                university.loadFromFile(filename);
                                cout << "Data loaded successfully from " << filename << ".\n";
                                break;
                            }
                            case 3: // Back to Main Menu
                                inFileMenu = false;
                                break;
                            default:
                                cout << "Invalid choice. Please try again.\n";
                        }
                    }
                    break;
                }
                case 8: // Exit
                    running = false;
                    // Save data to file on exit
                    try {
                        university.saveToFile("university_data.txt");
                        cout << "Data saved successfully to file.\n";
                    } catch (const exception& e) {
                        cout << "Could not save data to file: " << e.what() << "\n";
                    }
                    cout << "Exiting University Student Management System. Goodbye!\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << "\n";
        }
    }
    return 0;
}