#include<iostream>

using namespace std;

bool isPalindrome(int n){
    int original = n;
    int reversed = 0;
    while(n>0){
        reversed = reversed * 10 + (n%10); //remove last dignt and reverse the number
        n/=10;                             // remove the last digit from original number 

    }
    return original == reversed; // check if original and reversed num are same 

}

int main(){
    int num;
    cout << "Enter a number:"<<endl;
    cin>> num;

    if (isPalindrome(num))
        cout << num << " is a palindrome.\n";
    else
        cout << num << " is not a palindrome.\n";

    return 0;

}