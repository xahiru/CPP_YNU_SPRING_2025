#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Enter a string with multiple words: ";
    
    getline(cin, s);
    
    cout << "Output: " << s << endl;
    
    return 0;
}
