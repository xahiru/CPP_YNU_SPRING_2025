#include <iostream>
using namespace std;

void printAlphabets(char c1, char c2) {
    for (char c = c1; c <= c2; c++) {
        cout << c << " ";
    }
    cout << endl;
}

int main() {
    printAlphabets('a', 'z'); // Output: "a b c d e f g h i j k l m n o p q r s t u v w x y z "
    return 0;
}
