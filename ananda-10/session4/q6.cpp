#include <iostream>
#include <string>
using namespace std;

int main() {
    int size = 3;

    // Dynamically allocate array of integers
    int* intArray = new int[size];
    intArray[0] = 10;
    intArray[1] = 20;
    intArray[2] = 30;

    // Dynamically allocate array of strings
    string* strArray = new string[size];
    strArray[0] = "Apple";
    strArray[1] = "Banana";
    strArray[2] = "Cherry";

    // Print integer array
    cout << "Integer array: ";
    for (int i = 0; i < size; i++) {
        cout << intArray[i] << " ";
    }
    cout << endl;

    // Print string array
    cout << "String array: ";
    for (int i = 0; i < size; i++) {
        cout << strArray[i] << " ";
    }
    cout << endl;

    // Free memory
    delete[] intArray;
    delete[] strArray;

    return 0;
}

