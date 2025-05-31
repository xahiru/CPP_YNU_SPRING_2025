#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string name;
    int number;
    int height;

public:
    void setData(string n, int num, int h) {
        name = n;
        number = num;
        height = h;
    }

    void display() {
        cout << name << " " << number << " " << height << endl;
    }

    friend void swapObjects(Person &a, Person &b);
};

void swapObjects(Person &a, Person &b) {
    Person temp = a;
    a = b;
    b = temp;
}

int main() {
    Person obj1, obj2;
    string name1, name2;
    int num1, num2, height1, height2;

    cin >> name1 >> num1 >> height1;
    cin >> name2 >> num2 >> height2;

    obj1.setData(name1, num1, height1);
    obj2.setData(name2, num2, height2);
    obj1.display();
    obj2.display();

    swapObjects(obj1, obj2);

    obj1.display();
    obj2.display();
    

    return 0;

}