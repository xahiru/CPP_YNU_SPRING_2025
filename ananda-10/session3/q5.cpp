#include <iostream>
#include <algorithm>  
using namespace std;

int main() {
    int arr[] = {0, 1, 2, 2, 1, 1, 0, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + n);
    cout << "Array elements after rearranging: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
