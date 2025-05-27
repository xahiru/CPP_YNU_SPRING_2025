#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int number;
    int height;
public:
    void setDetails(string n, int num, int h) {
        name = n;
        number = num;
        height = h;
    }
    void display() {
        cout << name << " " << number << " " << height << endl;
    }
    void swap(Person &other) {
        string tempName = name;
        int tempNum = number;
        int tempHeight = height;
        
        name = other.name;
        number = other.number;
        height = other.height;
        
        other.name = tempName;
        other.number = tempNum;
        other.height = tempHeight;
    }
};

int main() {
    Person p1, p2;
    p1.setDetails("Morty", 1234, 6);
    p2.setDetails("Rick", 5678, 5);
    
    p1.display();
    p2.display();
    
    p1.swap(p2);
    
    p1.display();
    p2.display();
    
    return 0;
}