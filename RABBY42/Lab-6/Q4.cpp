#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string s = "Yunnan";
    int count = 0;
    string word;
    istringstream iss(s);
    while (iss >> word) count++;
    cout << count << endl;
    return 0;
}