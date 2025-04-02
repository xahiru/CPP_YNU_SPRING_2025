#include <iostream>

using namespace std;

bool isPrime(int n)    //function to check if its prime number
 {
    if (n < 2) return false; 
    
    for (int i = 2; i * i <= n; i++) { //loop from 2 to the square root of n
        if (n % i == 0)                //if n dividedd by i is not 0 its not prime
            return false;

    }


    return true;                  // if no diveder is found its a prime number
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isPrime(num)){
        cout << num << " is a prime number.\n";
    }
    else{
        cout << num << " is not a prime number.\n";
    }




    return 0;
}
