#include <iostream>

using namespace std;

int main() {
    int a, b;
    cout<<"Enter nummber a:"<<endl;
    cin >> a ;
    cout<<"Enter number b: "<<endl;
    cin>> b;


    string num_words[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    for (int n = a; n <= b; n++) {
        if(n >= 1 && n <= 9){
            cout << num_words[n - 1] << endl;
        }else{
            if(n % 2 == 0)
                cout << "even" << endl;
            else
                cout << "odd" << endl;
        }
    }


    return 0;
    
}