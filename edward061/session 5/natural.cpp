#include <iostream>
using namespace std;

int main() {
    int n;
    int sum = 0;

    cout << "Input number of terms: ";
    cin >> n;
    
    cout << "The odd numbers are: ";

    for (int i = 1; n > 0; i += 2) {
        cout << i << " ";  
        sum += i;          
        n--;               
    }
    
    cout << endl;  

    cout << "The Sum of odd Natural Numbers upto " << n + sum / 2 << " terms: " << sum << endl;

    return 0;
}