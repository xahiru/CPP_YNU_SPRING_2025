#include<iostream>
#include <cmath>  

using namespace std;

int main(){
    float p, r, t, interest, a;
    cout<<"Principle = ";
    cin>>p;
    cout<<"Rate = ";
    cin>>r;
    cout<<"Time in years = ";
    cin>>t;

    r = r / 100;
    a = p * pow(1 + r, t);  
    interest = a - p;
    
    cout<<"Compound Interest = "<< interest <<endl;
    return 0;
}   