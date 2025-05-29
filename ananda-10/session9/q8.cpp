#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int number;
    int height;

public:

    Person(string n = "", int num = 0, int h = 0) {
        name = n;
        number = num;
        height = h;
    }
    void input() {
        cin >> name >> number >> height;
    }

    void display() const {
        cout << name << " " << number << " " << height << endl;
    }

    friend void swap(Person &a, Person &b);
};

void swap(Person &a, Person &b) {
    Person temp = a;
    a = b;
    b = temp;
}
int main() {
    Person obj1, obj2;

    obj1.input();
    obj2.input();

    obj1.display();
    obj2.display();

    swap(obj1, obj2);
    obj1.display();
    obj2.display();

    return 0;
}

