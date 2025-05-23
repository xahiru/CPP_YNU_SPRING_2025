#include <iostream>
#include <string>
using namespace std;

class User {
private:
    string name;

public:
    // First constructor (no parameters)
    User() {
        name = "Default";
    }

    // Second constructor (with name parameter)
    User(string n) {
        name = n;
    }

    // Function to display the name
    void display() {
        cout << name << endl;
    }
};

int main() {
    // Create objects using both constructors
    User user1;         
    User user2("YNU");   

    // Display the names
    user1.display();   
    user2.display();    

    return 0;
}