#include <iostream>
using namespace std;

int calculateOddSum(int terms) {
    int total = 0;
    cout << "The odd numbers are:";
    for (int current = 1, count = 0; count < terms; current += 2, ++count) {
        cout << " " << current;
        total += current;
    }
    return total;
}

int main() {
    int numTerms;
    
    cout << "Enter how many odd numbers to sum: ";
    cin >> numTerms;
    
    int result = calculateOddSum(numTerms);
    
    cout << "\nThe Sum of first " << numTerms 
         << " odd natural numbers is: " << result << endl;
    
    return 0;
}