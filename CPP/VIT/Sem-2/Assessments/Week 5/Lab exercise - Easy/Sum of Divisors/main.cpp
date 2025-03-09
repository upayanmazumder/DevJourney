#include <iostream>
using namespace std;

void sumOfDivisors(int n, int &sum)
{
    sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
        }
    }
}

int main()
{
    int n, sum;
    cin >> n;

    sumOfDivisors(n, sum);

    cout << sum << endl;

    return 0;
}