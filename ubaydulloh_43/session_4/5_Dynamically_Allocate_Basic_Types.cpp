#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int *intPtr = new int;
    *intPtr = 42; 

    char *charPtr = new char;
    *charPtr = 'A'; 

    char *strPtr = new char[100]; 
    strcpy(strPtr, "Hello, World!"); 

    cout << "Dynamically allocated integer: " << *intPtr << endl;
    cout << "Dynamically allocated character: " << *charPtr << endl;
    cout << "Dynamically allocated string: " << strPtr << endl;

    delete intPtr;
    delete charPtr; 
    delete[] strPtr; 

    return 0;
}