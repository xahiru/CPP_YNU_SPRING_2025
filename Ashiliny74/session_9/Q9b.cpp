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
    string input;
    getline(cin, input);
    
    User u1;
    u1.display();
    
    User u2(input);
    u2.display();
    
    return 0;
}