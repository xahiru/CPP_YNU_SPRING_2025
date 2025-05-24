#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int number;
    int height;

public:
    // Constructor to initialize the object
    Person(string n = "", int num = 0, int h = 0) {
        name = n;
        number = num;
        height = h;
    }

    // Function to display person's information
    void display() {
        cout << name << " " << number << " " << height << endl;
    }

    // Friend function to swap two Person objects
    friend void swapObjects(Person &p1, Person &p2);
};

// Function to swap two Person objects
void swapObjects(Person &p1, Person &p2) {
    // Swap name
    string tempName = p1.name;
    p1.name = p2.name;
    p2.name = tempName;

    // Swap number
    int tempNum = p1.number;
    p1.number = p2.number;
    p2.number = tempNum;

    // Swap height
    int tempHeight = p1.height;
    p1.height = p2.height;
    p2.height = tempHeight;
}

int main() {
    string name1, name2;
    int num1, num2;
    int height1, height2;

    // Read input for first person
    cin >> name1 >> num1 >> height1;
    // Read input for second person
    cin >> name2 >> num2 >> height2;

    // Create two Person objects
    Person p1(name1, num1, height1);
    Person p2(name2, num2, height2);

    // Display original objects
    p1.display();
    p2.display();

    // Swap the objects
    swapObjects(p1, p2);

    // Display swapped objects
    p1.display();
    p2.display();

    return 0;
}