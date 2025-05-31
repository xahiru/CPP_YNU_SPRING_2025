#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array: [";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i != n - 1) cout << ", ";
    }
    cout << "]" << endl;
q15.cpp

    for (int& val : arr) {
        val *= 2;
    }

    cout << "Doubled Array: [";
    for (int val : arr) {
        cout << val;
        if (&val != &arr[n - 1]) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
