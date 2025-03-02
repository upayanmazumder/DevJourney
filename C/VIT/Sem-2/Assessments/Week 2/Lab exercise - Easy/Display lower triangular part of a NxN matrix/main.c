#include <stdio.h>

int main()
{
    int N, i, j, a[8][8];
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (j <= i)
            {
                printf("%d ", a[i][j]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}