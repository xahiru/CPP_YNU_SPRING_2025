#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;
    int age;

    void setDetails(string n, int a) {
        name = n;
        age = a;
    }

    void display() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    int size = 3;

    Person* people = new Person[size];

    people[0].setDetails("Ajel", 23);
    people[1].setDetails("Yang", 21);
    people[2].setDetails("Zhao", 22);

    cout << "People info:" << endl;
    for (int i = 0; i < size; ++i) {
        people[i].display();
    }

    delete[] people;

    return 0;
}

