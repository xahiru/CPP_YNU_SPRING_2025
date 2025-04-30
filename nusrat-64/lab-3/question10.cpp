#include <iostream>
using namespace std;

int sumArray(int arr[], int n) {
    if (n == 0)
        return 0;
    else
        return arr[n - 1] + sumArray(arr, n - 1);
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array elements:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    int sum = sumArray(arr, n);
    cout << "\nSum of array elements using recursion: " << sum << endl;

    return 0;
}