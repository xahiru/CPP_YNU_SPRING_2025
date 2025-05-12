#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 11, 7, 8, 2, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 19;
    bool found = false;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            cout << target << " found at index " << i << endl;
            found = true;
            break;
        }
    }
    
    if (!found) {
        cout << target << " not found in the arr[]" << endl;
    }
    return 0;
}