#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 5, 7, 5, 8, 9, 11, 11, 2, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << "\nUnique elements of the said array: ";
    for (int i = 0; i < size; i++) {
        bool isUnique = true;

        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isUnique = false;
                break;
            }
        }

        if (isUnique) {
            cout << arr[i] << " ";
        }
    }

    cout << endl;
    return 0;
}