#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

template <typename T>
void sortAndPrint(T arr[], int n) {
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main() {
    int n, q;
    cin >> n >> q;

    if (q == 1) {
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        sortAndPrint(arr, n);
    } else if (q == 2) {
        string arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        sortAndPrint(arr, n);
    } else {
        float arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        sortAndPrint(arr, n);
    }
    return 0;
}