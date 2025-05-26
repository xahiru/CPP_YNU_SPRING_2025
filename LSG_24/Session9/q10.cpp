#include <iostream>
#include <string>
using namespace std;

class User {
private:
    string name;
public:
    User() {
        name = "Default";
    }
    User(string n) {
        name = n;
    }
    void display() {
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