#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string name;
    int age;

public:

    Person() : name("Unknown"), age(0) {}

    // take user information
    void input() {
        cout << "Enter name: ";
        getline(cin >> ws, name); 
        cout << "Enter age: ";
        cin >> age;
    }
  //display information
    void display() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    
    int size;
    cout << "How many persons? ";
    cin >> size;

    // Dynamically allocate array of Person objects
    Person* people = new Person[size];

    for (int i = 0; i < size; ++i) {
        cout << "\nEnter details for Person " << (i + 1) << ":\n";
        people[i].input();
    }

    cout << "\n--- Displaying Information ---\n";
    for (int i = 0; i < size; ++i) {
        cout << "Person " << (i + 1) << ": ";
        people[i].display();
    }


    delete[] people;

    return 0;
}
