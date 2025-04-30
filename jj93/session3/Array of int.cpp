#include <iostream>
using namespace std;

int main() {

    float arr[] = {5, 4, 9, 12.8}; 
    
    
    int n = sizeof(arr) / sizeof(arr[0]);
    

    float largest = arr[0];
    
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    
    // Output the largest element
    cout << "The largest element is: " << largest << endl;
    
    return 0;
}