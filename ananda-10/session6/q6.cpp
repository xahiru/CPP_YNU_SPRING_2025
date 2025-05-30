#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;

    cout << "Enter a sentence: ";
    getline(cin, s);

    cout << "You entered: " << s << endl;

    return 0;
}

