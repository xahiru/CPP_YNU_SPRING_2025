#include <iostream>
#include <string>
using namespace std;

int main() {

    int sizeIntArray = 5;
    int* intArray = new int[sizeIntArray];

    for (int i = 0; i < sizeIntArray; ++i) {
        intArray[i] = (i + 1) * 10;
    }

    cout << "Integer array: ";
    for (int i = 0; i < sizeIntArray; ++i) {
        cout << intArray[i] << " ";
    }
    cout << endl;

    int sizeStrArray = 3;
    string* strArray = new string[sizeStrArray];


    strArray[0] = "Apple";
    strArray[1] = "Banana";
    strArray[2] = "Cherry";

    cout << "String array: ";
    for (int i = 0; i < sizeStrArray; ++i) {
        cout << strArray[i] << " ";
    }
    cout << endl;


    delete[] intArray;
    delete[] strArray;

    return 0;
}
