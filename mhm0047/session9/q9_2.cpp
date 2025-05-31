#include <iostream>
#include <string>
using namespace std;

class User {
private:
    string name;

public:
    User() : name("Default") {}
    User(const string& n) : name(n) {}

    void display() const {
        cout << name << endl;
    }
};

int main() {
    User u1;
    User u2("YNU");

    u1.display();
    u2.display();

    return 0;
}