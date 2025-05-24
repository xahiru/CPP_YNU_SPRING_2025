#include <iostream>
#include <cstring>
using namespace std;

int main() {

    int* intPtr = new int;
    *intPtr = 42;

    char* charPtr = new char;
    *charPtr = 'A';

    char* strPtr = new char[100];
    strcpy(strPtr, "Hello, world!");

    cout << "Integer value: " << *intPtr << endl;
    cout << "Character value: " << *charPtr << endl;
    cout << "String value: " << strPtr << endl;

    delete intPtr;
    delete charPtr;
    delete[] strPtr;

    return 0;
}
