#include <iostream>
#include <string>
using namespace std;

class Swap {
private:
    string name;
    int number;
    int height;

public:
    Swap(string n, int num, int h) : name(n), number(num), height(h) {}

    void display() {
        cout << name << " " << number << " " << height << endl;
    }

    void swap(Swap &other) {
        swap(name, other.name);
        swap(number, other.number);
        swap(height, other.height);
    }
};

int main() {
    Swap obj1("Morty", 1234, 6);
    Swap obj2("Rick", 5678, 5);

    obj1.display();
    obj2.display();

    obj1.swap(obj2);

    obj1.display();
    obj2.display();

    return 0;
}