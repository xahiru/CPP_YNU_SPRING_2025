#include <iostream>
#include <string>
using namespace std;

int main() {
    int* intPtr = new int(10);
    char* charPtr = new char('A');
    string* strPtr = new string("Hello");

    cout << "Integer: " << *intPtr << endl;
    cout << "Character: " << *charPtr << endl;
    cout << "String: " << *strPtr << endl;

    delete intPtr;
    delete charPtr;
    delete strPtr;

    return 0;
}
