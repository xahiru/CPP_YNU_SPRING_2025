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

    void display() const {
        cout << name << " " << number << " " << height << endl;
    }

    friend void swap(Person &a, Person &b);
};

void swap(Person &a, Person &b) {
    swap(a.name, b.name);
    swap(a.number, b.number);
    swap(a.height, b.height);
}

int main() {
    string name1, name2;
    int num1, num2, h1, h2;

    cin >> name1 >> num1 >> h1;
    Person p1(name1, num1, h1);

    cin >> name2 >> num2 >> h2;
    Person p2(name2, num2, h2);

    p1.display();
    p2.display();

    swap(p1, p2);

    p1.display();
    p2.display();

    return 0;
}