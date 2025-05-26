#include <iostream>
#include <string>
using namespace std;

class User {
private:
    string name;

public:
    User() : name("Default") {}
    User(string n) : name(n) {}

    void display() {
        cout << name << endl;
    }
};

int main() {
    User user1;
    User user2("YNU");

    user1.display();
    user2.display();

    return 0;
}