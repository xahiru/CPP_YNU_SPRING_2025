#include <iostream>
#include <cstring> x
using namespace std;

int main() {
    int sizeInt = 5; 
    int *intArray = new int[sizeInt]; 

    for (int i = 0; i < sizeInt; i++) {
        intArray[i] = (i + 1) * 10; 
    }

    int sizeStr = 3; 
    char **strArray = new char*[sizeStr]; 

    strArray[0] = new char[20]; 
    strcpy(strArray[0], "Hello");

    strArray[1] = new char[20]; 
    strcpy(strArray[1], "World");

    strArray[2] = new char[20]; 
    strcpy(strArray[2], "C++ Programming");

    cout << "Integer Array: ";
    for (int i = 0; i < sizeInt; i++) {
        cout << intArray[i] << " ";
    }
    cout << endl;

    cout << "String Array: ";
    for (int i = 0; i < sizeStr; i++) {
        cout << strArray[i] << " "; 
    }
    cout << endl;

    for (int i = 0; i < sizeStr; i++) {
        delete[] strArray[i];
    }
    delete[] strArray; 

    delete[] intArray; 

    return 0;
}