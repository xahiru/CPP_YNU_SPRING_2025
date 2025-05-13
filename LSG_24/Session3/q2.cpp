#include <iostream>
#include <climits>
using namespace std;

void findThreeLargest(int arr[], int size) {
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
    
    cout << "Three largest elements are: " << first << ", " << second << ", " << third;
}

int main() {
    int arr[] = {7, 12, 9, 15, 19, 32, 56, 70};
    int size = sizeof(arr) / sizeof(arr[0]);
    findThreeLargest(arr, size);
    return 0;
}