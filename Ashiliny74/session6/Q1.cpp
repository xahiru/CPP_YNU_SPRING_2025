#include <iostream>
#include <string>
using namespace std;

struct person {
    string name;
    int age;
    bool do_programming;
};

int main() {
    person p1, p2;

    // Setting values for p1
    p1.name = "alice";
    p1.age = 20;
    p1.do_programming = true;

    // Setting values for p2
    p2.name = "bob";
    p2.age = 18;
    p2.do_programming = false;

    // Outputting information
    cout << p1.name << " (" << p1.age << ")" << endl;
    cout << p2.name << " (" << p2.age << ")" << endl;

    return 0;
}