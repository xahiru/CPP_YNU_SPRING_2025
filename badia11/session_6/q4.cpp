#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string s = "World is hello";
    istringstream iss(s);
    string word;
    int count = 0;

    while (iss >> word) count++;
    cout << count << endl;

    return 0;
}
