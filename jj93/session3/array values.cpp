#include <iostream>
using namespace std;

int main() {

    int arr[] = {0, 1, 0, 0, 1, 1, 1, 0, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    int left = 0, right = n - 1;

    while (left < right) {

        if (arr[left] == 0) {
            left++;
        }

        else if (arr[right] == 1) {
            right--;
        }
    
        else {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Array after divided: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}