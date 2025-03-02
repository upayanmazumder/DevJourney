#include <stdio.h>

int main()
{
    int i, j, k, a[8][8], r, c;
    bool zeroC, zeroE;
    scanf("%d %d", &r, &c);
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 0; i < r; i++)
    {
        zeroE = false;
        for (j = 0; j < c; j++)
        {
            if (a[i][j] == 0)
            {
                zeroE = true;
                break;
            }
        }
        for (j = 0; j < c; j++)
        {
            if (zeroE)
            {
                printf("0 ");
            }
            else
            {
                zeroC = false;
                for (k = 0; k < r; k++)
                {
                    if (a[k][j] == 0)
                    {
                        zeroC = true;
                        break;
                    }
                }
                if (zeroC)
                {
                    printf("0 ");
                }
                else
                {
                    printf("%d ", a[i][j]);
                }
            }
        }
        printf("\n");
    }
}