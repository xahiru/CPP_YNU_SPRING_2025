#include <iostream>
#include <string>
using namespace std;

class Student {
    string name;
    int id;
public:
    Student(string n = "Unknown", int i = 0) : name(n), id(i) {}
    void setData(string n, int i) { name = n; id = i; }
    void display() const { cout << "Name: " << name << ", ID: " << id << endl; }
};

int main() {
    int size;
    cout << "Enter number of students: ";
    cin >> size;

    Student* students = new Student[size];
    
    for (int i = 0; i < size; i++) {
        string name;
        int id;
        cout << "Student " << i + 1 << " Name: ";
        cin.ignore(1, '\n');
        getline(cin, name);
        cout << "ID: ";
        cin >> id;
        students[i].setData(name, id);
    }

    cout << "\nStudents:\n";
    for (int i = 0; i < size; i++) {
        students[i].display();
    }

    delete[] students;
    return 0;
}