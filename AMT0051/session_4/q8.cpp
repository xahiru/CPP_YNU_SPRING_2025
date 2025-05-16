#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int id;

public:
    // Default constructor
    Student() {
        name = "Unknown";
        id = 0;
    }

    Student(string n, int i) {
        name = n;
        id = i;
    }

    void setData(string n, int i) {
        name = n;
        id = i;
    }

    void display() {
        cout << "ID: " << id << ", Name: " << name << endl;
    }
};

int main() {
    int size = 3;

    Student* students = new Student[size];

    students[0].setData("Alice", 101);
    students[1].setData("Bob", 102);
    students[2].setData("Charlie", 103);

    cout << "Student Information:" << endl;
    for (int i = 0; i < size; ++i) {
        students[i].display();
    }
    
    delete[] students;

    return 0;
}
