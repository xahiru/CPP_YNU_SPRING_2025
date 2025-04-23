#include <iostream>
#include <string>

class Student {
public:
    std::string name;
    int age;

    Student(std::string n, int a) : name(n), age(a) {
        std::cout << "Student " << name << " created." << std::endl;
    }

    void display() {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {
    int n;

    std::cout << "Enter the number of students: ";
    std::cin >> n;

    Student* students = new Student[n] {
        {"Alice", 20},
        {"Bob", 22},
        {"Charlie", 21}
    };
    for (int i = 0; i < n; ++i) {
        students[i].display();
    }

    delete[] students;

    return 0;
}
