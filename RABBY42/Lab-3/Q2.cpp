#include <iostream>
#include <climits>
using namespace std;

void findThreeLargest(int arr[], int size) {
    if (size < 3) {
        cout << "Array size is less than 3" << endl;
        return;
    }
    
    int first, second, third;
    first = second = third = INT_MIN;
    
    for (int i = 0; i < size; i++) {
        if (arr[i] > first) {
            third = second;
            second = first;
            first = arr[i];
        } else if (arr[i] > second) {
            third = second;
            second = arr[i];
        } else if (arr[i] > third) {
            third = arr[i];
        }
    }
    
    cout << "Three largest elements are: " << first << ", " << second << ", " << third << endl;
}

int main() {
    int arr[] = {7, 12, 9, 15, 19, 32, 56, 70};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    findThreeLargest(arr, size);
    
    return 0;
}