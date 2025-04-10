#include <iostream>

using namespace std;

int main(){

    int a,b,c,d;
    cout<<"Enter a:"<<endl;
    cin>>a;
    cout<<"Enter b:"<<endl;
    cin>>b;
    cout<<"Enter c:"<<endl;
    cin>>c;
    cout<<"Enter d:"<<endl;
    cin>>d;

    cout<<"The maximum number is : ";

    if(a>b && a>c && a>d){
        cout << a <<endl;
    }else if(b>a && b>c && b>d){
        cout << b << endl;
    }else if(c>a && c>b && c>d){
        cout << c <<endl;
    }else{
        cout << d <<endl;
    }


    return 0;

}
