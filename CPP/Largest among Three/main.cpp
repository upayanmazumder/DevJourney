#include<iostream>
using namespace std;

int main() {
    int a,b,c,larger,largest;
    cout<<"Enter three numbers: ";
    cin>>a>>b>>c;
    if (a>b)
    {
        larger=a;
    }
    else
    {
        larger=b;
    }
    if (c>larger)
    {
        largest=c;
    }
    else
    {
        largest=larger;
    }
    cout<<"The largest number is "<<largest;
}