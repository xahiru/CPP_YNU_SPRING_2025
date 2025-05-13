#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 22, 45, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    double sum = 0;
    
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    
    cout << "Average = " << sum/n << endl;
    return 0;
}