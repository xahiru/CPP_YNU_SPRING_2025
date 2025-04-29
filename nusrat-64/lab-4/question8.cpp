#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int age;

    void getData() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
    }

    void showData() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student* arr = new Student[n];

    for (int i = 0; i < n; i++) {
        cout << "\nStudent " << i + 1 << ":\n";
        arr[i].getData();
    }

    cout << "\nStudent Information:\n";
    for (int i = 0; i < n; i++) {
        arr[i].showData();
    }

    delete[] arr;

    return 0;
}