
#include <iostream>
#include <string>
using namespace std;

class User {
private:
    string name;
    int number;
    int height;
public:
    User(string n, int num, int h) : name(n), number(num), height(h) {}
    
    void display() {
        cout << name << " " << number << " " << height << endl;
    }
    
    void swap(User &other) {
        string tempName = name;
        int tempNum = number;
        int tempHeight = height;
        
        name = other.name;
        number = other.number;
        height = other.height;
        
        other.name = tempName;
        other.number = tempNum;
        other.height = tempHeight;
    }
};

int main() {
    string name1, name2;
    int num1, num2, height1, height2;
    
    cin >> name1 >> num1 >> height1;
    cin >> name2 >> num2 >> height2;
    
    User user1(name1, num1, height1);
    User user2(name2, num2, height2);
    
    user1.display();
    user2.display();
    
    user1.swap(user2);
    
    user1.display();
    user2.display();
    
    return 0;
}
