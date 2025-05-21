#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int arr[] = {7, 12, 9, 15, 19, 32, 56, 70};

    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + n, greater<int>());

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
}
    cout << endl;

    cout << "Three largest elements are: " << arr[0] << ", " << arr[1] << ", " << arr[2] << endl;

    return 0;
}