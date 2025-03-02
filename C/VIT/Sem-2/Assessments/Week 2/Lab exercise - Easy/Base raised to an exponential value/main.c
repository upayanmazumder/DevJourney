#include <stdio.h>

int main()
{
    int b, e, res;
    int calculatePower(int, int);
    scanf("%d %d", &b, &e);
    res = calculatePower(b, e);
    printf("%d", res);
}

int calculatePower(int b, int e)
{
    int p = 1, i;
    for (i = 0; i < e; i++)
    {
        p *= b;
    }
    return p;
}