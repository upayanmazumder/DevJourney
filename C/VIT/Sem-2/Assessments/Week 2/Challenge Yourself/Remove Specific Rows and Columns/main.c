#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int R, C, removeRow, removeCol;
        scanf("%d %d", &R, &C);
        int matrix[R][C];
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                scanf("%d", &matrix[i][j]);
            }
        }
        scanf("%d %d", &removeRow, &removeCol);
        for (int i = 0; i < R; i++)
        {
            if (i == removeRow)
                continue;
            for (int j = 0; j < C; j++)
            {
                if (j == removeCol)
                    continue;
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
    }
}