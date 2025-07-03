#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <limits>
#include <unistd.h>
#include <memory>
#include <algorithm>
#include <filesystem>

using namespace std;
namespace fs = filesystem;   //creates an alias fs for the std::filesystem namespace

// class for all persons in the university
class Person {
protected:
    string id;
    string name;
    int age;

public:
    Person(const string& id = "", const string& name = "", int age = 0)
    : id(id), name(name), age(age) {}   //Initializes a person with default or given values

    virtual ~Person(){}      //derived class destructor when delating through base pointer

    //Getter and setter method
    string getId() const { return id; }
    string getName() const { return name; }
    int getAge() const { return age; }

    void setId(const string& newId){ id = newId; }
    void setName(const string& newName) { name = newName; }
    void setAge(int newAge) { age = newAge; }

    virtual void display() const {    //Virtual allows overridding in subclass
        cout << "ID: " << id << "\nName: " << name << "\nAge: " << age << endl;  //outputs persons basic information
    }

    //file serialization
    virtual string toFileString() const {            //toFileString(): Converts object to colon-separated format for saving to file
        return id + ":" + name + ":" + to_string(age);
    }

    virtual void fromFileString(const string& data) {  //fromFileString(): Parses colon-separated string and sets member values
        size_t pos1 = data.find(':');
        size_t pos2 = data.find(':', pos1 + 1);

        if (pos1 != string::npos && pos2 != string::npos) {
            id = data.substr(0, pos1);
            name = data.substr(pos1 + 1, pos2 - pos1 - 1);
            age = stoi(data.substr(pos2 + 1));
        }
    }
};

// Derived class for Students
class Student : public Person {
private:
    double gpa;                          //Inherits from Person
    string address;                       //Adds gpa and address specific to students.

public:
    Student(const string& id = "", const string& name = "", int age = 0,
            double gpa = 0.0, const string& address = "")                   //Access and modify gpa and address
        : Person(id, name, age), gpa(gpa), address(address) {}

    // Getters and setters
    double getGpa() const { return gpa; }
    string getAddress() const { return address; }

    void setGpa(double newGpa) { gpa = newGpa; }
    void setAddress(const string& newAddress) { address = newAddress; }

    void display() const override {
        Person::display();                                   //override display to show student info
        cout << "GPA: " << fixed << setprecision(2) << gpa 
             << "\nAddress: " << address << endl;
    }

    string toFileString() const override {                                     // Override serialization for student-specific data
        return Person::toFileString() + ":" + to_string(gpa) + ":" + address;
    }

    void fromFileString(const string& data) override {   // Override deserialization for student-specific data
        size_t pos1 = data.find(':');
        size_t pos2 = data.find(':', pos1 + 1);
        size_t pos3 = data.find(':', pos2 + 1);
        size_t pos4 = data.find(':', pos3 + 1);

        if (pos1 != string::npos && pos2 != string::npos && 
            pos3 != string::npos && pos4 != string::npos) {
            Person::fromFileString(data.substr(0, pos3));
            gpa = stod(data.substr(pos3 + 1, pos4 - pos3 - 1));
            address = data.substr(pos4 + 1);
        }
    }
};

// Derived class for Faculty
class Faculty : public Person {
private:
    string specialization;
    string department;

public:
    Faculty(const string& id = "", const string& name = "", int age = 0,
            const string& specialization = "", const string& department = "")
        : Person(id, name, age), specialization(specialization), department(department) {}

    // Getters and setters
    string getSpecialization() const { return specialization; }
    string getDepartment() const { return department; }

    void setSpecialization(const string& newSpec) { specialization = newSpec; }
    void setDepartment(const string& newDept) { department = newDept; }

    void display() const override {
        Person::display();
        cout << "Specialization: " << specialization 
             << "\nDepartment: " << department << endl;
    }

    string toFileString() const override {
        return Person::toFileString() + ":" + specialization + ":" + department;
    }

    void fromFileString(const string& data) override {
        size_t pos1 = data.find(':');                       
        size_t pos2 = data.find(':', pos1 + 1);
        size_t pos3 = data.find(':', pos2 + 1);
        size_t pos4 = data.find(':', pos3 + 1);

        if (pos1 != string::npos && pos2 != string::npos && 
            pos3 != string::npos && pos4 != string::npos) {
            Person::fromFileString(data.substr(0, pos3));
            specialization = data.substr(pos3 + 1, pos4 - pos3 - 1);
            department = data.substr(pos4 + 1);
        }
    }
};

// For university corses created a Course class 
class Course {
private:
    string code;
    string title;
    string facultyId;
    vector<string> enrolledStudents;

public:                                                                                      //using constructor with default values
    Course(const string& code = "", const string& title = "", const string& facultyId = "")
        : code(code), title(title), facultyId(facultyId) {}

    // Getters and setters
    string getCode() const { return code; }
    string getTitle() const { return title; }
    string getFacultyId() const { return facultyId; }
    const vector<string>& getEnrolledStudents() const { return enrolledStudents; }

    void setCode(const string& newCode) { code = newCode; }
    void setTitle(const string& newTitle) { title = newTitle; }
    void setFacultyId(const string& newFacultyId) { facultyId = newFacultyId; }

    void addStudent(const string& studentId) {     //add a student to course if not already enrolled 
        if (find(enrolledStudents.begin(), enrolledStudents.end(), studentId) == enrolledStudents.end()) {
            enrolledStudents.push_back(studentId);
        }
    }

    void removeStudent(const string& studentId) { //this funtion add remove feature
        enrolledStudents.erase(
        remove(enrolledStudents.begin(), enrolledStudents.end(), studentId),
        enrolledStudents.end()
        );
    }
     //dispalys course information
    void display() const {
        cout << "Course Code: " << code << "\nTitle: " << title 
             << "\nFaculty ID: " << facultyId << "\nEnrolled Students: " 
             << enrolledStudents.size() << endl;
    }

    string toFileString() const {
        string result = code + ":" + title + ":" + facultyId;
        for (const auto& student : enrolledStudents) {
            result += ":" + student;
        }
        return result;
    }

    void fromFileString(const string& data) {
        enrolledStudents.clear();
        size_t pos1 = data.find(':');
        size_t pos2 = data.find(':', pos1 + 1);

        if (pos1 != string::npos && pos2 != string::npos) {
            code = data.substr(0, pos1);
            title = data.substr(pos1 + 1, pos2 - pos1 - 1);
            facultyId = data.substr(pos2 + 1);

            size_t pos = data.find(':', pos2 + 1);
            while (pos != string::npos) {                     //extract all students that are enrolled 
                size_t nextPos = data.find(':', pos + 1);
                string studentId = data.substr(pos + 1, nextPos - pos - 1);
                enrolledStudents.push_back(studentId);
                pos = nextPos;
            }
        }
    }
};

// Gradebook class to manage student grades
class Gradebook {
private:
    map<pair<string, string>, char> grades; // Key: (studentId, courseCode), Value: grade

public:
    void addGrade(const string& studentId, const string& courseCode, char grade) {
        grades[{studentId, courseCode}] = grade;
    }

    void updateGrade(const string& studentId, const string& courseCode, char grade) {
        auto it = grades.find({studentId, courseCode});
        if (it != grades.end()) {
            it->second = grade;
        }
    }

    void removeGrade(const string& studentId, const string& courseCode) {
    grades.erase({studentId, courseCode});
    }

    char getGrade(const string& studentId, const string& courseCode) const {
        auto it = grades.find({studentId, courseCode});
        return (it != grades.end()) ? it->second : 'N'; // 'N' for no grade
    }

    double calculateGPA(const string& studentId, const vector<string>& courseCodes) const {
        double totalPoints = 0.0;
        int count = 0;

        for (const auto& courseCode : courseCodes) {
            char grade = getGrade(studentId, courseCode);
            if (grade != 'N') {
                count++;
                switch (toupper(grade)) {
                    case 'A': totalPoints += 4.0; break;
                    case 'B': totalPoints += 3.0; break;
                    case 'C': totalPoints += 2.0; break;
                    case 'D': totalPoints += 1.0; break;
                    case 'F': totalPoints += 0.0; break;
                    default: count--; break; // Invalid grade, don't count
                }
            }
        }
        return (count > 0) ? totalPoints / count : 0.0;
    }

    string toFileString() const {
        string result;
        for (const auto& entry : grades) {
            result += entry.first.first + ":" + entry.first.second + ":" + entry.second + "\n";
        }
        return result;
    }
     // Deserialize string to gradebook
    void fromFileString(const string& data) {
        grades.clear();
        size_t start = 0;
        size_t end = data.find('\n');

        while (end != string::npos) {
            string line = data.substr(start, end - start);
            size_t pos1 = line.find(':');
            size_t pos2 = line.find(':', pos1 + 1);

            if (pos1 != string::npos && pos2 != string::npos) {
                string studentId = line.substr(0, pos1);
                string courseCode = line.substr(pos1 + 1, pos2 - pos1 - 1);
                char grade = line[pos2 + 1];
                grades[{studentId, courseCode}] = grade;
            }

            start = end + 1;
            end = data.find('\n', start);
        }
    }
};

// University Management System main application class 
class UniversitySystem {
private:
    vector<shared_ptr<Student>> students; //list of all students faculty and course
    vector<shared_ptr<Faculty>> faculty;
    vector<Course> courses;
    Gradebook gradebook;
    const string studentsFile = "students.dat";
    const string facultyFile = "faculty.dat";
    const string coursesFile = "courses.dat";
    const string gradesFile = "grades.dat";

    void clearInputBuffer() {        // Clear input buffer to handle invalid input
        cin.clear();                 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void pauseProgram() {                       // Pause program execution until user presses Enter
        cout << "\nPress Enter to continue...";
        clearInputBuffer();
        cin.get();
    }

    void displayHeader(const string& title) {
        system("clear");
        cout << title << endl;
        cout << string(title.length(), '=') << endl << endl;
    }

    // Create file if it doesn't exist
    void ensureFileExists(const string& filename) {
        if (!fs::exists(filename)) {
            ofstream outFile(filename);
            if (outFile) {
                outFile.close();
                cout << "Created new file: " << filename << endl;
            }
        }
    }

    // File operations
    void loadData() {
        // Ensure all files exist before loading
        ensureFileExists(studentsFile);
        ensureFileExists(facultyFile);
        ensureFileExists(coursesFile);
        ensureFileExists(gradesFile);

        // Load students
        ifstream inFile(studentsFile);
        if (inFile) {
            string line;
            while (getline(inFile, line)) {
                auto student = make_shared<Student>();
                student->fromFileString(line);
                students.push_back(student);
            }
            inFile.close();
        }

        // Load faculty
        inFile.open(facultyFile);
        if (inFile) {
            string line;
            while (getline(inFile, line)) {
                auto fac = make_shared<Faculty>();
                fac->fromFileString(line);
                faculty.push_back(fac);
            }
            inFile.close();
        }

        // Load courses
        inFile.open(coursesFile);
        if (inFile) {
            string line;
            while (getline(inFile, line)) {
                Course course;
                course.fromFileString(line);
                courses.push_back(course);
            }
            inFile.close();
        }

        // Load grades
        inFile.open(gradesFile);
        if (inFile) {
            string data((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
            gradebook.fromFileString(data);
            inFile.close();
        }
    }

    void saveData() {
        // Save students
        ofstream outFile(studentsFile);
        if (outFile) {
            for (const auto& student : students) {
                outFile << student->toFileString() << endl;
            }
            outFile.close();
        }

        // Save faculty
        outFile.open(facultyFile);
        if (outFile) {
            for (const auto& fac : faculty) {
                outFile << fac->toFileString() << endl;
            }
            outFile.close();
        }

        // Save courses
        outFile.open(coursesFile);
        if (outFile) {
            for (const auto& course : courses) {
                outFile << course.toFileString() << endl;
            }
            outFile.close();
        }

        // Save grades
        outFile.open(gradesFile);
        if (outFile) {
            outFile << gradebook.toFileString();
            outFile.close();
        }
    }

    // Helper functions
    shared_ptr<Student> findStudent(const string& id) {
        for (const auto& student : students) {              //this funtion finds student by their id
            if (student->getId() == id) {
                return student;
            }
        }
        return nullptr;
    }

    shared_ptr<Faculty> findFaculty(const string& id) {
        for (const auto& fac : faculty) {
            if (fac->getId() == id) {
                return fac;
            }
        }
        return nullptr;
    }

    Course* findCourse(const string& code) {   // Helper function to find a course by code
        for (auto& course : courses) {
            if (course.getCode() == code) {
                return &course;
            }
        }
        return nullptr;
    }

    void displayAllStudents() {
        displayHeader("All Students");
        for (const auto& student : students) {
            student->display();
            cout << endl;
        }
        pauseProgram();
    }

    void displayAllFaculty() {
        displayHeader("All Faculty");
        for (const auto& fac : faculty) {
            fac->display();
            cout << endl;
        }
        pauseProgram();
    }

    void displayAllCourses() {
        displayHeader("All Courses");
        for (const auto& course : courses) {
            course.display();
            cout << endl;
        }
        pauseProgram();
    }

    // New functions for updating information
    void updateStudent() {
        displayHeader("Update Student Information");
        
        string id;
        cout << "Enter Student ID to update: ";
        getline(cin, id);
        
        auto student = findStudent(id);
        if (!student) {
            cout << "Student not found!" << endl;
            pauseProgram();
            return;
        }

        cout << "\nCurrent Student Information:\n";
        student->display();
        cout << endl;

        string name, address;
        int age;
        double gpa;

        cout << "Enter new Name (or leave blank to keep current): ";
        getline(cin, name);
        if (!name.empty()) {
            student->setName(name);
        }

        cout << "Enter new Age (or 0 to keep current): ";
        if (cin >> age) {
            if (age > 0) {
                student->setAge(age);
            }
        }
        clearInputBuffer();

        cout << "Enter new GPA (or -1 to keep current): ";
        if (cin >> gpa) {
            if (gpa >= 0 && gpa <= 4.0) {
                student->setGpa(gpa);
            }
        }
        clearInputBuffer();

        cout << "Enter new Address (or leave blank to keep current): ";
        getline(cin, address);
        if (!address.empty()) {
            student->setAddress(address);
        }

        cout << "\nStudent information updated successfully!" << endl;
        pauseProgram();
    }

    void updateFaculty() {
        displayHeader("Update Faculty Information");
        
        string id;
        cout << "Enter Faculty ID to update: ";
        getline(cin, id);
        
        auto fac = findFaculty(id);
        if (!fac) {
            cout << "Faculty not found!" << endl;
            pauseProgram();
            return;
        }

        cout << "\nCurrent Faculty Information:\n";
        fac->display();
        cout << endl;

        string name, specialization, department;
        int age;

        cout << "Enter new Name (or leave blank to keep current): ";
        getline(cin, name);
        if (!name.empty()) {
            fac->setName(name);
        }

        cout << "Enter new Age (or 0 to keep current): ";
        if (cin >> age) {
            if (age > 0) {
                fac->setAge(age);
            }
        }
        clearInputBuffer();

        cout << "Enter new Specialization (or leave blank to keep current): ";
        getline(cin, specialization);
        if (!specialization.empty()) {
            fac->setSpecialization(specialization);
        }

        cout << "Enter new Department (or leave blank to keep current): ";
        getline(cin, department);
        if (!department.empty()) {
            fac->setDepartment(department);
        }

        cout << "\nFaculty information updated successfully!" << endl;
        pauseProgram();
    }

    void updateCourse() {
        displayHeader("Update Course Information");
        
        string code;
        cout << "Enter Course Code to update: ";
        getline(cin, code);
        
        auto course = findCourse(code);
        if (!course) {
            cout << "Course not found!" << endl;
            pauseProgram();
            return;
        }

        cout << "\nCurrent Course Information:\n";
        course->display();
        cout << endl;

        string title, facultyId;

        cout << "Enter new Title (or leave blank to keep current): ";
        getline(cin, title);
        if (!title.empty()) {
            course->setTitle(title);
        }

        cout << "Enter new Faculty ID (or leave blank to keep current, 'none' to remove faculty): ";
        getline(cin, facultyId);
        if (!facultyId.empty()) {
            if (facultyId == "none") {
                course->setFacultyId("");
            } else if (findFaculty(facultyId)) {
                course->setFacultyId(facultyId);
            } else {
                cout << "Faculty ID not found. Faculty assignment not changed." << endl;
            }
        }

        cout << "\nCourse information updated successfully!" << endl;
        pauseProgram();
    }

    // New functions for deleting records
    void deleteStudent() {
        displayHeader("Delete Student");
        
        string id;
        cout << "Enter Student ID to delete: ";
        getline(cin, id);
        
        auto it = find_if(students.begin(), students.end(), 
            [&id](const shared_ptr<Student>& s) { return s->getId() == id; });
        
        if (it == students.end()) {
            cout << "Student not found!" << endl;
            pauseProgram();
            return;
        }

        // Remove student from all courses
        for (auto& course : courses) {
            course.removeStudent(id);
        }

        // Remove student's grades
        for (auto& course : courses) {
            gradebook.removeGrade(id, course.getCode());
        }

        students.erase(it);
        cout << "\nStudent deleted successfully!" << endl;
        pauseProgram();
    }

    void deleteFaculty() {
        displayHeader("Delete Faculty");
        
        string id;
        cout << "Enter Faculty ID to delete: ";
        getline(cin, id);
        
        auto it = find_if(faculty.begin(), faculty.end(), 
            [&id](const shared_ptr<Faculty>& f) { return f->getId() == id; });
        
        if (it == faculty.end()) {
            cout << "Faculty not found!" << endl;
            pauseProgram();
            return;
        }

        // Remove faculty from all courses
        for (auto& course : courses) {
            if (course.getFacultyId() == id) {
                course.setFacultyId("");
            }
        }

        faculty.erase(it);
        cout << "\nFaculty deleted successfully!" << endl;
        pauseProgram();
    }

    void deleteCourse() {
        displayHeader("Delete Course");
        
        string code;
        cout << "Enter Course Code to delete: ";
        getline(cin, code);
        
        auto it = find_if(courses.begin(), courses.end(), 
            [&code](const Course& c) { return c.getCode() == code; });
        
        if (it == courses.end()) {
            cout << "Course not found!" << endl;
            pauseProgram();
            return;
        }

        // Remove all grades for this course
        for (const auto& studentId : it->getEnrolledStudents()) {
            gradebook.removeGrade(studentId, code);
        }

        courses.erase(it);
        cout << "\nCourse deleted successfully!" << endl;
        pauseProgram();
    }

public:
    UniversitySystem() {   //this construcor laods data when system starts 
        loadData();
    }

    ~UniversitySystem() { //destrucor save data when sytem exists 
        saveData();
    }
//add new students 
    void addStudent() {
        displayHeader("Add New Student");
        
        string id, name, address;
        int age;
        double gpa;

        cout << "Enter Student ID: ";
        getline(cin, id);
        if (findStudent(id)) {
            cout << "Student with this ID already exists!" << endl;
            pauseProgram();
            return;
        }

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Age: ";
        while (!(cin >> age) || age < 0) {
            cout << "Invalid age. Please enter a positive number: ";
            clearInputBuffer();
        }
        clearInputBuffer();

        cout << "Enter GPA: ";
        while (!(cin >> gpa) || gpa < 0 || gpa > 4.0) {
            cout << "Invalid GPA. Please enter a value between 0 and 4.0: ";
            clearInputBuffer();
        }
        clearInputBuffer();

        cout << "Enter Address: ";
        getline(cin, address);

        auto student = make_shared<Student>(id, name, age, gpa, address);
        students.push_back(student);

        cout << "\nStudent added successfully!" << endl;
        pauseProgram();
    }
    //add new faculty 
    void addFaculty() { 
        displayHeader("Add New Faculty");
        
        string id, name, specialization, department;
        int age;

        cout << "Enter Faculty ID: ";
        getline(cin, id);
        if (findFaculty(id)) {
            cout << "Faculty with this ID already exists!" << endl;
            pauseProgram();
            return;
        }

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Age: ";
        while (!(cin >> age) || age < 0) {
            cout << "Invalid age. Please enter a positive number: ";
            clearInputBuffer();
        }
        clearInputBuffer();

        cout << "Enter Specialization: ";
        getline(cin, specialization);

        cout << "Enter Department: ";
        getline(cin, department);

        auto fac = make_shared<Faculty>(id, name, age, specialization, department);
        faculty.push_back(fac);

        cout << "\nFaculty added successfully!" << endl;
        pauseProgram();
    }

    void addCourse() {
        displayHeader("Add New Course");
        
        string code, title, facultyId;

        cout << "Enter Course Code: ";
        getline(cin, code);
        if (findCourse(code)) {
            cout << "Course with this code already exists!" << endl;
            pauseProgram();
            return;
        }

        cout << "Enter Course Title: ";
        getline(cin, title);

        cout << "Enter Faculty ID (or leave blank): ";
        getline(cin, facultyId);

        if (!facultyId.empty() && !findFaculty(facultyId)) {
            cout << "Faculty with this ID doesn't exist!" << endl;
            pauseProgram();
            return;
        }

        Course course(code, title, facultyId);
        courses.push_back(course);

        cout << "\nCourse added successfully!" << endl;
        pauseProgram();
    }

    void enrollStudentInCourse() {
        displayHeader("Enroll Student in Course");
        
        string studentId, courseCode;

        cout << "Enter Student ID: ";
        getline(cin, studentId);
        auto student = findStudent(studentId);
        if (!student) {
            cout << "Student not found!" << endl;
            pauseProgram();
            return;
        }

        cout << "Enter Course Code: ";
        getline(cin, courseCode);
        auto course = findCourse(courseCode);
        if (!course) {
            cout << "Course not found!" << endl;
            pauseProgram();
            return;
        }

        course->addStudent(studentId);
        cout << "\nStudent enrolled successfully!" << endl;
        pauseProgram();
    }

    void assignGrade() {
        displayHeader("Assign Grade to Student");
        
        string studentId, courseCode;
        char grade;

        cout << "Enter Student ID: ";
        getline(cin, studentId);
        if (!findStudent(studentId)) {
            cout << "Student not found!" << endl;
            pauseProgram();
            return;
        }

        cout << "Enter Course Code: ";
        getline(cin, courseCode);
        if (!findCourse(courseCode)) {
            cout << "Course not found!" << endl;
            pauseProgram();
            return;
        }

        cout << "Enter Grade (A-F): ";
        while (!(cin >> grade) || !isalpha(grade) || 
               toupper(grade) < 'A' || toupper(grade) > 'F') {
            cout << "Invalid grade. Please enter a letter from A to F: ";
            clearInputBuffer();
        }
        clearInputBuffer();

        gradebook.addGrade(studentId, courseCode, toupper(grade));
        cout << "\nGrade assigned successfully!" << endl;
        pauseProgram();
    }

    void viewStudentTranscript() {
        displayHeader("Student Transcript");
        
        string studentId;
        cout << "Enter Student ID: ";
        getline(cin, studentId);
        auto student = findStudent(studentId);
        if (!student) {
            cout << "Student not found!" << endl;
            pauseProgram();
            return;
        }

        student->display();
        cout << "\nCourses and Grades:\n";

        bool hasGrades = false;
        for (const auto& course : courses) {
            const auto& enrolled = course.getEnrolledStudents();
            if (find(enrolled.begin(), enrolled.end(), studentId) != enrolled.end()) {
                char grade = gradebook.getGrade(studentId, course.getCode());
                if (grade != 'N') {
                    cout << course.getCode() << " - " << course.getTitle() 
                         << ": " << grade << endl;
                    hasGrades = true;
                }
            }
        }

        if (!hasGrades) {
            cout << "No grades recorded yet." << endl;
        }

        // Calculate GPA
        vector<string> studentCourses;
        for (const auto& course : courses) {
            const auto& enrolled = course.getEnrolledStudents();
            if (find(enrolled.begin(), enrolled.end(), studentId) != enrolled.end()) {
                studentCourses.push_back(course.getCode());
            }
        }

        double gpa = gradebook.calculateGPA(studentId, studentCourses);
        cout << "\nCurrent GPA: " << fixed << setprecision(2) << gpa << endl;

        pauseProgram();
    }
     // this is main appliction loop funtion 
    void run() {
        int choice;
        bool running = true;

        while (running) {
            displayHeader("University Management System");
            cout << "1. Add Student\n2. Add Faculty\n3. Add Course\n4. Enroll Student in Course\n"
                 << "5. Assign Grade\n6. View Student Transcript\n7. Display All Students\n"
                 << "8. Display All Faculty\n9. Display All Courses\n10. Update Student\n"
                 << "11. Update Faculty\n12. Update Course\n13. Delete Student\n"
                 << "14. Delete Faculty\n15. Delete Course\n16. Exit\n\n"
                 << "Enter your choice: ";

            if (!(cin >> choice)) {
                cout << "\nInvalid input. Please enter a number." << endl;
                clearInputBuffer();
                sleep(2);
                continue;
            }
            clearInputBuffer(); //this is the main menu options 

            switch (choice) {
                case 1: addStudent(); break;
                case 2: addFaculty(); break;
                case 3: addCourse(); break;
                case 4: enrollStudentInCourse(); break;
                case 5: assignGrade(); break;
                case 6: viewStudentTranscript(); break;
                case 7: displayAllStudents(); break;
                case 8: displayAllFaculty(); break;
                case 9: displayAllCourses(); break;
                case 10: updateStudent(); break;
                case 11: updateFaculty(); break;
                case 12: updateCourse(); break;
                case 13: deleteStudent(); break;
                case 14: deleteFaculty(); break;
                case 15: deleteCourse(); break;
                case 16: running = false; break;
                default: cout << "\nInvalid choice. Please try again." << endl; sleep(2); break;
            }
        }

        cout << "\nGoodbye!" << endl;
        sleep(1);
    }
};
// main function entry point of the program
int main() {
    UniversitySystem system;
    system.run();
    return 0;
}