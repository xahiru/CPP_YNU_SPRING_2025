#include <iostream>
using namespace std;

template <typename T>
T findMax(T arr[], int n) {
    T max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

int main() {
    int n, K;
    cin >> n >> K;
    if (K == 1) {
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        cout << findMax(arr, n);
    } else if (K == 2) {
        float arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        cout << findMax(arr, n);
    }
    return 0;
}