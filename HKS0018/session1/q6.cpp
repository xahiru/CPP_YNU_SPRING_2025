#include <iostream>
#include <cmath>

using namespace std;

int main(){

    double principal, rate, time, amount, compoundInterest;

    cout<<"Enter the principal: "<<endl;
    cin>>principal;
    cout<<"Enter the rate : "<<endl;
    cin>>rate;
    cout<<"Enter the time: "<<endl;
    cin>>time;


    amount = principal * pow((1+rate/100),time);

    compoundInterest = amount - principal;


    cout<<"Compund Interest: " << compoundInterest<<endl;




    return 0;
}

