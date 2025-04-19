#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 5, 5, 7, 8, 8, 9, 9, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    bool printed[100] = {false};
    
    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Repeating elements: ";
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j] && !printed[arr[i]]) {
                cout << arr[i] << " ";
                printed[arr[i]] = true;
                break;
            }
        }
    }

    return 0;
}