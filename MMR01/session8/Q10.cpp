#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

template <typename T>
void sortArray(T arr[], int n) {
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main() {
    int n;
    cin >> n;
    char type;
    cin >> type;
    if (type == 'i') {
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        sortArray(arr, n);
    } else if (type == 'f') {
        float arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        sortArray(arr, n);
    } else if (type == 's') {
        string arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        sortArray(arr, n);
    }
    return 0;
}