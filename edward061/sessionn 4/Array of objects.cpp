#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int age;

    Student(string n, int a) {
        name = n;
        age = a;
    }

    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    int n;

    cout << "Enter the number of students: ";
    cin >> n;

    Student* students = new Student[n] {
        Student("Alice", 20),  
        Student("Bob", 21),    
        Student("Charlie", 22) 
    };

    cout << "\nStudent Details:\n";
    for (int i = 0; i < n; ++i) {
        students[i].display(); 
    }

    delete[] students;

    return 0;
}