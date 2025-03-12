#include <iostream>
using namespace std;

int main() {
    int age = 18;

    // if this condition is true child is printed
    if (age < 13) {
        cout << "child";
    }
 
    // if above above if statement is not true then we check
    // this else if condition if it evalutes to true print
    // growing age
    else if (age >= 1 and age <= 18) {
        cout << "Growing stage";
    }

    // if none of above condition is true print adult
    else {
        cout << "adult";
    }
    return 0;
}
