#include <iostream>
#include <cmath>  //for sqrt() function
using namespace std;

int main() {
    int num;
    bool prime = true;  //assume number is prime initially
    
    cout << "Enter a number: ";
    cin >> num;
    
    if (num <= 1) prime = false;      //0 and 1 are not prime
    else if (num == 2) prime = true;  //2 is prime
    else if (num % 2 == 0) prime = false; //even numbers > 2 aren't prime
    else {
        
        for (int i = 3; i <= sqrt(num); i += 2) //check divisors from 3 up to sqrt(num)
         {
            if (num % i == 0) {
                prime = false;  //found a divisor
                break;          
            }
        }
    }
    
    if (prime) {
        cout << num << " is a prime number." << endl;
    } else {
        cout << num << " is not a prime number." << endl;
    }
    
    return 0;
}