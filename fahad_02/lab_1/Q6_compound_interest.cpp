#include<iostream>
#include <cmath>  

using namespace std;

int main(){
    float p, r, t, interest, A;
    cout<<"Principle = ";
    cin>>p;
    cout<<"Rate = ";
    cin>>r;
    cout<<"Time in years = ";
    cin>>t;

    r = r / 100;
    A = p * pow(1 + r, t);  
    interest = A - p;
    
    cout<<"Compound Interest = "<< interest <<endl;
    return 0;
}   