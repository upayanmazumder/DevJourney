#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int N;
        scanf("%d", &N);
        int matrix[N][N];
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                scanf("%d", &matrix[i][j]);
            }
        }
        int mid = N / 2;
        int a, b, c, d;
        a = 0;
        b = 0;
        c = 0;
        d = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i < mid && j < mid)
                {
                    a += matrix[i][j];
                }
                else if (i < mid && j >= mid)
                {
                    b += matrix[i][j];
                }
                else if (i >= mid && j < mid)
                {
                    c += matrix[i][j];
                }
                else
                {
                    d += matrix[i][j];
                }
            }
        }
        printf("%d %d %d %d", a, b, c, d);
    }
}