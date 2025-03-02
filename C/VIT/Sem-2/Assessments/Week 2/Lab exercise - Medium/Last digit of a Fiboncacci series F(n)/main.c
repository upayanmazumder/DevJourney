#include <stdio.h>

int main()
{
    int n, res;
    int fiboLastDigit(int);
    scanf("%d", &n);
    res = fiboLastDigit(n);
    printf("%d", res);
}

int fiboLastDigit(int x)
{
    int i = 0, j = -1, k = 1, sum = 0;
    for (i = 0; i <= x; i++)
    {
        sum = j + k;
        j = k;
        k = sum;
    }

    return sum % 10;
}