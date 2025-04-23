#include <iostream>
#include <string>

class Student {
public:
    // Member variables
    std::string name;
    int age;

    // Constructor to initialize the Student object
    Student(const std::string& name, int age) : name(name), age(age) {}

    // Method to display student information
    void display() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {
    int n;

    // Input the number of students
    std::cout << "Enter the number of students: ";
    std::cin >> n;

    // Dynamically create an array of Student objects
    Student* students = new Student[n]; // Allocate memory for n Student objects

    // Initialize the Student objects
    for (int i = 0; i < n; i++) {
        std::string name;
        int age;

        std::cout << "Enter name for student " << (i + 1) << ": ";
        std::cin >> name;
        std::cout << "Enter age for student " << (i + 1) << ": ";
        std::cin >> age;

        // Use the constructor to initialize the object
        students[i] = Student(name, age);
    }

    // Display the information of all students
    std::cout << "\nStudent Information:\n";
    for (int i = 0; i < n; i++) {
        students[i].display();
    }

    // Deallocate the memory
    delete[] students; // Free the memory allocated for the array of Student objects

    return 0;
}