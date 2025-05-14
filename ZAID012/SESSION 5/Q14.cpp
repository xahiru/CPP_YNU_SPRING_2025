#include <iostream>
using namespace std;

void doubleValues(int& val) {
    val *= 2;
}

int main() {
    int arr[] = {1, 2, 3};
    cout << "Array: [";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << "]" << endl;

    for (int& val : arr) {
        doubleValues(val);
    }

    cout << "Doubled Array: [";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << "]" << endl;

    return 0;
}