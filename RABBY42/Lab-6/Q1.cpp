#include <iostream>
#include <string>
using namespace std;

struct person {
    string name;
    int age;
    bool do_programming;
};

int main() {
    person p1 = {"alice", 20, true};
    person p2 = {"bob", 18, false};

    cout << p1.name << " (" << p1.age << ")" << endl;
    cout << p2.name << " (" << p2.age << ")" << endl;

    return 0;
}