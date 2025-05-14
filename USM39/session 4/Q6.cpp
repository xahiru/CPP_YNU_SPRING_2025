#include <iostream>
#include <string>
using namespace std;

int main() {
    int size = 5;
    int *intArray = new int[size];
    string *strArray = new string[size];

    for (int i = 0; i < size; i++) {
        intArray[i] = i * 10;
        strArray[i] = "String " + to_string(i);
    }

    for (int i = 0; i < size; i++) {
        cout << intArray[i] << " " << strArray[i] << endl;
    }

    delete[] intArray;
    delete[] strArray;
    return 0;
}
