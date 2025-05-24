#include <iostream>
#include <string>
using namespace std;

class User {
private:
    string name;
    int number;
    int height;
public:
    void setDetails(string n, int num, int h) {
        name = n;
        number = num;
        height = h;
    }
    
    void display() {
        cout << name << " " << number << " " << height << endl;
    }
    
    void swap(User &other) {
        User temp = *this;
        *this = other;
        other = temp;
    }
};

int main() {
    User u1, u2;
    string name1, name2;
    int num1, num2, h1, h2;
    
    cin >> name1 >> num1 >> h1;
    cin >> name2 >> num2 >> h2;
    
    u1.setDetails(name1, num1, h1);
    u2.setDetails(name2, num2, h2);
    
    u1.display();
    u2.display();
    
    u1.swap(u2);
    
    u1.display();
    u2.display();
    
    return 0;
}
