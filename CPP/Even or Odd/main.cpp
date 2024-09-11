#include <iostream>
using namespace std;

int main() {
    int n,r;
    cout<<"Enter a number: ";
    cin>>n;
    r=n%2;
    if (r==0)
    {
        cout<<"The number is even";
    }
    else
    {
        cout<<"The number is odd";
    }
}