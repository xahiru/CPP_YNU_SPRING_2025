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
    
    void swap(Person &other) {
        swap(name, other.name);
        swap(number, other.number);
        swap(height, other.height);
    }
};

int main() {
    Person obj1("Morty", 1234, 6);
    Person obj2("Rick", 5678, 5);
    
    obj1.display();
    obj2.display();
    
    obj1.swap(obj2);
    
    obj1.display();
    obj2.display();
    
    return 0;
}
