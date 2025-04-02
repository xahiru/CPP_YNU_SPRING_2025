#include<iostream>

using namespace std;

int main(){

    int a, b, c;
    cout<<"Enter number A: " <<endl;
    cin>>a;

    cout<<"Enter number B: " <<endl;
    cin>>b;

    cout<<"Enter number C: " <<endl;
    cin>>c;

    if(a>b && a>c){
        cout<<"Number A is the biggest."<<endl;
    }
    else if(b>c && b>a){
        cout<<"Number B is the biggest." <<endl;
    }else{
        cout<<"Number C is the biggest."<<endl;
    }



    return 0;
}