#include <iostream>
using namespace std;

template <typename T>
T findLargest(T arr[], int n) {
    T largest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    return largest;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    if (k == 1) {
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        cout << findLargest(arr, n) << endl;
    }
    else if (k == 2) {
        float arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        cout << findLargest(arr, n) << endl;
    }
    
    return 0;
}