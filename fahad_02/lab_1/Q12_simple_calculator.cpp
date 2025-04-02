#include<iostream>
using namespace std;

int main(){
    int num1, num2;
    cout<<"Enter the Number: a = ";
    cin>>num1;
    cout<<", b = ";
    cin>>num2;

    cout
    <<"Enter a for addition,"<<endl
    <<"s for substraction,"<<endl
    <<"m for multiplication,"<<endl
    <<"d for division."<<endl;
    char ch;
    cin>>ch;
    if(ch == 'a' || ch == 'A'){
        cout<<num1+num2<<endl;
    }
    else if(ch == 's' || ch == 'S'){
        cout<<num1-num2<<endl;
    }
    else if(ch == 'm' || ch == 'M'){
        cout<<num1*num2<<endl;
    }
    else if(ch == 'd' || ch == 'D'){
        cout<<num1/num2<<endl;
    }
    else{
        cout<<"Wrong enter"<<endl;
    }
    return 0;
}




