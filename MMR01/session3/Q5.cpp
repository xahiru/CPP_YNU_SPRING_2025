#include <iostream>
using namespace std;

int main() {
    int arr[] = {0, 1, 2, 2, 1, 1, 0, 0, 1}, n = 9;
    int count[3] = {0};
    
    cout << "Original array: ";
    //Counting Phase
    for (int x : arr) {
        cout << x << " ";
        count[x]++;
    }
    
    cout << "\nArray elements after rearranging: ";

    //Reconstruction Phase
    for (int i = 0; i < 3; i++)
        while (count[i]--) 
            cout << i << " ";
    
    return 0;
}