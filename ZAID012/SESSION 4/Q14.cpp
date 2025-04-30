#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 11, 7, 8, 2, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int element = 19;
    bool found = false;

    for (int i = 0; i < size; ++i) {
        if (arr[i] == element) {
            cout << "Element found at index: " << i << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << element << " not found in the arr[]" << endl;
    }
    return 0;
}
