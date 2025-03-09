#include <stdio.h>

int main()
{
    int x;
    void iseven(int);
    scanf("%d", &x);
    iseven(x);
}

void iseven(int a)
{
    void ismultiple(int);
    if (a % 2 == 0)
    {
        printf("Even");
        ismultiple(a);
    }
    else
    {
        printf("Not even");
    }
}

void ismultiple(int a)
{
    if (a % 10 == 0)
        printf("\nMultiple of 10");
    else
        printf("\nNot a multiple of 10");
}