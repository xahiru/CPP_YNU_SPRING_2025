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
    int K, n;
    cin >> n >> K;
    if (K == 1) {
        int arr[10000];
        for (int i = 0; i < n; i++) cin >> arr[i];
        cout << findLargest(arr, n) << endl;
    } else if (K == 2) {
        float arr[10000];
        for (int i = 0; i < n; i++) cin >> arr[i];
        cout << findLargest(arr, n) << endl;
    }
    return 0;
}
