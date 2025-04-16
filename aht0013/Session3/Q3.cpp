#include<iostream>
using namespace std;

int main() {
    int arr[] = {5, 6, 7, 2, 3, 4, 12};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int smallest, second_smallest;
    
    if(arr[0] < arr[1]) {
        smallest = arr[0];
        second_smallest = arr[1];
    } else {
        smallest = arr[1];
        second_smallest = arr[0];
    }
    
    for(int i = 2; i < n; i++) {
        if(arr[i] < smallest) {
            second_smallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i] < second_smallest && arr[i] != smallest) {
            second_smallest = arr[i];
        }
    }
    
    cout << "Original array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    cout << "\nSecond smallest number: " << second_smallest << endl;
    
    return 0;
}