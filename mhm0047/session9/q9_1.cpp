#include <iostream>
#include <string>
using namespace std;

class User {
private:
    string name;
    int number;
    int height;

public:
    User(const string& n, int num, int h) 
        : name(n), number(num), height(h) {}

    void display() const {
        cout << name << " " << number << " " << height << endl;
    }

    void swap(User& other) {
        std::swap(name, other.name);
        std::swap(number, other.number);
        std::swap(height, other.height);
    }
};

int main() {
    User u1("Morty", 1234, 6);
    User u2("Rick", 5678, 5);

    u1.display();
    u2.display();

    u1.swap(u2);

    u1.display();
    u2.display();

    return 0;
}