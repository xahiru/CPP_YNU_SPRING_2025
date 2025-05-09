#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int age;
    float gpa;
    
    void display() {
        cout << "Name: " << name << ", Age: " << age << ", GPA: " << gpa << endl;
    }
};

int main() {
    int size = 2; // Fixed size for brevity
    
    Student* students = new Student[size]{
        {"Alice Johnson", 20, 3.8f},
        {"Bob Smith", 21, 3.5f}
    };

    cout << "Student Information:\n";
    for (int i = 0; i < size; i++)
        students[i].display();

    delete[] students;
    return 0;
}