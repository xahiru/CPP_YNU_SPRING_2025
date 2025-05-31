#include <iostream>
using namespace std;

template<typename T>
T findLargest(T arr[], int n) {
    T max = arr[0];
    for (int i = 1; i < n; ++i)
        if (arr[i] > max) max = arr[i];
    return max;
}

int main() {
    int n, k; cin >> n >> k;
    if (k == 1) {
        int arr[n]; for (int& x : arr) cin >> x;
        cout << findLargest(arr, n);
    } else {
        float arr[n]; for (float& x : arr) cin >> x;
        cout << findLargest(arr, n);
    }
}