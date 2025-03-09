#include <stdio.h>

int isAutomorphic(int x)
{
    int sqr = x * x;
    if (x <= 10)
    {
        return sqr % 10;
    }
    else
    {
        return sqr % 100;
    }
}

int main()
{
    int x, result;
    scanf("%d", &x);
    result = isAutomorphic(x);
    if (result == x)
    {
        printf("The number is an automorphic.");
    }
    else
    {
        printf("The number is NOT an automorphic.");
    }
}