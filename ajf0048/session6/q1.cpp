#include <iostream>
#include <string>

struct Person {
    std::string name;
    int age;
    bool do_programming;
};

int main() {
    Person p1 = {"alice", 20, true};
    Person p2 = {"bob", 18, false};

    std::cout << p1.name << " (" << p1.age << ")" << std::endl;
    std::cout << p2.name << " (" << p2.age << ")" << std::endl;

    return 0;
}
