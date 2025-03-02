#include <stdio.h>

int main()
{
    int N, a[10][10], b[10][10], i, j;
    bool transpose = true;

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
            b[i][j] = a[j][i];
        }
    }

    printf("Original matrix:\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    printf("Transpose matrix:\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (a[i][j] != b[i][j])
            {
                transpose = false;
                break;
            }
        }
    }

    printf("Matrix is %sSymmetric!", transpose ? "" : "not ");
}