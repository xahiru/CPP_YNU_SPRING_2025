#include <iostream>
using namespace std;

int main() {
    cout<<"input a number :";
    ios_base::sync_with_stdio(false);

    cin.tie(NULL);
    int n;
    cin >> n;
    
    // Ultra-fast lookup and output
    const char* word = "Greater than 9";
    if (n >= 1 && n <= 9) {
        const char* words[] = {"one","two","three","four","five",
                              "six","seven","eight","nine"};
        word = words[n-1];
        cout << word << '\n' << "Explanation: " << n << " is written as '" << word << "' in English.";
    } else {
        cout << word << '\n' << "Explanation: " << n << " is greater than 9.";
    }
    
    return 0;
}