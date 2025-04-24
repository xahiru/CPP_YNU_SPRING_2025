#include <iostream>
#include <climits>
using namespace std;

int main() {
    int arr[] = {5, 6, 7, 2, 3, 4, 12};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int smallest = INT_MAX;
    int second_smallest = INT_MAX;
    
    for(int i = 0; i < size; i++) {
        if(arr[i] < smallest) {
            second_smallest = smallest;
            smallest = arr[i];
        } 
        else if(arr[i] < second_smallest && arr[i] != smallest) {
            second_smallest = arr[i];
        }
    }
    
    cout << "Original array: 5 6 7 2 3 4 12" << endl;
    cout << "Second smallest number: " << second_smallest << endl;
    
    return 0;
}

