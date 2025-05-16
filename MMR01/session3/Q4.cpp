#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[] = {0, 1, 0, 0, 1, 1, 1, 0, 1, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << "Original array: ";
    for(int x : arr) cout << x << " ";
    
    // separate 0s and 1s
    sort(arr, arr + n);
    
    cout << "\nArray after divided: ";
    for(int x : arr) cout << x << " ";
    
    return 0;
}