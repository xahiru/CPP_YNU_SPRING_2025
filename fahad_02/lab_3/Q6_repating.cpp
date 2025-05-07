#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 5, 5, 7, 8, 8, 9, 9, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nRepeating elements: ";

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                bool alreadyPrinted = false;
                for (int k = 0; k < i; k++) {
                    if (arr[k] == arr[i]) {
                        alreadyPrinted = true;
                        break;
                    }
                }
                if (!alreadyPrinted) {
                    cout << arr[i] << " ";
                }
                break;
            }
        }
    }

    cout << endl;
    return 0;
}
