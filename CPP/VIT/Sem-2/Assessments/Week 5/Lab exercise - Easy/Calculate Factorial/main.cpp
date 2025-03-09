#include <iostream>

using namespace std;

void calculateFactorialAndSum(int n, long long &factorial, int &sumOfDigits)
{
    factorial = 1;
    for (int i = 2; i <= n; i++)
    {
        factorial *= i;
    }

    sumOfDigits = 0;
    long long temp = factorial;
    while (temp > 0)
    {
        sumOfDigits += temp % 10;
        temp /= 10;
    }
}

int main()
{
    int n;
    cin >> n;

    long long factorial;
    int sumOfDigits;

    calculateFactorialAndSum(n, factorial, sumOfDigits);

    cout << "Factorial: " << factorial << endl;
    cout << "Sum of digits of the factorial: " << sumOfDigits << endl;

    return 0;
}