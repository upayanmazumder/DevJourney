#include <iostream>
using namespace std;

inline int sumOfSquaresEven(int n)
{
    return (4 * n * (n + 1) * (2 * n + 1)) / 6;
}

inline int sumOfSquaresOdd(int n)
{
    return (n * (2 * n + 1) * (2 * n - 1)) / 3;
}

int main()
{
    int n;
    cin >> n;
    cout << sumOfSquaresEven(n) << endl;
    cout << sumOfSquaresOdd(n) << endl;
    return 0;
}