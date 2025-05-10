#include <iostream>
#include <string>
using namespace std;

int main() {
    int *ptr1 = new int;
    *ptr1 = 5;

    char *ptr2 = new char;
    *ptr2 = 'a';

    string *ptr3 = new string;
    *ptr3 = "hello";

    cout << "Integer: " << *ptr1 << endl;
    cout << "Character: " << *ptr2 << endl;
    cout << "String: " << *ptr3 << endl;

    delete ptr1;
    delete ptr2;
    delete ptr3;

    return 0;
}
