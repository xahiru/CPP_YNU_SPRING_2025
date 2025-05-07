#include <iostream>
#include <string>
using namespace std;

int main() {
    int *intPtr = new int;
    char *charPtr = new char;
    string *strPtr = new string;

    *intPtr = 10;
    *charPtr = 'A';
    *strPtr = "Hello";

    cout << *intPtr << " " << *charPtr << " " << *strPtr << endl;

    delete intPtr;
    delete charPtr;
    delete strPtr;
    return 0;
}
