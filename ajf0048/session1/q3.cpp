#include <iostream>
using namespace std;

int main(){
    char a;
    cout << "Enter a character: " << endl;
    cin >> a;
    cout << "You entered: " << a << endl;
    cout << "ASCII value: " << int(a) << endl;
    cout << "Character after increment: " << char(a + 1) << endl;
    cout << "Character after decrement: " << char(a - 1) << endl;
    return 0;
}