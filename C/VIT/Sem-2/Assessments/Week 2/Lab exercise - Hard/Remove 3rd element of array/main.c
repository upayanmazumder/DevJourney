#include <stdio.h>

int main()
{
    int i, j, n, a[15], b[15];
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    i = 0;
    for (j = 0; j < n - 1; j++)
    {
        if (j == 2)
        {
            i++;
        }
        b[j] = a[i];
        i++;
    }

    for (i = 0; i < n - 1; i++)
    {
        printf("%d ", b[i]);
    }
}