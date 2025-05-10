#include <iostream>
#include <climits>
using namespace std;

int findSecondSmallest(int arr[], int size) {
    int smallest = INT_MAX, secondSmallest = INT_MAX;
    
    for (int i = 0; i < size; i++) {
        if (arr[i] < smallest) {
            secondSmallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < secondSmallest && arr[i] != smallest) {
            secondSmallest = arr[i];
        }
    }
    
    return secondSmallest;
}

int main() {
    int arr[] = {5, 6, 7, 2, 3, 4, 12};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Second smallest number: " << findSecondSmallest(arr, size);
    return 0;
}