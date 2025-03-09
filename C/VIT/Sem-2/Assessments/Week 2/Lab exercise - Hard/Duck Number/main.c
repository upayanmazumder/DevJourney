#include <stdio.h>

bool isDuckNumber(int n)
{
    int x = 0;
    int count = 0;
    while (n != 0)
    {
        int digit = n % 10;
        n /= 10;
        if (digit == 0)
        {
            x = 1;
            return true;
        }
        else
        {
            x = 0;
        }
    }

    if (x == 0)
        return false;
}

int main()
{
    int n, result;
    scanf("%d", &n);
    result = isDuckNumber(n);
    if (result)
        printf("%d is a duck number.", n);
    else
        printf("%d is not a duck number.", n);
}