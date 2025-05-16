#include <iostream>
#include <string>

struct person {
    std::string name;   
    int age;       
    bool do_programming; 
};

int main() {
    person p1;
    person p2;

    p1.name = "alice";
    p1.age = 20;
    p1.do_programming = true;

    p2.name = "bob";
    p2.age = 23;
    p2.do_programming = false;

    std::cout << p1.name << " (age " << p1.age << ") does programming: " << (p1.do_programming ? "Yes" : "No") << std::endl;
    std::cout << p2.name << " (age " << p2.age << ") does programming: " << (p2.do_programming ? "Yes" : "No") << std::endl;

    return 0;
}
