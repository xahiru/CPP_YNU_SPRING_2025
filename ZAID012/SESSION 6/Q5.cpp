#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    
    string reversed = "";
    
    for (int i = s.length() - 1; i >= 0; i--) {
        reversed += s[i];
    }
    
    cout << "Reversed string: " << reversed << endl;
    
    return 0;
}
