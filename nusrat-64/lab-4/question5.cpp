#include <iostream>
using namespace std;

int main() {

    int* num = new int;
    char* ch = new char;
    string* str = new string;

    *num = 10;
    *ch = 'A';
    *str = "Hello";

    cout << "Integer: " << *num << endl;
    cout << "Character: " << *ch << endl;
    cout << "String: " << *str << endl;

    delete num;
    delete ch;
    delete str;

    return 0;
}