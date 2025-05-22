#include <iostream>
#include <string>

// Create a structure named "person"
struct person {
    std::string name;
    int age;
    bool do_programming;
};

int main() {
    // Declare two objects "p1" and "p2"
    person p1;
    person p2;

    // Set values for p1
    p1.name = "alice";
    p1.age = 20;
    p1.do_programming = true;

    // Set values for p2
    p2.name = "bob";
    p2.age = 18;
    p2.do_programming = false;

    // Cout their informations
    std::cout << p1.name << " (" << p1.age << ")" << std::endl;
    std::cout << p2.name << " (" << p2.age << ")" << std::endl;

    return 0;
}