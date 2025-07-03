#include <iostream>
#include <string>
using namespace std;

class Swap {
private:
    string name;
    int number;
    double height;
public:
    Swap(string n, int num, double h) : name(n), number(num), height(h) {}
    void display() {
        cout << name << " " << number << " " << height << endl;
    }
    friend void swapObjects(Swap& a, Swap& b);
};

void swapObjects(Swap& a, Swap& b) {
    swap(a.name, b.name);
    swap(a.number, b.number);
    swap(a.height, b.height);
}

int main() {
    Swap obj1("Morty", 1234, 6), obj2("Rick", 5678, 5);
    obj1.display(); // Morty 1234 6
    obj2.display(); // Rick 5678 5
    swapObjects(obj1, obj2);
    obj1.display(); // Rick 5678 5
    obj2.display(); // Morty 1234 6
    return 0;
}