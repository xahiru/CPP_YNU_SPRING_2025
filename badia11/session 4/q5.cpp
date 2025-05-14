#include <iostream>
#include <string>
using namespace std;

int main() {
    int *num = new int(10);
    char *ch = new char('A');
    string *str = new string("Hello");
    
    cout << *num << " " << *ch << " " << *str;
    
    delete num;
    delete ch;
    delete str;
    return 0;
}
