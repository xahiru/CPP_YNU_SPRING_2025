#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;
    int number;
    int height;
    
    void set(string n, int num, int h) {
        name = n;
        number = num;
        height = h;
    }
    void display() {
        cout << name << " " << number << " " << height << endl;
    }
    static void swap(Person &a, Person &b) {
        Person temp = a;
        a = b;
        b = temp;
    }
};

int main() {
    Person p1, p2;
    string n1, n2;
    int num1, num2, h1, h2;
    
    cin >> n1 >> num1 >> h1;
    cin >> n2 >> num2 >> h2;
    
    p1.set(n1, num1, h1);
    p2.set(n2, num2, h2);
    
    p1.display();
    p2.display();
    
    Person::swap(p1, p2);
    
    p1.display();
    p2.display();
    
    return 0;
}