#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 22, 45, 11};
    int n = sizeof(arr) / sizeof(arr[0]); 
    
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    
    double average = static_cast<double>(sum) / n;
    
    cout << "Average = " << average << endl;
    
    return 0;
}