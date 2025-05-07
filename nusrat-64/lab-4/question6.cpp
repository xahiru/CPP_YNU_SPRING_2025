#include <iostream>
using namespace std;

int main() {
    int size = 5;

    int* numbers = new int[size];

    for(int i = 0; i < size; i++) {
        numbers[i] = (i + 1) * 10;
    }

    cout << "Integer array: ";
    for(int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    string* words = new string[size];

    words[0] = "apple";
    words[1] = "banana";
    words[2] = "cherry";
    words[3] = "date";
    words[4] = "elder";

    cout << "String array: ";
    for(int i = 0; i < size; i++) {
        cout << words[i] << " ";
    }
    cout << endl;

    delete[] numbers;
    delete[] words;

    return 0;
}