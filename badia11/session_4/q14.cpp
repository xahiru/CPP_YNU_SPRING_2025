#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {10, 11, 7, 8, 2, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 19;
    
    int result = linearSearch(arr, n, x);
    if (result == -1) {
        cout << x << " not found in the arr[]" << endl;
    } else {
        cout << x << " found at index " << result << endl;
    }
    return 0;
}
