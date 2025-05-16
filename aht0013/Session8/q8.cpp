#include <iostream>
using namespace std;

template <typename T>
T findMax(T arr[], int n) {
    T maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal) maxVal = arr[i];
    return maxVal;
}

int main() {
    int k, n;
    cin >> n >> k;

    if (k == 1) {
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        cout << findMax(arr, n);
    } else {
        float arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        cout << findMax(arr, n);
    }
    return 0;
}