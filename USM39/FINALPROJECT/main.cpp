#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <fstream>
#include "person.h"
#include "student.h"
#include "faculty.h"
#include "course.h"
#include "gradebook.h"
#include "utils.h"

void displayMainMenu() {
    std::cout << "\n====== University Student Management System ======\n";
    std::cout << "1. Add Student\n";
    std::cout << "2. Add Faculty\n";
    std::cout << "3. Add Course\n";
    std::cout << "4. Enroll Student in Course\n";
    std::cout << "5. Assign Grade\n";
    std::cout << "6. View Students in Course\n";
    std::cout << "7. View Courses of Student\n";
    std::cout << "8. View GPA Report\n";
    std::cout << "9. List All Students\n";
    std::cout << "10. List All Courses\n";
    std::cout << "0. Exit\n";
    std::cout << "===============================================\n";
    std::cout << "Enter your choice: ";
}

int main() {
    std::vector<Student> students;
    std::vector<Faculty> faculties;
    std::vector<Course> courses;
    Gradebook gradebook;

    int choice;
    do {
        displayMainMenu();
        std::cin >> choice;
        clearInputBuffer();

        try {
            switch (choice) {
            case 1: {
              
                std::string name, id;
                int age;
                std::cout << "Enter Student Name: ";
                std::getline(std::cin, name);
                std::cout << "Enter Student ID: ";
                std::getline(std::cin, id);
                std::cout << "Enter Age: ";
                std::cin >> age;
                clearInputBuffer();

                if (findStudent(students, id) != nullptr)
                    throw DuplicateIDException();

                students.emplace_back(name, id, age);
                std::cout << "Student added successfully.\n";
                break;
            }
            case 2: {
     
                std::string name, id, spec;
                int age;
                std::cout << "Enter Faculty Name: ";
                std::getline(std::cin, name);
                std::cout << "Enter Faculty ID: ";
                std::getline(std::cin, id);
                std::cout << "Enter Age: ";
                std::cin >> age;
                clearInputBuffer();
                std::cout << "Enter Specialization: ";
                std::getline(std::cin, spec);

                if (findFaculty(faculties, id) != nullptr)
                    throw DuplicateIDException();

                faculties.emplace_back(name, id, age, spec);
                std::cout << "Faculty added successfully.\n";
                break;
            }
            case 3: {
                std::string code, title, facultyID;
                std::cout << "Enter Course Code: ";
                std::getline(std::cin, code);
                std::cout << "Enter Course Title: ";
                std::getline(std::cin, title);
                std::cout << "Enter Faculty-in-charge ID: ";
                std::getline(std::cin, facultyID);

                if (findCourse(courses, code) != nullptr)
                    throw DuplicateIDException();

                Faculty* f = findFaculty(faculties, facultyID);
                if (!f)
                    throw NotFoundException("Faculty");

                courses.emplace_back(code, title, f);
                f->addCourse(code);
                std::cout << "Course added successfully.\n";
                break;
            }
            case 4: {
                std::string studentID, courseCode;
                std::cout << "Enter Student ID: ";
                std::getline(std::cin, studentID);
                std::cout << "Enter Course Code: ";
                std::getline(std::cin, courseCode);

                Student* s = findStudent(students, studentID);
                if (!s)
                    throw NotFoundException("Student");

                Course* c = findCourse(courses, courseCode);
                if (!c)
                    throw NotFoundException("Course");

                c->enrollStudent(s);
                s->addCourse(courseCode);
                std::cout << "Enrollment successful.\n";
                break;
            }
            case 5: {
                std::string studentID, courseCode;
                char grade;
                std::cout << "Enter Student ID: ";
                std::getline(std::cin, studentID);
                std::cout << "Enter Course Code: ";
                std::getline(std::cin, courseCode);
                std::cout << "Enter Grade (A-F): ";
                std::cin >> grade;
                clearInputBuffer();

                if (!findStudent(students, studentID))
                    throw NotFoundException("Student");
                if (!findCourse(courses, courseCode))
                    throw NotFoundException("Course");

                gradebook.addOrUpdateGrade(studentID, courseCode, grade);
                std::cout << "Grade assigned successfully.\n";
                break;
            }
            case 6: {
                std::string courseCode;
                std::cout << "Enter Course Code: ";
                std::getline(std::cin, courseCode);
                Course* c = findCourse(courses, courseCode);
                if (!c)
                    throw NotFoundException("Course");
                c->listStudents();
                break;
            }
            case 7: {
                std::string studentID;
                std::cout << "Enter Student ID: ";
                std::getline(std::cin, studentID);
                Student* s = findStudent(students, studentID);
                if (!s)
                    throw NotFoundException("Student");
                s->listCourses();
                break;
            }
            case 8: {
                std::string studentID;
                std::cout << "Enter Student ID: ";
                std::getline(std::cin, studentID);
                Student* s = findStudent(students, studentID);
                if (!s)
                    throw NotFoundException("Student");
                double gpa = gradebook.calculateGPA(studentID);
                std::cout << "GPA: " << gpa << std::endl;
                break;
            }
            case 9: {
                std::cout << "\nAll Students:\n";
                for (const auto& s : students)
                    s.display();
                break;
            }
            case 10: {
                std::cout << "\nAll Courses:\n";
                for (const auto& c : courses)
                    c.display();
                break;
            }
            case 0:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid option!\n";
            }
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    } while (choice != 0);

    return 0;
}
