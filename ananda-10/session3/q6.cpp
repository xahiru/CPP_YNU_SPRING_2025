#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 5, 5, 7, 8, 8, 9, 9, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int count[100] = {0};  

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
        count[arr[i]]++;
    }

    cout << "\nRepeating elements: ";
    for (int i = 0; i < 100; i++) {
        count[i] > 1 ? cout << i << " " : cout << "";
    }

    cout << endl;
    return 0;
}
