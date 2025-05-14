#include <iostream>
#include <string>
using namespace std;

// Define the structure 'person'
struct person {
    string name;
    int age;
    bool do_programming;
};

int main() {
    // Create two person objects
    person p1 = {"alice", 20, true};
    person p2 = {"bob", 18, false};

    // Output their information in the specified format
    cout << p1.name << " (" << p1.age << ")\n";
    cout << p2.name << " (" << p2.age << ")\n";

    return 0;
}
