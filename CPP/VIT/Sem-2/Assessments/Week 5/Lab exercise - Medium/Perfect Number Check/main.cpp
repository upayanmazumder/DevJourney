#include <iostream>
using namespace std;

bool isPerfect(int n, int s = 1)
{
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            s += i + (i != n / i ? n / i : 0);
    return s == n;
}

int main()
{
    int n;
    cin >> n;
    cout << n << (isPerfect(n) ? " is a perfect number" : " is not a perfect number");
    return 0;
}