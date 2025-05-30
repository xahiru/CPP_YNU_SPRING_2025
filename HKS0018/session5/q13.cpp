#include <iostream>

using namespace std;

int main() {
    int arr[] = {1, 2, 3};

    cout << "Array: [";
    for (size_t i = 0; i < 3; ++i) {
        cout << arr[i];
        if (i < 2) cout << ", ";
    }
    cout << "]" << endl;

    // Doubling each value using reference in range-based loop
    for (int &x : arr) {
        x *= 2;
    }

    cout << "Doubled Array: [";
    for (size_t i = 0; i < 3; ++i) {
        cout << arr[i];
        if (i < 2) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
