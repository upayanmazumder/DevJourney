#include <stdio.h>

int main()
{
    int m, n, a[15][15], i, j;
    scanf("%d %d", &m, &n);
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 0; i < m; i++)
    {
        if (i % 2 == 0)
        { // Row number is odd
            for (j = 0; j < n; j++)
            {
                printf("%d ", a[i][j]);
            }
        }
        else
        { // Row number is even
            for (j = n - 1; j > -1; j--)
            {
                printf("%d ", a[i][j]);
            }
        }
    }
}