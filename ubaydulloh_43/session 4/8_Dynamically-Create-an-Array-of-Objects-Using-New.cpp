#include <iostream>
#include <cstring> 
using namespace std;

class Student {
public:
    char name[50];
    float grade;

    Student(const char* n, float g) {
        strcpy(name, n);
        grade = g;
    }

    void display() const {
        cout << "Name: " << name << ", Grade: " << grade << endl;
    }
};

int main() {
    int numStudents;

    cout << "Enter the number of students: ";
    cin >> numStudents;

    Student* students = new Student[numStudents];

    for (int i = 0; i < numStudents; i++) {
        char name[50];
        float grade;

        cout << "Enter name for student " << (i + 1) << ": ";
        cin >> name;
        cout << "Enter grade for student " << (i + 1) << ": ";
        cin >> grade;

        students[i] = Student(name, grade);
    }

    cout << "\nStudent Information:\n";
    for (int i = 0; i < numStudents; i++) {
        students[i].display();
    }

    delete[] students; 

    return 0;
}