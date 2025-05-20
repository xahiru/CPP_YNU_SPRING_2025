#include <iostream>
#include <string>  
using namespace std;

int main() {

    int *ptrInt = new int;
    *ptrInt = 42;  


    char *ptrChar = new char;
    *ptrChar = 'A';  

    string *ptrString = new string;
    *ptrString = "Hello, Dynamic Allocation!";  

    cout << "Integer value: " << *ptrInt << endl;
    cout << "Character value: " << *ptrChar << endl;
    cout << "String value: " << *ptrString << endl;

    delete ptrInt;
    delete ptrChar;
    delete ptrString;

    return 0;
}