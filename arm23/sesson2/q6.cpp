#inclue <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    for (int i = 1; i <= n; ++1){
        if (i % 2 == 0)
          cout << i << "is even\n";
      else 
          cout << i << "is odd\n"; 
    }
    return 0; 
}