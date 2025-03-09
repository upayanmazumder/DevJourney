#include <stdio.h>

int main()
{
    int N, S;
    scanf("%d", &N);
    int matrix[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    scanf("%d", &S);
    int count = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int a = 0; a < N - i + 1; a++)
        {
            for (int b = 0; b < N - i + 1; b++)
            {
                int sum = 0;
                for (int j = 0; j < i; j++)
                {
                    for (int k = 0; k < i; k++)
                    {
                        if (j + a <= N - 1 && k + b <= N - 1)
                        {
                            sum += matrix[j + a][k + b];
                        }
                    }
                }
                if (sum == S)
                {
                    count++;
                }
            }
        }
    }
    printf("%d", count);
}