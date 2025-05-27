#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int number;
    int height;

public:
    Person(string n, int num, int h) : name(n), number(num), height(h) {}

    void display() {
        cout << name << " " << number << " " << height << endl;
    }

    friend void swap(Person& p1, Person& p2);
};

void swap(Person& p1, Person& p2) {
    Person temp = p1;
    p1 = p2;
    p2 = temp;
}

int main() {
    Person obj1("Morty", 1234, 6);
    Person obj2("Rick", 5678, 5);

    obj1.display();
    obj2.display();

    swap(obj1, obj2);

    obj1.display();
    obj2.display();

    return 0;
}
