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
    string input;
    cin >> input;
    
    User u1;
    User u2(input);
    
    u1.display();
    u2.display();
    
    return 0;
}
