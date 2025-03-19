#include<iostream>

using namespace std;

void printDetails(int id, string name = "NA", string address = "NA")
{
    cout << "Id: " << id << '\n';
    cout << "Name: " << name << '\n';
    cout << "Address: "<< address << '\n';
}

int main()
{
    printDetails(101, "Doe", "John");
    cout << '\n';
    printDetails(201, "Jane");
    cout << '\n';
    printDetails(301);
    return 0;
}