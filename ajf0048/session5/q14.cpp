#include <iostream>
using namespace std;

void doubleValues(int& value) {
    value *= 2;
}

int main() {
    int arr[] = {1, 2, 3};
    cout << "Array: [";
    for (int i = 0; i < 3; ++i) {
        cout << arr[i] << (i < 2 ? ", " : "");
    }
    cout << "]" << endl;

    for (int& value : arr) {
        doubleValues(value);
    }

    cout << "Doubled Array: [";
    for (int i = 0; i < 3; ++i) {
        cout << arr[i] << (i < 2 ? ", " : "");
    }
    cout << "]" << endl;

    return 0;
}