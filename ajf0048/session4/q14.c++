#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 11, 7, 8, 2, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int elementToSearch = 19;
    bool found = false;

    for (int i = 0; i < size; ++i) {
        if (arr[i] == elementToSearch) {
            cout << elementToSearch << " found at index " << i << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << elementToSearch << " not found in the arr[]" << endl;
    }

    return 0;
}