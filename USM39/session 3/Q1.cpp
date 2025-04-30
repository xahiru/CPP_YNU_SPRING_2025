#include <iostream>
#include <climits>
using namespace std;

int findLargest(int arr[], int size) {
    int max = INT_MIN;
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int arr[] = {5, 4, 9, 12, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    cout << "The largest integer is: " << findLargest(arr, size) << endl;
    
    return 0;
}
