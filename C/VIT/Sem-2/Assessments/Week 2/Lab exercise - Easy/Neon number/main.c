#include <stdio.h>

int main()
{
    int N, x, r, sum;
    scanf("%d", &N);
    x = N * N;

    while (x > 0)
    {
        r = x % 10;
        sum += r;
        x /= 10;
    }

    printf("%d is ", N);
    if (N != sum)
        printf("not ");
    printf("a neon number");
}