#include <iostream>
#include <string>
using namespace std;

int main() {
    int size;

    cout << "Enter the number of elements: ";
    cin >> size;

    int* intArray = new int[size];
    string* strArray = new string[size];

    cout << "Enter " << size << " integers:\n";
    for (int i = 0; i < size; i++) {
        cin >> intArray[i];
    }

    cout << "Enter " << size << " strings:\n";
    cin.ignore(); 
    for (int i = 0; i < size; i++) {
        getline(cin, strArray[i]);
    }

    cout << "\nInteger array:\n";
    for (int i = 0; i < size; i++) {
        cout << intArray[i] << " ";
    }
    cout << "\n\nString array:\n";
    for (int i = 0; i < size; i++) {
        cout << strArray[i] << endl;
    }

    delete[] intArray;
    delete[] strArray;

    return 0;
}
