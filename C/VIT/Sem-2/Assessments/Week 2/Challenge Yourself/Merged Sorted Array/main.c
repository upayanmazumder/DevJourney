#include <stdio.h>

int main()
{
    int a[1000], b[1000], M, N, temp, i, j;
    scanf("%d\n", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d\n", &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &b[i]);
    }

    for (i = 0; i < 100; i++)
    {
        a[N + i] = b[i];
    }

    for (i = 0; i < (M + N); i++)
    {
        for (j = i + 1; j < M + N; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        printf("%d ", a[i]);
    }
}