#include <iostream>
using namespace std;

int arraySum(int arr[], int n) {
    // Base case
    if (n <= 0) {
        return 0;
    }
    return arr[n-1] + arraySum(arr, n-1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Array elements:" << endl;
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    int sum = arraySum(arr, size);
    
    cout << "Sum of array elements using recursion: " << sum << endl;
    
    return 0;
}
