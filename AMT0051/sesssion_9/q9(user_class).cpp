#include <iostream>
#include <string>
using namespace std;

class User {
private:
    string name;
public:
    User() : name("Default") {}
    User(string n) : name(n) {}
    
    string getName() {
        return name;
    }
};

int main() {
    string input;
    cin >> input;
    
    User defaultUser;
    User customUser(input);
    
    cout << defaultUser.getName() << endl;
    cout << customUser.getName() << endl;
    
    return 0;
}