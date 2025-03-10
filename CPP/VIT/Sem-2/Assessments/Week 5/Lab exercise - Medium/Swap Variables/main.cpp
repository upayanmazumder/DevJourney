#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

int main()
{
    int x, y;
    cin >> x >> y;
    swap(x, y);
    cout << x << " " << y;
    return 0;
}