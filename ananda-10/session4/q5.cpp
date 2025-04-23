#include <iostream>
#include <string>
using namespace std;

int main() {
    int* intPtr = new int;
    char* charPtr = new char;
    string* strPtr = new string;

    *intPtr = 42;
    *charPtr = 'A';
    *strPtr = "Hello, dynamic memory!";

    cout << "Integer: " << *intPtr << endl;
    cout << "Character: " << *charPtr << endl;
    cout << "String: " << *strPtr << endl;

    delete intPtr;
    delete charPtr;
    delete strPtr;

    return 0;
}

