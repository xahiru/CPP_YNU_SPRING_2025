#include <iostream> using namespace std; int main() { 
     int arr[] = {5, 4, 9, 12, 8}; 
     int n = sizeof(arr) / sizeof(arr[0]); 
    
     int largest = arr[0]; 

     for (int i = 1; i < n; i++) { if (arr[i] > largest) { largest = arr[i]; } } 
    
     cout << "The largest integer is: " << largest << endl;
      
     return 0; 
}
