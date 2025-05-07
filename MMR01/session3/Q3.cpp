#include <iostream>
#include <climits>
using namespace std;

int main() {

    // Array Initialization and Printing

    int arr[] = {5, 7, 8, 1, 2, 10, 12};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << "Original array: ";
    for(int i=0; i<n; i++) cout << arr[i] << " ";
    
    int first = INT_MAX, second = INT_MAX;  //Initialization
    for(int i=0; i<n; i++) {
        if(arr[i] < first) {
            second = first;  // Current smallest becomes second smallest
            first = arr[i];   // New smallest found
        }
        else if(arr[i] < second && arr[i] != first) {
            second = arr[i]; // New second smallest found
        }
    }
    
    cout << "\nSecond smallest number: " << second;
    return 0;
}