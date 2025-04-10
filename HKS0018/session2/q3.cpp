#include<iostream>

using namespace std;

int main(){

    double l;
    double w;
    double a;
    double p;

    cout<<"Enter the length: "<<endl;
    cin>>l;

    cout<<"Enter the width : "<<endl;
    cin>>w;


    a = l * w;
    p = 2*l + 2*w;

    cout<< "The are of rectangle is: "<<a<<endl;
    cout<< "The perimeter of he rectangle is: "<<p<<endl;

    return 0;
}