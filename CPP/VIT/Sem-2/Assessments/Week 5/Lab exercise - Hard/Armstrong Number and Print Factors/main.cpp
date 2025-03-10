#include <iostream>
#include <cmath>
using namespace std;

inline bool isArmstrong(int number)
{
    int sum = 0, temp = number, d = log10(number) + 1;
    while (temp)
    {
        sum += pow(temp % 10, d);
        temp /= 10;
    }
    return sum == number;
}

inline void printFactors(int number)
{
    for (int i = 1; i <= number; i++)
        if (number % i == 0)
            cout << i << " ";
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    if (isArmstrong(n))
    {
        cout << n << " is an Armstrong number." << endl;
        printFactors(n);
    }
    else
    {
        cout << n << " is not an Armstrong number." << endl;
    }
    return 0;
}