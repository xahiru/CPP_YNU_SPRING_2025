#include <iostream>

using namespace std;

int main(){

cout <<"*****Shimanto's Calculator*********"<<endl;

int num1;                      //Take user input for two numbers and operator
char op;                       
int num2;
cout<<"enter num1: "<<endl;
cin>>num1;                     
cout<<"enter num2:"<<endl;
cin>>num2;
cout<<"enter op(+ - / *): "<<endl;
cin>>op;

if(op == '+'){
    cout<<"result: "<<num1+num2<<endl; //using if and else if to set up condition for the calculator
}
else if(op == '-'){
    cout<<"result: "<<num1-num2<<endl;
}
else if(op == '*'){
    cout<<"result: "<<num1*num2<<endl;
}
else if(op == '/'){
    cout<<"result: "<<num1/num2<<endl;
}else{
    cout<<"You entered invalid input!"<<endl;
}

cout<<"******************"<<endl;

return 0;

}
