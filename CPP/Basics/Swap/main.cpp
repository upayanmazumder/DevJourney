#include <iostream>
using namespace std;

int main() {
    int a,b,temp;
    cout<<("Enter the first number  (a): ");
    cin>>a;
    cout<<("Enter the second number (b): ");
    cin>>b;
    temp=a;
    a=b;
    b=temp;
    cout<<"After swapping, a is "<<a<<" and b is "<<b<<endl;
}