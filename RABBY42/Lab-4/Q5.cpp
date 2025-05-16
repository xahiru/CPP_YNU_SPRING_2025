#include <iostream>
#include <string>
using namespace std;

int main() {
    int *pInt = new int(5);
    char *pChar = new char('A');
    string *pStr = new string("Hello");
    
    // Cleanup
    delete pInt;
    delete pChar;
    delete pStr;
    return 0;
}