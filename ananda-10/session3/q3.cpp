#include <iostream>
#include <algorithm>  
using namespace std;

int main() {
    int arr[] = {5, 6, 7, 2, 3, 4, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    nth_element(arr, arr + 1, arr + n);
    
    cout << "Second smallest number: " << arr[1] << endl; 
    return 0;
}
