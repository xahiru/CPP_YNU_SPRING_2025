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

    void display() const {
        cout << name << endl;
    }
};
int main() {
    string input;
    getline(cin, input);  

    User user1;           
    User user2(input);    

    user1.display();      
    user2.display();      

    return 0;
}

