#include <iostream>
#include <string>  
using namespace std;

int main() {
    int sizeInt, sizeStr;
    
    cout << "Enter the size of the integer array: ";
    cin >> sizeInt;
    int *intArray = new int[sizeInt];  

    for (int i = 0; i < sizeInt; ++i) {
        intArray[i] = (i + 1) * 10;  
    }

    cout << "Enter the size of the string array: ";
    cin >> sizeStr;
    string *strArray = new string[sizeStr];  

    for (int i = 0; i < sizeStr; ++i) {
        strArray[i] = "String " + to_string(i + 1);  
    }

    cout << "\nInteger array elements: ";
    for (int i = 0; i < sizeInt; ++i) {
        cout << intArray[i] << " ";
    }
    cout << endl;

    cout << "String array elements: ";
    for (int i = 0; i < sizeStr; ++i) {
        cout << strArray[i] << " ";
    }
    cout << endl;

    delete[] intArray;
    delete[] strArray;

    return 0;
}