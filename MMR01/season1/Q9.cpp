#include <iostream>
using namespace std;

int main() {
    int year;
    
    cout << "Enter a year: "; //ask user to enter a year
    cin >> year;
    
    if ((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0)) //condition
    { 
        cout << year << " is a Leap Year" << endl;
    } else {
        cout << year << " is not a Leap Year" << endl;
    }
    
    return 0;
}